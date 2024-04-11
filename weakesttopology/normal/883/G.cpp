#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;

void test_case(){
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	vector<tuple<int, int, int>> e(m);
	vvi g(n+1);
	for(int i = 0; i < m; i++){
		int t, a, b;
		cin >> t >> a >> b;
		a--;b--;
		e[i] = {t, a, b};
		g[a].push_back(i);
		if(t==2)
		g[b].push_back(i);
	}	
	{
		vi orientation(m);
		vi vis(n);
		int cnt = 0;
		function<void(int)> dfs = [&](int u){
			if(vis[u])return;
			cnt++;
			vis[u] = 1;
			for(auto k: g[u]){
				int v = (get<1>(e[k]) == u)? get<2>(e[k]): get<1>(e[k]);
				if(get<0>(e[k])==1){
					dfs(v);
				}
				else{
					orientation[k] = (get<1>(e[k]) == u)? -1: 1;
				}
				dfs(v);
			}
			
		};
		dfs(s);
		cout << cnt << endl;
		string res;
		for(int i=0; i<m; i++){
			if(orientation[i]==1||(!orientation[i] && get<0>(e[i])==2))res.push_back('+');
			if(orientation[i]==-1)res.push_back('-');
		}
		cout << res << endl;
	}
	{
		vi orientation(m);
		vi vis(n);
		int cnt = 0;
		function<void(int)> dfs = [&](int u){
			if(vis[u])return;
			cnt++;
			vis[u] = 1;
			for(auto k: g[u]){
				int v = (get<1>(e[k]) == u)? get<2>(e[k]): get<1>(e[k]);
				if(get<0>(e[k])==1){
					dfs(v);
				}
				else{
					orientation[k] = (get<1>(e[k]) == u)? -1: 1;
				}
			}
			
		};
		dfs(s);
		cout << cnt << endl;
		string res;
		for(int i=0; i<m; i++){
			if(orientation[i]==1||(!orientation[i] && get<0>(e[i])==2))res.push_back('+');
			if(orientation[i]==-1)res.push_back('-');
		}
		cout << res << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}