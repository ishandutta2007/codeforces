#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first;
#define S second;

int n,m;
vi adj[100001];
bool visited[100001];
vi comp;

void dfs(int s){
    visited[s] = true;
    comp.pb(s);
    for (int i = 0; i < adj[s].size(); i++){
        int next = adj[s][i];
        if (!visited[next]) dfs(next);
    }
}

int main() {
	
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
	    int x,y;
	    cin >> x >> y;
	    adj[x].pb(y);
	    adj[y].pb(x);
	}
	int ans = 0;
    for (int i = 0; i <= n; i++) visited[i] = false;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            comp.clear();
            dfs(i);
            int edg = 0;
            for (int i = 0; i < comp.size(); i++){
                edg += adj[comp[i]].size();
            }
            edg /= 2;
            if (edg == comp.size()-1) ans += 1;
        }
    }
    cout << ans;
}