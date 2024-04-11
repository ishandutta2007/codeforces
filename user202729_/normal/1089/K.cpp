/*input
19
? 3
+ 2 2
? 3
? 4
+ 5 2
? 5
? 6
+ 1 2
? 2
? 3
? 4
? 5
? 6
? 7
? 9
- 8
? 2
? 3
? 6
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 1e6+5;

struct BITx {
    int tree[N];
    BITx(){
      memset(tree,0,sizeof(tree));
    }
    void update(int i, int val) {
        for (; i < N; i += i & -i) tree[i] += val;
    }
    int get(int i) {
        int ret = 0;
        for (; i; i -= i & -i) ret += tree[i];
        return ret;
    }
} bit;

const int INF = 1e9;
class ITrangeMaxMin {
private:
#define mid ((l+r)/2)
  int n, f[4 * N], lazy[4 * N];
  void dolazy(int k, int l, int r) {
    if (lazy[k] == 0) return;
    f[k] += lazy[k];
    if (l != r) {
      lazy[k * 2] += lazy[k];
      lazy[k * 2 + 1] += lazy[k];
    }
    lazy[k] = 0;
  }
  void init(int k, int l, int r) {
    f[k] = lazy[k] = 0; if (l == r) return;
    init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
  }
  void update(int k, int l, int r, int L, int R, int val) {
    dolazy(k, l, r);
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      lazy[k] += val; dolazy(k, l, r);
      return;
    }
    update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
    f[k] = max(f[k * 2], f[k * 2 + 1]);
  }
  int get(int k, int l, int r, int L, int R) {
    dolazy(k, l, r);
    if (r < L || R < l) return -INF;
    if (L <= l && r <= R) return f[k];
    return max(get(k * 2, l, mid, L, R), get(k * 2 + 1, mid + 1, r, L, R)); // flip;
  }
public:
  void init(int _n) {n = _n; init(1, 0, n + 1);}
  int get(int l, int r) {return get(1, 0, n + 1, l, r);};
  void update(int l, int r, int val) {update(1, 0, n + 1, l, r, val);};
#undef mid
} IT;

struct Event{
  char c; int x,y;
};

int n;
vector<Event> e;

int query(int t){
  // print(bit.get(t),IT.get(0,t));
  return bit.get(t) + IT.get(0,t);
}

void modify(int t, int d, int add){
  bit.update(t,(d)*add);
  IT.update(t+1,N,(-d)*add);
  IT.update(t,t,t*add);
  // print("u",t+1,(-d)*add);
  // print("u",t,t*add);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    IT.init(N);
    
    cin >> n;
    loop(i,1,n){
      char c; 
      cin >> c;
      if (c=='?'){
        int t;
        cin >> t;
        e.push_back({'?',t});
        // print("?",t,query(t));
        cout << max(0LL,query(t)-t) << endl;
      }
      else if (c=='+'){
        int t,d;
        cin >> t >> d;
        e.push_back({'+',t,d});
        modify(t,d,1);
      }
      else{
        int p;
        cin >> p;
        e.push_back({'-',p});
        modify(e[p-1].x,e[p-1].y,-1);
      }
    }
}