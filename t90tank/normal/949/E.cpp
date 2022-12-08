#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

vi a; 
vi tmp; 
vi ans; 
int n; 

void dfs(int dep, vi a) {
	if (dep >= 20) {
		if (a.size() == 1) {
			if (tmp.size() < ans.size()) ans = tmp; 
		}
		return; 
	}
	bool flag = false; 
	for (auto i : a) 
		if (i & (1<<dep)) flag = true;
	if (flag) {
		vi b; 
		b.clear(); 
		for (auto i : a) 
			if (i & (1<<dep)) b.pb(i-(1<<dep)); 
			else b.pb(i); 
		tmp.pb((1<<dep));
		b.erase(unique(b.begin(), b.end()), b.end()); 
		dfs(dep+1, b);  
		tmp.pop_back(); 
		b.clear(); 
		for (auto i : a) 
			if (i & (1<<dep)) b.pb(i+(1<<dep)); 
			else b.pb(i); 
		tmp.pb(-(1<<dep));
		b.erase(unique(b.begin(), b.end()), b.end()); 
		dfs(dep+1, b);  
		tmp.pop_back(); 
	}
	else dfs(dep+1, a); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf( "%d", &x ); 
		a.pb(x); 
	}
	for (int i = 0; i <= 19; ++i) 
		ans.pb((1<<i)); 
	ans.pb(-(1<<20)); 
	sort(a.begin(), a.end()); 
	a.erase(unique(a.begin(), a.end()), a.end()); 
	dfs(0, a); 
	printf( "%d\n", (int)ans.size() ); 
	for (auto i : ans) printf( "%d ", i ); 
	puts( "" ); 
}