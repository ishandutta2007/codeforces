#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;

int T, N;
int P[n], C[n];
bool vis[n];
int erg;

void dfs(int st){
  int cur = st;
  vis[cur] = true;
  vector<int> x;
  do{
    x.push_back(cur);
    cur = P[cur];
    vis[cur] = true;
  }while(cur != st);
  /*
  for(int i : x)
    cerr << i << " ";
  cerr << endl;
  */
  int c = sz(x);
  for(int i=1; i<=c; i++){
    if(c%i == 0){
      for(int j=0; j<i; j++){
        int col = C[x[j]];
        for(int k=(j+i)%c; k!=j; k=(k+i)%c){
          if(col != C[x[k]])
            col = -1;
        }
        if(col != -1){
          erg = min(erg, i);
          return;
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    erg = N;
    for(int i=1; i<=N; i++){
      cin >> P[i];
    }
    for(int i=1; i<=N; i++){
      cin >> C[i];
    }
    fill_n(vis, N+1, false);
    for(int i=1; i<=N; i++){
      if(!vis[i]){
        dfs(i);
      }
    }
    cout << erg << "\n";
  }

  return 0;
}