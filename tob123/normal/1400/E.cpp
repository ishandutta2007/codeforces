#include <bits/stdc++.h>
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

int N;
vector<ll> A;

ll calc(int l, int r, ll lev){
  if(r < l)
    return 0;
  int m = l;
  for(int i=l+1; i<=r; i++)
    m = A[m] < A[i] ? m : i;
  return min((ll)r-l+1, A[m]-lev + calc(l, m-1, A[m]) + calc(m+1, r, A[m]));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  cout << calc(0, N-1, 0) << endl;
}