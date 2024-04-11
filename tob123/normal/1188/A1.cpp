#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 2e5+10;

int N;
vector<int> G[n];

int main(){
  cin >> N;
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i=0; i<N; i++){
    if(sz(G[i]) == 2){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}