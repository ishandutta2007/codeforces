#include <bits/stdc++.h>
using namespace std; 

const int maxn = 17; 
const int oo = 0x3f3f3f3f; 
using ll = long long; 

int f[(1<<maxn)][300]; 
int n; 
int t[maxn]; 
int r[maxn], b[maxn]; 
ll sr, sb; 

int main() {
	scanf( "%d", &n ); 
	sr = sb = 0; 
	for (int i = 0; i < n; ++i) {
		char st[10]; 
		scanf( "%s%d%d", st, &r[i], &b[i] ); 
		sr += r[i]; sb += b[i]; 
		if (st[0] == 'R') t[i] = 0; 
		else t[i] = 1; 
	}
	int D = (n-1)*n/2; 
	for (int i = (1<<n)-1; i >= 0; --i) 
		for (int j = 0; j <= D; ++j) 
			f[i][j] = -oo; 
	for (int i = (1<<n)-1; i >= 0; --i) {
		f[i][0] = max(f[i][0],0); 
		int s[2]; 
		s[0] = s[1] = 0; 
		for (int j = 0; j < n; ++j) 
			if (!((i>>j) & 1)) s[t[j]]++; 
		int num[2][maxn];
		int tot[2]; 
		tot[0] = tot[1] = 0; 
		for (int j = 0; j < n; ++j) 
			if ((i>>j)&1) {
				num[0][j] = (r[j]>s[0]); 
				num[1][j] = (b[j]>s[1]); 
				tot[0] += num[0][j]; 
				tot[1] += num[1][j]; 
			}
		for (int j = 0; j < n; ++j) 
			if ((i>>j)&1) {
				int dr = tot[0]-num[0][j]; 
				int db = tot[1]-num[1][j]; 
				if (t[j]==0) db = 0; 
				else dr = 0; 
			//	cout<<i<<' '<<j<<' '<<dr<<' '<<db<<endl; 
				for (int k = 0; k <= D-dr; ++k) 
					f[i-(1<<j)][k+dr] = max(f[i-(1<<j)][k+dr], f[i][k]+db); 
			}
	}
	ll ans = max(sr,sb); 
	for (int i = 0; i <= D; ++i) 
		ans = min(ans,max(sr-i,sb-f[0][i])); 
	cout<<ans+n<<endl; 
}