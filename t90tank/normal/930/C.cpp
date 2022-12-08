#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 100006; 
#define lowbit(x) ((x)&(-(x)))

int n, m; 
int g[maxn]; 
int s[maxn]; 
int f1[maxn], f2[maxn]; 

void ud(int x, int d) {
	x++; 
	for (int i = x; i <= n; i+=lowbit(i)) 
		g[i] = max(g[i], d); 
}

int get(int x) {
	x++; 
	int ans = 0; 
	for (int i = x; i >= 1; i-=lowbit(i))
		ans = max(ans, g[i]); 
	return ans; 
}

int main() {
	scanf( "%d%d", &n, &m );
	for (int i = 1; i <= n; ++i) {
		int l, r; 
		scanf( "%d%d", &l, &r ); 
		//l = rand() % m + 1; 
		//r = rand() % m + 1; 
		//if (l > r) swap(l, r); 
		s[l]++; s[r+1]--; 
	}
	for (int i = 1; i <= m; ++i) s[i] += s[i-1]; 
	for (int i = 1; i <= m; ++i) {
		f1[i] = get(s[i]) + 1; 
		ud(s[i], f1[i]); 
	}
	fill(g, g+n+1, 0);
	reverse(s+1, s+m+1); 
	for (int i = 1; i <= m; ++i) {
		f2[i] = get(s[i]) + 1; 
		ud(s[i], f2[i]); 
	}
	int k = 0; 
	for (int i = 0; i <= m; ++i) 
		k = max(k, f1[i]+f2[m-i]); 
	printf( "%d\n", k ); 
}