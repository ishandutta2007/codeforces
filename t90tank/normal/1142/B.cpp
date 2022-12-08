#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 200006; 
const int D = 20; 

int n,m,q; 
int h[maxn];
int p[maxn];  
int a[maxn]; 
deque<int> deq[maxn]; 
int bef[maxn]; 
int ans[maxn];
int jump[D][maxn];  

int main() {
	scanf( "%d%d%d", &n, &m, &q ); 
	for (int i = 0; i < n; ++i) {
		int x; 
		scanf( "%d", &x ); 
		h[x] = i; 
	}
	for (int i = 1; i <= m; ++i) {
		int x; 
		scanf( "%d", &x ); 
		a[i] = h[x]; 
	}
	
	for (int i = 0; i < n; ++i) bef[i] = 0;
	
	jump[0][0] = 0; 
	for (int i = 1; i <= m; ++i) {
		jump[0][i] = bef[(a[i]+n-1)%n]; 
		//printf( "jump[%d]=%d\n", i, jump[0][i] ); 
		bef[a[i]] = i; 
	}
	for (int i = 1; i < D; ++i) 
		for (int j = 0; j <= m; ++j) 
			jump[i][j] = jump[i-1][jump[i-1][j]]; 
	for (int j = 1; j <= m; ++j) {
		int s = 0; 
		int x = j; 
		for (int i = D-1; i >= 0; --i) 
			if (s + (1<<i) < n) {
				s+=(1<<i); 
				x = jump[i][x]; 
				//printf( "%d %d\n", s, x ); 
			}
		//printf( "ans[%d]=%d\n", j, ans[j] ); 
		ans[j] = x; 
	}
	
	for (int i = 1; i <= m; ++i) 
		ans[i] = max(ans[i], ans[i-1] ); 
	while (q--) {
		int l, r; 
		scanf( "%d%d", &l, &r ); 
		if (ans[r] >= l) printf( "1" ); 
		else printf( "0" ); 
	}
	puts( "" ); 
}