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

const int n = 1e7+10;

int T, N, K;

//bool np[n];
//int val[n];
int lnk[n];
int lst[n];

int reduce(int x){
  for(int i=2; i*i<=x; i++){
    int sq = i*i;
    while(x%sq == 0)
      x /= sq;
  }
  return x;
}

void init(vector<int>& A){
  for(int x : A)
    lst[x] = -1;
  for(int i=0; i<N; i++){
    lnk[i] = lst[A[i]];
    lst[A[i]] = i;
  }
}

int solve(vector<int>& A){
  int b = 0;
  int res = 0;
  for(int i=0; i<N; i++){
    if(lnk[i] >= b){
      res++;
      b = i;
    }
  }
  return res+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  /*
  for(int i=2; i*i<n; i++){
    if(!np[i]){
      for(int j=2*i; j<n; j+=i)
        np[j] = true;
      int sq = i*i;
      for(int j=2*sq; j<n; j+=sq){
        while(val[j]%sq == 0)
          val[j] /= sq;
      }
    }
  }
  */
  for(int i=0; i<n; i++)
    lst[i] = -1;

  cin >> T;
  while(T--){
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      A[i] = reduce(A[i]);
    }
    init(A);
    cout << solve(A) << "\n";
  }
}