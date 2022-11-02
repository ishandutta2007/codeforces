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
typedef long double ld;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, L;
  cin >> T;
  while(T--){
    cin >> N >> L;
    vector<ld> A(N+2);
    for(int i=1; i<=N; i++)
      cin >> A[i];
    A[N+1] = L;
    vector<ld> B(N+2);
    vector<ld> C(N+2);
    for(int i=1; i<=N+1; i++){
      B[i] = B[i-1] + ((ld)(A[i]-A[i-1]))/i;
    }
    for(int i=N; i>=0; i--){
      C[i] = C[i+1] + ((ld)(-A[i]+A[i+1]))/(N+1-i);
    }
    bool fin = false;
    for(int i=0; i<=N+1; i++){
      if(abs(B[i]-C[i]) < 1e-8){
        cout << fixed << setprecision(10) << B[i] << "\n";
        fin = true;
        break;
      }
    }
    if(fin)
      continue;
    //print(B);
    //print(C);
    int li=0, ri=N+1;
    while(li < ri-1){
      if(B[li+1] < C[ri-1])
        li++;
      else
        ri--;
    }
    //cout << li << " " << ri << endl;
    double ls = li+1;
    double rs = N+2-ri;
    if(B[li] < C[ri]){
      A[li] += (C[ri]-B[li])*ls;
    }
    else{
      A[ri] -= (-C[ri]+B[li])*rs;
    }
    //cout << A[li] << " - " << A[ri] << " " << endl;
    cout << setprecision(10) << fixed << max(B[li], C[ri]) + (A[ri]-A[li])/(ls+rs) << "\n";
    //cout << endl;
  }
}