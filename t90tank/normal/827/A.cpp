#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const int maxn = 3000000; 
char s[maxn]; 
char t[maxn]; 
int n, k, x, maxl; 
int nxt[maxn]; 


int main() {
	maxl = 0; 
	scanf( "%d", &n ); 
	for (int i = 0; i < maxn; ++i) s[i] = 'a'; 
	for (int i = 0; i < maxn; ++i) nxt[i] = i+1; 
	for (int i = 1; i <= n; ++i) {
		scanf( "%s%d", t, &k ); 
		int len = strlen(t); 
		for (int j = 1; j <= k; ++j) {
			scanf( "%d", &x );
			x--;  
			for (int y = x; y < x+len;) {
				s[y] = t[y-x]; 
				int prey = y; 
				y = nxt[y]; 
				nxt[prey] = max(nxt[prey],x+len); 
				//printf( "%d ", y); 
			}
			//puts( "" ); 
			//for (int y = x; y < x+len; ++y) printf( "%d ", nxt[y] ); 
			//puts( "" ); 
			maxl = max(maxl, x+len); 
		}
	}
	s[maxl] = 0; 
	printf( "%s\n", s ); 
}