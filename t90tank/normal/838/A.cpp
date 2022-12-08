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

const int maxn = 5006; 

int n, m; 
char a[maxn][maxn]; 
int s[maxn][maxn]; 

bool isprime(int x) {
	for (int i = 2; i*i <= x; ++i) 
		if (x % i == 0) return false; 
	return true; 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) scanf("%s", a[i]+1);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='1'); 
	int D = max(n,m)*2+1; 
	for (int i = 1; i <= D; ++i) 
		for (int j = 1; j <= D; ++j) 
			if (i > n || j > m) s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]; 
	int ans = D*D; 
	for (int k = 2; k <= max(n,m); ++k) 
		if (isprime(k)) {
			int sum = 0; 
			for (int i = 0; i < n; i+=k)
				for (int j = 0; j < m; j+=k) {
					int tmp = s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j]; 
					sum += min(tmp, k*k-tmp); 
				}
			ans = min(ans, sum); 
		}
	cout<<ans<<endl; 
}