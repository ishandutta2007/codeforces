#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 

int n;
vector<int> e[maxn];
int s[maxn]; 
int A = -1, B = -1; 

void build(int x, int p) {
	s[x] = 1; 
	for (auto i : e[x]) 
		if (i != p) {
			build(i, x); 
			s[x] += s[i]; 
		}
}

void Find(int x, int p) {
	//cout<<x<<' '<<p<<endl; 
	for (auto i : e[x]) 
		if (i != p) {
			if (s[i] > n/2) {
				Find(i, x); 
				return; 
			}
			else if (s[i] == n/2 && n % 2 == 0) {
				A = x, B = i; 
				return; 
			}
		}
	A = x; 
	return; 
} 

struct data {
	int x, y1, y2; 
}; 

vector<data> ans; 

int pre; 
void dfs(int x, int p, int o, int t) {
	if (x != t) {
		ans.pb({o,pre,x}); 
		ans.pb({x,p,t}); 
		pre = x; 
	}
	for (auto i : e[x]) 
		if (i != p) 
			dfs(i, x, o, t); 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i < n; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].pb(b); 
		e[b].pb(a); 
	}
	build(1,0); 
	Find(1,0); 
	for (auto i : e[A]) 
		if (i != B) {
			pre = i;
			dfs(i,A,A,i);  
			ans.pb({A,pre,i}); 
		}
	if (B != -1) 
		for (auto i : e[B]) 
			if (i != A) {
				pre = i; 
				dfs(i,B,B,i);
				ans.pb({B,pre,i}); 
			}
	cout<<ans.size()<<endl;
	for (auto i : ans) printf( "%d %d %d\n", i.x, i.y1, i.y2 ); 
}