#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N;
vector<pii> G[n];
int L[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back({b,i});
    G[b].push_back({a,i});
  }
  bool f = false;
  for(int i=0; i<N; i++){
    if(sz(G[i]) > 2){
      for(int j=0; j<3; j++){
        L[G[i][j].second] = j+1;
      }
      f = true;
      break;
    }
  }
  int stcnt = f ? 4 : 1;
  for(int i=0; i<N-1; i++){
    if(L[i] == 0)
      L[i] = stcnt++;
  }
  for(int i=0; i<N-1; i++){
    cout << L[i]-1 << "\n";
  }

  return 0;
}