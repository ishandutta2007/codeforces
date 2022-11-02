#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<ll,ll> pii;
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
  int T, N, M;
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<ll> A(N);
    vector<vector<ll>> G(M);
    vector<ll> sumG(M);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    vector<pair<pii, int>> GS(M);
    vector<int> GI(M);
    for(int i=0; i<M; i++){
      int k;
      cin >> k;
      G[i].resize(k);
      for(int j=0; j<k; j++){
        cin >> G[i][j];
        sumG[i] += G[i][j];
      }
      GS[i] = make_pair(make_pair(sumG[i], k), i);
    }
    auto cmp = [&](pair<pii,int> a, pair<pii,int> b){
      return a.first.first*b.first.second > a.first.second*b.first.first;
    };
    sort(GS.begin(), GS.end(), cmp);
    for(int i=0; i<M; i++){
      GI[GS[i].second] = i;
    }
    //print(GS);
    vector<vector<ll>> dp(3, vector<ll>(M+2));
    for(int dif=-1; dif<=1; dif++){
      int di = dif+1;
      dp[di][0] = 0;
      for(int i=0; i<M; i++){
        dp[di][i+1] = 0;
        if(i+dif >= 0 && i+dif < N && A[i+dif]*GS[i].first.second >= GS[i].first.first){
          dp[di][i+1] = 1;
        }
        dp[di][i+1] += dp[di][i];
      }
      dp[di][M+1] = dp[di][M];
    }
    //print(dp);

    vector<int> res;
    for(int gi=0; gi<M; gi++){
      int gsi = GI[gi]+1;
      for(auto a : G[gi]){
        auto newG = make_pair(make_pair(sumG[gi]-a, sz(G[gi])-1), -1);
        auto it = lower_bound(GS.begin(), GS.end(), newG, cmp);
        int ind = it == GS.end() ? M : it-GS.begin();
        ind++;
        //cout << ind << " " << gsi << endl;
        bool pos;
        if(ind <= gsi){
          pos = A[ind-1]*newG.first.second >= newG.first.first;
          pos &= dp[1][ind-1]-dp[1][0]==ind-1;
          pos &= dp[1][M+1]-dp[1][gsi] == M-gsi;
          pos &= dp[2][gsi-1]-dp[2][ind-1] == gsi-ind;
        }
        else{
          pos = A[ind-2]*newG.first.second >= newG.first.first;
          pos &= dp[1][gsi-1]-dp[1][0]==gsi-1;
          pos &= dp[1][M+1]-dp[1][ind-1] == M-ind+1;
          pos &= dp[0][ind-1]-dp[0][gsi] == ind-gsi-1;
        }
        res.push_back(pos);
      }
    }
    for(auto x : res){
      cout << x;
    }
    cout << "\n";
  }
}