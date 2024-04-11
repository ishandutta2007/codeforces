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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> P(2*N+1);
    for(int i=0; i<2*N; i++)
      cin >> P[i];
    vector<int> nxt(2*N, 2*N);
    for(int i=2*N-1; i>=0; i--){
      for(int j=i+1; j<2*N; j++){
        if(P[j] > P[i]){
          nxt[i] = j;
          break;
        }
      }
    }
    vector<vector<int>> pos(2*N+1, vector<int>(N+1));
    pos[2*N][N] = true;
    for(int posI=2*N-1; posI >= 0; posI--){
      for(int s=0; s<=N; s++){
        int s2 = posI - s;
        int i1 = s+nxt[posI]-posI;
        int i2 = max(s2+nxt[posI]-posI, s);
        pos[posI][s] = (i1 <= N && pos[nxt[posI]][i1]) || (i2 <= N && pos[nxt[posI]][i2]);
      }
    }
    //cout << N << endl;
    //print(pos);
    cout << (pos[0][0] ? "YES" : "NO") << "\n";
  }
}