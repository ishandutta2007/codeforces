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

const int h = 20; 
const int maxn = 300006; 
const int oo = 0x3f3f3f3f; 

int g[maxn][h]; 
int c[h][h]; 
int n, q; 
int a[maxn]; 

int main() {
	scanf("%d%d", &n, &q); 
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < h; ++i) 
		for (int j = 0; j < h; ++j) 
			c[i][j] = n+1; 
	for (int i = n; i >= 1; --i) {
		for (int p = 0; p < h; ++p) 
			if ((a[i]>>p)&1) g[i][p] = i;
			else { 
				g[i][p] = n+1; 
				for (int x = 0; x < h; ++x)
					if ((a[i]>>x)&1)
						g[i][p] = min(g[i][p], c[x][p]); 
			}
		for (int p = 0; p < h; ++p) 
			for (int x = 0; x < h; ++x) 
				if ((a[i]>>x)&1)
					c[x][p] = min(c[x][p], g[i][p]); 
	}
	while (q--) {
		int x, y; 
		scanf("%d%d", &x, &y); 
		bool flag = false; 
		for (int p = 0; p < h; ++p)
			if (((a[y]>>p)&1) && g[x][p] <= y) 
				flag = true; 
		if (flag) puts("Shi"); 
		else puts("Fou"); 
	}
}