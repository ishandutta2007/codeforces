#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define log2(x) (31-__builtin_clz(x))

typedef long long ll;
typedef pair<int,int> pii;

const int n = 20;
const int m = 17000;

int N;
bool G[n][n];
vector<vector<vector<ll>>> dp;
vector<int> B[n];
ll mem = 0;

void initDp(){
  dp.resize(1<<N);
  for(int i=1; i<1<<N; i++){
    int s1 = __builtin_popcount(i)-1; //one more then necessary
    //cerr << i << " -> " << s1 << endl;
    dp[i].resize(1<<s1);
    for(int j=0; j<1<<s1; j++){
      dp[i][j].resize(N);
      mem += N*8;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      char c;
      cin >> c;
      G[i][j] = c == '1';
    }
  }
  initDp();
  for(int i=0; i<N; i++){
    dp[1<<i][0][i] = 1;
  }
  for(int i=0; i<1<<N; i++){
    B[__builtin_popcount(i)].push_back(i);
  }
  for(int i=1; i<N; i++){
    for(int p : B[i+1]){
      for(int bitS=0; bitS<1<<i; bitS++){
        int pa = p;
        while(pa){
          int cura = pa&(-pa);
          int inda = log2(cura);
          pa = pa & (~cura);
          int pb = p & (~cura);
          while(pb){
            int curb = pb&(-pb);
            int indb = log2(curb);
            pb &= ~curb;
            if(G[inda][indb] == (bitS&1)){
              dp[p][bitS][inda] += dp[p & (~cura)][bitS>>1][indb];
            }
          }
        }
      }
    }
  }
  vector<ll> res(1<<(N-1));
  int i = (1<<N)-1;
  for(int j=0; j<1<<(__builtin_popcount(i)-1); j++){
    for(int k=0; k<N; k++){
      //cerr << i << " " << j << " " << k << " / " << sz(dp[i][j]) << endl;
      res[j] += dp[i][j][k];
    }
  }
  for(int i=0; i<1<<(N-1); i++)
    cout << res[i] << " ";
  cout << endl;
  //cerr << "mem: " << mem << endl;

  return 0;
}