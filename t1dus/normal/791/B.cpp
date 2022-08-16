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
vi adj[150001];
bool vis[150001];
vi comp;

void dfs(int s){
    comp.pb(s);
    vis[s] = true;
    for (int i = 0; i < adj[s].size(); i++){
        int next = adj[s][i];
        if (!vis[next]) dfs(next);
    }
}

int main() {
	
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m;i ++){
	    int x,y;
	    cin >> x >> y;
	    adj[x].pb(y);
	    adj[y].pb(x);
	}
    for (int i = 0; i <= 150000; i++) vis[i] = false;
    
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            comp.clear();
            dfs(i);
            int cps = comp.size();
            for (int i = 0; i < cps; i++){
                if (adj[comp[i]].size() != cps-1){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}