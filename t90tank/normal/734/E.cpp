#include <iostream>
#include <vector>
#include <set> 
#include <cstring> 
using namespace std; 
const int maxn = 200006; 

int n; 
int c[maxn]; 
vector<int> e[maxn]; 
int f[maxn]; 
int jump[maxn]; 
int color[maxn]; 
int tot; 
int l[maxn]; 
vector<int> s[maxn]; 

void dfs(int x, int p) {
	if (p == 0 || c[x] != c[p]) {
		f[++tot] = jump[p]; 
		color[tot] = c[x]; 
		jump[x] = tot; 
	}
	else jump[x] = jump[p]; 
	for (auto i : e[x]) 
		if (i != p) 
			dfs(i, x); 
}

multiset<int> S;
int main() {
	cin>>n; 
	for (int i = 1; i <= n; ++i) cin>>c[i]; 
	for (int i = 1; i < n; ++i) {
		int u, v; 
		cin>>u>>v; 
		e[u].push_back(v);
		e[v].push_back(u);
	}
	jump[0] = 0; 
	dfs(1, 0);
	for (int i = 1; i <= tot; ++i) s[f[i]].push_back(i); 
	for (int i = 1; i <= tot; ++i) l[i] = 1; 
	for (int i = tot; i >= 1; --i) l[f[i]] = max(l[f[i]], l[i]+1);
	int ans = l[1];  
	for (int i = 1; i <= tot; ++i) {
		S.clear(); 
		for (auto j : s[i]) 
			S.insert(l[j]); 
		if (S.size() > 1) {
			int a = *S.rbegin(); S.erase(prev(S.end())); 
			int b = *S.rbegin(); 
			ans = max(ans, a+b+1); 
		}
	}
	cout<<ans/2<<endl;
}