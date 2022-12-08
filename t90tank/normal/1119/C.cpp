#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

int n, m; 
int c[2000];  

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int t = 1; t <= 2; ++t)
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) {
				int x; 
				scanf("%d", &x ); 
				c[i] ^= x; 
				c[j+n] ^= x;
			} 
	for (int i = 1; i <= n+m; ++i)
		if (c[i] != 0) {
			puts( "No" ); 
			return 0; 
		}
	puts( "Yes" ); 
}