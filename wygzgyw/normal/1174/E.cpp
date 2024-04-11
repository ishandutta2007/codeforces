#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(1e6)+5;
int n,dp[maxn][21][3];
int m2[21],m3[3];
int f(int x,int y) {
	return n/(m2[x]*m3[y]);
}
void add(int &d,int x,int y) {
	d+=(ll)x*y%mod;
	if (d>=mod) d-=mod;
}
int main() {
	read(n);
	int cnt=0;
	while ((1<<cnt)<=n) cnt++;
	cnt--;
	for (int i=0;i<=cnt;i++) m2[i]=1<<i;
	m3[0]=1; m3[1]=3;
	dp[1][cnt][0]=1;
	if (f(cnt-1,1)) dp[1][cnt-1][1]=1;
	for (int i=1;i<=n;i++) {
		for (int x=0;x<=cnt;x++)
		for (int y=0;y<=1;y++) {
			add(dp[i+1][x][y],dp[i][x][y],f(x,y)-i);
			if (x) add(dp[i+1][x-1][y],dp[i][x][y],f(x-1,y)-f(x,y));
			if (y) add(dp[i+1][x][y-1],dp[i][x][y],f(x,y-1)-f(x,y));
		}
	}
	printf("%d\n",dp[n][0][0]);
	return 0;
}