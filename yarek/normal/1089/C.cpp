#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 507;
const int INF = 1e9 + 7;

int n, m;
int dist[N][N];
vector <int> cand;

void add(int u, int v){
	dist[u][v] = dist[v][u] = 1;
}

int ask(int v){
	printf("%d\n", v);
	fflush(stdout);
	
	char s[10];
	scanf("%s", s);
	
	if(s[0] == 'F')
		return -1;
	
	int ret;
	scanf("%d", &ret);
	return ret;
}

int get(int u, vector <int> &cur){
	int ret = 0;
	for(int v: cur)
		ret += dist[u][v];
	return ret;
}

int go(vector <int> &cur){
	int best = 0, Dist = INF;
	for(int i = 1; i <= n; ++i){
		int Cur = get(i, cur);
		if(Cur < Dist){
			Dist = Cur;
			best = i;
		}
	}
	
	return best;
}

void solve(){
	cand.clear();
	for(int i = 1; i <= n; ++i)
		cand.push_back(i);
	
	while(true){
		int u = go(cand);
		int v = ask(u);
		
		if(v == -1)
			break;
		
		vector <int> help = cand;
		cand.clear();

		for(int t: help)
			if(dist[u][t] > dist[v][t])
				cand.push_back(t);

		assert(cand.size() <= help.size());
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = i == j ? 0 : INF;
	
	while(m--){
		int k;
		scanf("%d", &k);
		
		vector <int> path(k);
		for(int i = 0; i < k; ++i)
			scanf("%d", &path[i]);
		
		for(int i = 1; i < k; ++i)
			add(path[i - 1], path[i]);
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	
	int quest = n;
	while(quest--)
		solve();
	return 0;
}