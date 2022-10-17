#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1'000'000'007;

struct UF {
  vi e;
  vi bad;
  UF(int n) : e(n,-1), bad(n,0) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    assert(bad[a] == 0 || bad[b] == 0);
    if(bad[a] || bad[b]) bad[a] = bad[b] = 1;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  UF uf(m+10);
  vi ans;
  rep(i,0,n) {
    int k;
    cin>>k;
    if(k == 1) {
      int x;
      cin>>x;
      x = uf.find(x);
      if(!uf.bad[x]) {
        ans.push_back(i+1);
        uf.bad[x] = 1;
      }
    }
    if(k == 2) {
      int x,y;
      cin>>x>>y;
      x = uf.find(x);
      y = uf.find(y);
      if(x != y) {
        if(uf.bad[x] == 0 || uf.bad[y] == 0) {
          uf.join(x,y);
          ans.push_back(i+1);
        }
      }
    }
  }
  ll q = 1;
  rep(i,0,sz(ans))
    q = (2 * q) % mod;
  cout << q << " " << sz(ans) << endl;
  rep(i,0,sz(ans)) cout << ans[i] << " ";
  cout << endl;
}