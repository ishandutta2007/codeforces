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

const int oo = 0x3f3f3f3f; 

int f[3][3][5]; 
int num[2000000]; 

void fill(int x) {
	for (int i=0; i<=2; ++i) 
		for (int j=0; j<=4; ++j)
			f[x][i][j] = oo;
}

int main() {
	int n, m; 
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) {
		int a; 
		scanf( "%d", &a ); 
		num[a]++; 
	}
	int t = 0; 
	fill(0); fill(1); 
	f[0][0][0] = 0; 
	for (int i = 3; i <= m; ++i) {
		t = 1-t; fill(t); 
		for (int j = 0; j <= 2; ++j)
			for (int k = 0; k <= 4; ++k) 
				for (int p = 0; p <= 2; ++p) 
					if (k+p <= num[i-2]) f[t][p][j+p] = min(f[t][p][j+p], f[1-t][j][k]+(num[i-2]-(k+p)) % 3);
	}
	int ans = oo; 
	for (int i=0; i<=min(2,num[m]); ++i) 
		for (int j=0; j<=min(4,num[m-1]); ++j)
			ans = min(ans, f[t][i][j]+(num[m]-i)%3+(num[m-1]-j)%3); 
	printf( "%d\n", (n-ans)/3); 
}