#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost; // null_mapped_type instead of null_type in older versions


struct fenwick_tree {
  int n;
  vector<ll> a, f;
  fenwick_tree(int n = 0) : n(n), a(n), f(n + 1) {}
  fenwick_tree(vector<ll> & a) : fenwick_tree(a.size()) {
    for (int i = 0; i < n; i++)
      setValue(i, a[i]);
  }
  void changeValue(int i, ll d) {
    for (a[i++] += d; i <= n; i += i & -i)
      f[i] += d;
  }
  void setValue(int i, ll v) {
    changeValue(i, v - a[i]);
  }
  ll getSum(int i) {
    ll s = 0;
    for (i++; i; i -= i & -i)
      s += f[i];
    return s;
  }
  // get the sum of the range [l, r[
  ll getSum(int l, int r) {
    return getSum(r - 1) - getSum(l - 1);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<pii> Q;
  vector<int> A;
  for(int i=0; i<N; i++){
    int t, d;
    cin >> t >> d;
    Q.push_back({t,d});
    A.push_back(abs(d));
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  unordered_map<int,int> M;
  for(int i=0; i<sz(A); i++){
    M[A[i]] = i;
  }
  fenwick_tree S(sz(A));
  fenwick_tree fenCount(sz(A));
  ost T;
  ll sum = 0;
  int cntL = 0;
  set<int> Li, Fi;
  for(auto [t,d] : Q){
    if(t == 1){
      if(d < 0)
        cntL--, Li.erase(-d), fenCount.setValue(M[-d], 0);
      else
        cntL++, Li.insert(d), fenCount.setValue(M[d], 1);
    }
    else{
      if(d < 0)
        Fi.erase(-d);
      else
        Fi.insert(d);
    }
    sum += d;
    if(d < 0){
      d = abs(d);
      T.erase(d);
      S.changeValue(M[d], -d);
    }
    else{
      T.insert(d);
      S.changeValue(M[d], d);
    }
    ll res = sum;
    //cout << "st: " << res << endl;
    if(cntL > 0){
      int from = M[*(T.find_by_order(sz(T)-cntL))];
      //cout << "stInd: " << from << endl;
      res += S.getSum(from, sz(A));
      //cout << "nxt: " << res << endl;
      int gotCntL = fenCount.getSum(from, sz(A));
      //cout << "got: " << gotCntL << endl;
      if(gotCntL == cntL){
        res -= *(Li.begin());
        if(sz(Fi) > 0)
          res += *(--(Fi.end()));
      }
    }
    cout << res << "\n";
    //cout << endl;
  }
}