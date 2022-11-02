// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
int T,n,k,a[60];
bool dp[60][60][2];
bool f[60][60][2];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(k);
		for (int i=1;i<=n;i++) read(a[i]);
		memset(dp,0,sizeof(dp));
		for (int l=n;l>=1;l--) {
			memset(f,0,sizeof(f));
			f[l-1][0][0]=1;
			for (int r=l;r<=n;r++) {
				if (l==r) dp[l][r][a[l]]=1;
				else {
					for (int mid=l;mid<r;mid++) for (int v1=0;v1<=1;v1++) for (int v2=0;v2<=1;v2++)
						if (dp[l][mid][v1]&&dp[mid+1][r][v2]) dp[l][r][min(v1,v2)]=1;
					for (int i=l;i<=r;i++) for (int used=0;used<k;used++) {
						for (int v1=0;v1<=1;v1++) for (int v2=0;v2<=1;v2++) {
							if (f[i-1][used][v1]&&dp[i][r][v2]) f[r][used+1][max(v1,v2)]=1;
						}
					}
				}
				if (f[r][k][0]) dp[l][r][0]=1;
				if (f[r][k][1]) dp[l][r][1]=1;
				
				if (dp[l][r][0]) f[r][1][0]=1;
				if (dp[l][r][1]) f[r][1][1]=1;
			}
		}
		if (dp[1][n][1]) puts("YES"); else puts("NO");
	}
	return 0;
}