#include <bits/stdc++.h>
#define N 2020
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N], b[N], f[N][N];
signed main(int argc, char const *argv[]){
	int k = read(), n = read(), s = read();
	for(int i = 1; i <= k; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	sort(a+1, a+k+1); sort(b+1, b+n+1);
	memset(f, 63, sizeof(int)*N*N);
	for(int i = 1; i <= k; i++){
		int zyy = i == 1 ? 0 : (1ll<<60);
		for(int j = 1; j <= n; j++){
			f[i][j] = max(zyy, abs(a[i]-b[j])+abs(b[j]-s));
			zyy = min(zyy, f[i-1][j]);
		}
	}
	int ans = 1ll<<60;
	for(int i = 1; i <= n; i++) ans = min(ans, f[k][i]);
	printf("%lld\n", ans);
	return 0;
}