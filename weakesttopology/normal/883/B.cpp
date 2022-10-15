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
	int n, m, k;
	cin >> n >> m >> k;
	vi out(n), p(n);
	vvi g1(n), g2(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b; 
		a--;b--;
		g1[a].push_back(b);
		g2[b].push_back(a);
		out[a]++;
	}
	vi topologicOrder;
	{
		vi vis(n);
		function<void(int)> dfs = [&](int u){
			if(vis[u]==2){
				cout << -1 << endl;
				exit(0);
			}
			if(vis[u])return;
			vis[u]=2;
			for(auto v: g1[u]){
				dfs(v);
			}
			topologicOrder.push_back(u);
			vis[u]=1;
		};
		for(int i = 0; i < n; i++){
			dfs(i);
		}
	}
	vi min_v(n, 1), max_v(n, k);
	for(int i = 0; i < n; i++)
		if(p[i]) min_v[i] = max_v[i] = p[i];
	
	for(int i = 0; i < n; i++){
		int u = topologicOrder[i];
		for(auto v: g2[u])
			min_v[v] = max(min_v[v], min_v[u]+1);
	}
	for(int i = n-1; i >= 0; i--){
		int u = topologicOrder[i];
		for(auto v: g1[u])
			max_v[v] = min(max_v[v], max_v[u]-1);
	}
	priority_queue<ii> q, events;
	for(int i = 0; i < n; i++){
		if(min_v[i] > max_v[i] || min_v[i] > k || max_v[i] < 1){
			cout << -1 << endl;
			exit(0);
		}
		if(!out[i]){
			events.push({-min_v[i], i});
		}
	}
	function<void(int)> getNext = [&](int u){
		for(auto v: g2[u]){
			if(out[v]-- == 1){
				events.push({-min_v[v], v});
			}
		}
	};
	function<void(int)> prop = [&](int i){
		while(!events.empty() && -events.top().f <= i){
			int x = events.top().s;
			events.pop();
			q.push({-max_v[x], x});
		}
	};
	
	
	for(int i = 1; i <= k; i++){
		prop(i);
		if(q.empty()){
			cout << -1 << endl;
			exit(0);
		}
		int x = q.top().s;
		if(min_v[x]>i || max_v[x] < i){
			cout << -1 << endl;
			exit(0);
		}
		p[x] = i;
		getNext(x);
		prop(i);
		q.pop();
		while(!q.empty() && -q.top().f == i){
			x = q.top().s;
			q.pop();
			p[x] = i;
			getNext(x);
			prop(i);
		}
	}
	for(int i = 0; i < n; i++){
		cout << p[i] << " ";
	}	
	cout << endl;
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