#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

const int maxn = 200006; 

int n; 
vi e[maxn]; 
int p[maxn];

void dfs(int x, int f) {
	for (auto i : e[x]) 
		if (i != f) {
			p[i] = -p[i]; 
			printf( " %d", i); 
			dfs(i, x); 
			printf( " %d", x); 
			p[x] = -p[x]; 
			if (p[i] < 0) {
				printf( " %d", i); 
				p[i] = -p[i]; 
				printf( " %d", x);
				p[x] = -p[x]; 
			} 
		}
}

int main() {
	bool flag = true; 
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &p[i] ); 
		flag &= (p[i] == 1); 
	}
	for (int i = 1; i < n; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].pb(b); e[b].pb(a); 
	}
	printf( "1" ); 
	if (!flag) {
		dfs(1, 0); 
		if (p[1] < 0) {
			int i = e[1][0]; 
			printf( " %d 1 %d", i,i ); 
		}
	}
	puts( "" ); 
}