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

const int n = 55;

ll ch[n][n];
ll A[n][n];
ll B[n][n];

int N, Q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<=50; i++){
    ch[i][0] = ch[i][i] = 1;
  }
  for(int i=1; i<=50; i++){
    for(int j=1; j<i; j++){
      ch[i][j] = ch[i-1][j] + ch[i-1][j-1];
    }
  }
  for(int j=N-2; j>=0; j--){
    for(int i=N-2; i>=0; i--){
      int h=N-j-1, v=N-i-1;
      A[i+1][j] = ch[h+v-1][h-1] + B[i][j+1] - B[i+1][j+1];
      B[i+1][j] = A[i+1][j] + B[i+1][j+1];
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cin >> Q;
  while(Q--){
    ll x;
    cin >> x;
    int a=0, b=0;
    while(a!=N-1 || b != N-1){
      cout << a+1 << " " << b+1 << "\n";
      if(a == N-1)
        b++;
      else if(b == N-1)
        a++;
      else{
        if(x < B[a+1][b])
          b++;
        else
          a++;
      }
      x -= A[a][b];
    }
    cout << N << " " << N << endl;
  }
}