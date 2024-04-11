#include <bits/stdc++.h>
#include <array>
#include <unordered_map>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
using ll = long long;
using ull = unsigned long long;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    const int N = 42, M = 360 * 2;
    auto block = create<bool>(N, M);
    for(int i = 0; i < n; i++){
      char ty;
      cin >> ty;
      int x, y, z;
      cin >> x >> y >> z;
      x *= 2; y *= 2; z *= 2;
      if(ty == 'C'){
        while(y != z){
          block[x][y] = 1;
          y = (y + 1) % M;
        }
        block[x][y] = 1;
      } else {
        while(x != y){
          block[x][z] = 1;
          x = (x + 1);
        }
        block[x][z] = 1;
      }
    }
    auto vis = create<int>(N, M);
    queue<pair<int, int>> q;
    for(int i = 0; i < M; i++){
      q.push({0, i});
      vis[0][i] = 1;
    }
    while(!q.empty()){
      auto [x, y] = q.front(); q.pop();
      for(int dx : {-1, 0, 1}){
        for(int dy : {-1, 0, 1}){
          int nx = x + dx, ny = (y + dy + M) % M;
          if(nx >= 0 && nx < N && !vis[nx][ny] && !block[nx][ny]){
            vis[nx][ny] = 1;
            q.push({nx, ny});
          }
        }
      }
    }
    cout << (vis[N - 1][0] ? "YES\n" : "NO\n");
  }
  return 0;
}