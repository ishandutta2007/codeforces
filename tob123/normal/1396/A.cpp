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

const int n = 2e5+10;

int N;
ll A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  if(N == 1){
    for(int i=0; i<3; i++){
      cout << 1 << " " << 1 << "\n" << -A[0] << "\n";
      A[0] = 0;
    }
    return 0;
  }
  cout << 1 << " " << N-1 << "\n";
  for(int i=0; i<N-1; i++){
    cout << (A[i]%N*(N-1)) << " ";
    A[i] += (A[i]%N*(N-1));
  }
  cout << endl;
  cout << N << " " << N << "\n";
  cout << N-A[N-1]%N << "\n";
  A[N-1] += N-A[N-1]%N;
  cout << 1 << " " << N << "\n";
  for(int i=0; i<N; i++){
    cout << -A[i] << " ";
  }
  cout << endl;
}