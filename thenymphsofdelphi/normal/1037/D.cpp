#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
int hgt[N], par[N], ck[N], seq[N], pos[N];
vi a[N];
vii b;
vii::iterator itr;
queue <int> q;

void dfs(int u, int h){
    hgt[u] = h;
    ck[u] = 1;
    for (int i = 0; i < a[u].size(); i++){
        if (!ck[a[u][i]]){
            par[a[u][i]] = u;
            dfs(a[u][i], h + 1);
        }
    }
    return;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int u, v, idx = 1;
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> u >> v;
		u--;
		v--;
		a[u].pb(v);
		a[v].pb(u);
	}
	for (int i = 0; i < n; i++){
	    cin >> seq[i];
	    seq[i]--;
	    pos[seq[i]] = i;
	}
	if (seq[0] != 0){
	    cout << "No";
	    return 0;
	}
	if (n == 1){
	    cout << "Yes";
	    return 0;
	}
	par[0] = -1;
	dfs(0, 0);
	for (int i = 0; i < n - 1; i++){
	    if (hgt[seq[i]] > hgt[seq[i + 1]]){
	        cout << "No";
	        return 0;
	    }
	}
	for (int i = 0; i < n - 1; i++){
	    if (pos[par[seq[i]]] > pos[par[seq[i + 1]]]){
	        cout << "No";
	        return 0;
	    }
	}
	cout << "Yes";
}

/*

*/