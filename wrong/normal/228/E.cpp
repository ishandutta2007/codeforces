#include<iostream>
#include<cstring>

using namespace std;

int n, m, adj[100][100], col[100];

bool dfs(int u, int c)
{
  if(col[u] >= 0) {
    return col[u] == c;
  }

  col[u] = c;
  for(int i=0; i<n; ++i) {
    if(~adj[u][i]) {
      if(!dfs(i, c^adj[u][i])) {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  while(cin >> n >> m) {
    memset(adj, ~0, sizeof(adj));

    for(int i=0; i<m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      adj[a][b] = adj[b][a] = 1-c;
    }

    bool ok = true;
    for(int i=0; i<n; ++i) {
      col[i] = -1;
    }
    for(int i=0; ok && i<n; ++i) {
      if(col[i] < 0) {
        ok &= dfs(i, 0);
      }
    }

    if(!ok) {
      cout << "Impossible" << endl;
    } else {
      int x = 0;
      for(int i=0; i<n; ++i) {
        x += col[i];
      }

      cout << x << endl;
      for(int i=0; i<n; ++i) {
        if(col[i]) {
          cout << i+1;
          x--;
          if(x) {
            cout << " ";
          } else {
            cout << endl;
          }
        }
      }
    }
  }
  
  return 0;
}