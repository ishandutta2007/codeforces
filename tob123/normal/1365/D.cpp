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

const int n = 110;

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};
int T, N, M;

bool vis[n][n], B[n][n];

void dfs(int y, int x){
  vis[y][x] = true;
  for(int i=0; i<4; i++){
    if(!B[y+Y[i]][x+X[i]] && !vis[y+Y[i]][x+X[i]])
      dfs(y+Y[i], x+X[i]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<pii> A;
    for(int i=0; i<=N+1; i++){
      for(int j=0; j<=M+1; j++){
        B[i][j] = true;
        vis[i][j] = false;
      }
    }
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        B[i][j] = false;
      }
    }
    bool res = true;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        char x;
        cin >> x;
        if(x == 'G'){
          A.push_back({i,j});
        }
        else if(x == 'B'){
          if(i+j == N+M)
            res = false;
          for(int k=0; k<4; k++){
            B[i+Y[k]][j+X[k]] = true;
          }
        }
        else if(x == '#')
          B[i][j] = true;
      }
    }
    /*
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        cout << B[i][j];
      }
      cout << endl;
    }
    */
    if(!B[N][M])
      dfs(N, M);
    for(auto p : A){
      res &= vis[p.first][p.second];
    }
    cout << (res ? "Yes\n" : "No\n");
  }
}