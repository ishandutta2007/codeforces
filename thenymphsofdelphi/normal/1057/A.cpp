#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority_queue
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

vi adj[N];
int n;
vi path;
bool ck[N];

void dfs(int u){
    path.pb(u);
    if (u == n){
        for (int i = 0; i < path.size(); i++){
            cout << path[i] << ' ';
        }
        exit(0);
    }
    ck[u] = 1;
    for (int i = 0; i < adj[u].size(); i++){
        if (!ck[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
    path.pob();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 2, n + 1){
        int x;
        cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    dfs(1);
}

/*
----------------------------------+
INPUT:                            |
==============================    |
8
1 1 2 2 3 2 5
==============================    |
6
1 2 3 4 5
==============================    |
7
1 1 2 3 4 3
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
1 2 5 8 
==============================    |
1 2 3 4 5 6 
==============================    |
1 3 7 
==============================    |
----------------------------------+
*/