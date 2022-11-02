#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int T, N;
vector<int> G[n];
bool vis[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    fill_n(vis, N, false);
    vector<int> res;
    for(int i=0; i<N; i++){
      G[i].clear();
      int K;
      cin >> K;
      bool found = false;
      for(int j=0; j<K; j++){
        int x;
        cin >> x;
        x--;
        G[i].push_back(x);
        if(!found){
          if(!vis[x]){
            found = true;
            vis[x] = true;
          }
        }
      }
      if(!found){
        res.push_back(i);
      }
    }
    if(sz(res) == 0){
      cout << "OPTIMAL\n";
    }
    else{
      cout << "IMPROVE\n";
      for(int i=0; i<N; i++){
        if(!vis[i]){
          cout << res[0]+1 << " " << i+1 << "\n";
          break;;
        }
      }
    }
  }

  return 0;
}