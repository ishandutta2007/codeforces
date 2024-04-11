#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
#define data ll
#define operation ll

const ll INF = 3e12+10;
set<int> B;

struct segment_tree {
  /*
  struct data{
    int val;
  };
  struct operation{
    int val;
  };
  */
  static data combine(data dl, data dr){
    return min(dl, dr);
  }
  static data calculate(operation o, data d){
    return d+o;
  }
  static operation merge(operation ot, operation ob){
    return ot+ob;
  }
  int n, h;
  vector<data> t;
  vector<operation> o;
  segment_tree(int n = 0) : n(n), h(32 - __builtin_clz(n)), t(2 * n), o(n) {}
  segment_tree(vector<data> & a) : segment_tree(a.size()) {
    for (int i = 0; i < n; i++)
      t[i + n] = a[i];
    for (int x = n - 1; x > 0; x--)
      t[x] = combine(t[x << 1], t[x << 1 | 1]);
  }
  void apply(int x, operation op) {
    t[x] = calculate(op, t[x]);
    if (x < n)
      o[x] = merge(op, o[x]);
  }
  void push(int x) {
    for (int s = h; s > 0; s--) {
      int c = x >> s;
      apply(c << 1, o[c]);
      apply(c << 1 | 1, o[c]);
      o[c] = 0; //neutral op
    }
  }
  void push2(int x) {
    apply(x << 1, o[x]);
    apply(x << 1 | 1, o[x]);
  }
  void build(int x) {
    while (x >>= 1)
      t[x] = calculate(o[x], combine(t[x << 1], t[x << 1 | 1]));
  }
  // set the data at the position i
  void setValue(int i, data d) {
    i += n;
    push(i);
    t[i] = d;
    build(i);
  }
  // query the data on the range [l, r[
  data query(int l, int r) {
    l += n; r += n;
    push(l); push(r - 1);
    data dl=INF, dr=INF; //neutra data
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        dl = combine(dl, t[l++]);
      if (r & 1)
        dr = combine(t[--r], dr);
    }
    return combine(dl, dr);
  }
  int searchM(int l){
    //cerr << l << ": ";
    int a=l+1, r=n;
    while(a < r){
      int m = (a+r)/2;
      if(query(l, m) == 0){
        r = m;
      }
      else{
        a = m+1;
      }
    }
    a--;
    //cerr << a << endl;
    return a;
  }
  // apply an operation on the range [l, r[
  void apply(int l, int r, operation op) {
    //cerr << l << " - " << r << ": " << op << endl;
    l += n; r += n;
    push(l); push(r - 1);
    int xl = l, xr = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        apply(l++, op);
      if (r & 1)
        apply(--r, op);
    }
    build(xl); build(xr - 1);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> P(N), Q(N), toInd(N);
  for(int i=0; i<N; i++){
    cin >> P[i];
    toInd[P[i]-1] = i;
  }
  for(int i=0; i<N; i++){
    cin >> Q[i];
    Q[i]--;
  }
  segment_tree s(N);
  int curRes = N-1;
  vector<int> res;
  for(int i=0; i<N; i++){
    if(curRes >= 0)
      //cerr << "search for " << toInd[curRes] << endl;
    while(curRes >= 0 && B.lower_bound(toInd[curRes]) != B.end()){
      //cerr << "found" << endl;
      auto it = B.lower_bound(toInd[curRes]);
      s.apply(toInd[curRes], *it, 1);
      B.erase(it);
      curRes--;
      //if(curRes >= 0)
        //cerr << "search for " << toInd[curRes] << endl;
    }
    res.push_back(curRes+1);
    int nxt0 = s.searchM(Q[i]);
    s.apply(Q[i], nxt0, -1);
    //cerr << "ins " << nxt0 << endl;
    B.insert(nxt0);
  }
  for(int x : res) cout << x << " ";
  cout << endl;

  return 0;
}