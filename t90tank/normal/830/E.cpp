#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3f; 
const int maxn = 200000; 

int n, m; 
vi e[maxn]; 
int d[maxn]; 
int ans[maxn]; 
//bool flag = false; 
int cur[maxn]; 
int tot; 
bool v[maxn]; 
vi r; 

bool dfs(int x, int f) {
	cur[++tot] = x; v[x] = true; 
	for (auto i : e[x]) 
		if (i != f) {
			if (!v[i]) {
				if (dfs(i,x)) return true; 
			}
			else {
				for (int j = tot; cur[j] != i; j--) r.pb(cur[j]); 
				r.pb(i); 
				return true; 
			}
		}
	return false; 
	tot--; 
}

bool dfs2(int x, int f, int y) {
	if (x == y) return true; 
	for (auto i : e[x]) 
		if (i != f) {
			if (dfs2(i, x, y)) {
				ans[x] = 2; 
				return true; 
			}
		}
	return false; 
}

void Wr() {
	puts( "YES" ); 
	for (int j = 1; j <= n; ++j) printf("%d ", ans[j]); 
	puts( "" ); 
}

vi p; 
bool flag[maxn]; 
void getcon(int x) {
	p.pb(x); 
	flag[x] = true; 
	for (auto i : e[x]) 
		if (!flag[i]) getcon(i); 
}
 
vi u[3]; 
int no[3]; 
void getl(int num, int x, int f) {
	u[num].pb(x); 
	for (auto i : e[x]) 
		if (i != f) 
			getl(num, i, x); 
}

bool cmp(vi x, vi y) {
	return x.size() < y.size(); 
}

int solve(int n) {
	for (auto i : p) 
		if (d[i] >= 4) {
			ans[i] = 2;
			//int s = 0; 
			for (auto j : e[i]) ans[j] = 1; 
			Wr(); 
			return true; 
		}
	tot = 0; r.clear(); 
	if (dfs(p[0], 0)) {
		for (auto i : r) ans[i] = 1; 
		Wr(); 
		return 1; 
	}
	vi d3; 
	for (auto i : p) 
		if (d[i] >= 3) d3.pb(i); 
	if ((int)d3.size() >= 2) {
		for (auto i : e[d3[0]]) ans[i] = 1; 
		for (auto i : e[d3[1]]) ans[i] = 1; 
		assert(dfs2(d3[0], 0, d3[1]));
		ans[d3[0]] = ans[d3[1]] = 2;  
		Wr(); 
		return 2; 
	}
	if ((int)d3.size() >= 1) {
		int x = d3[0];
		int tot = 0; 
		for (auto i : e[x]) {
			u[tot].clear(); 
			getl(tot, i, x); 
			tot++; 
		}	
		for (int i = 0; i < 3; ++i) no[i] = i; 
		sort(u,u+3,cmp);
		while (u[0].size() > 2) u[0].pop_back(); 
		if (u[0].size() == 2) {
			while (u[1].size() > 2) u[1].pop_back(); 
			while (u[2].size() > 2) u[2].pop_back(); 
			ans[x] = 3; 
			for (int i = 0; i < 3; ++i) 
				for (int j = 0; j < 2; ++j) 
					ans[u[i][j]] = 2 - j; 
			Wr(); 
			return 3; 
		}
		if (u[1].size() >= 3) {
			while (u[1].size() > 3) u[1].pop_back(); 
			while (u[2].size() > 3) u[2].pop_back(); 
			ans[x] = 4; 
			ans[u[0][0]] = 2; 
			for (int i = 0; i < 3; ++i) ans[u[1][i]]=ans[u[2][i]]=3-i; 
			Wr(); 
			return 4; 
		}
		else {
			if (u[1].size() <= 1 || (u[1].size() == 2 && u[2].size() < 5)) return 0; 
			while (u[2].size() > 5) u[2].pop_back(); 
			ans[x] = 6; 
			ans[u[0][0]] = 3; 
			for (int i = 0; i < 2; ++i) ans[u[1][i]] = 4 - 2 * i; 
			for (int i = 0; i < 5; ++i) ans[u[2][i]] = 5 - i; 
			Wr(); 
			return 5; 
		}
		
	}
	return 0; 
}

void init() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) {
		e[i].clear(); 
		d[i] = 0; 
		v[i] = false; 
		ans[i] = 0; 
	}
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].pb(b); e[b].pb(a); 
		d[a]++; d[b]++; 
	}
	
	fill(flag, flag+n+1, false); 
	for (int i = 1; i <= n; ++i) 
		if (!flag[i]) {
			p.clear(); 
			getcon(i); 
			int tmp = solve(p.size()); 
			if (tmp) {
				int s = 0; 
				for (int i = 1; i <= n; ++i) s += ans[i] * ans[i]; 
				for (int i = 1; i <= n; ++i) 
					for (auto j : e[i]) 
						if ( i < j ) s -= ans[i] * ans[j]; 
				//if (s>0) cout<<tmp<<endl; 
				if (s > 0) {
					if (tmp == 3) while (1);
					if (tmp == 4) assert(false); 
				}
				//assert(s <= 0); 
				//cout<<s<<endl; 
				return; 
			}
		}
	puts( "NO" ); 
}

int main() {
	int t; 
	cin>>t; 
	while (t--) init(); 
}