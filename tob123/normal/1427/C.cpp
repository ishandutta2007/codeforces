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

const int n = 1e5+10;
const int r = 1000;
int N, R;
int X[n], Y[n], TT[n];
int val[n];
int dp[r][r];
vector<int> T[2000000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> N;
  for(int i=1; i<=N; i++){
    int t;
    cin >> t >> X[i] >> Y[i];
    TT[i] = t;
    X[i]--; Y[i]--;
    T[t].push_back(i);
    val[i] = 1;
  }
  T[0].push_back(0);
  X[0] = Y[0] = 0;
  val[0] = 1;
  int curI = N+1;
  for(int t=1e6; t>=0; t--){
    if(sz(T[t]))
      curI--;
    for(int ind = sz(T[t]) ? curI+1 : curI; ind <= N && TT[ind] <= t+R; ind++){
      int i=TT[ind]-t;
      if(Y[ind] >= i){
        dp[X[ind]][Y[ind]-i] = max(dp[X[ind]][Y[ind]-i], val[ind]);
      }
      if(Y[ind]+i < R){
        dp[X[ind]][Y[ind]+i] = max(dp[X[ind]][Y[ind]+i], val[ind]);
      }
    }
    for(int ind : T[t]){
      val[ind] = max(val[ind], dp[X[ind]][Y[ind]]+1);
      //cout << ind << ": " << val[ind] << endl;
      dp[X[ind]][Y[ind]] = max(dp[X[ind]][Y[ind]], val[ind]);
    }
    for(int ind = curI-1; ind >= 0 && TT[ind] >= t-R; ind--){
      int i=t-TT[ind];
      if(X[ind] >= i)
        val[ind] = max(val[ind], dp[X[ind]-i][Y[ind]]+1);
      if(X[ind]+i < R)
        val[ind] = max(val[ind], dp[X[ind]+i][Y[ind]]+1);
    }
  }
  cout << val[0]-1 << "\n";
}