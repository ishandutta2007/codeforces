/*
Contest: -
Problem: Codeforces 401D
Author: tzc_wk
Time: 2020.7.31
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
int a[20],cnt=0,dp[262144][105],num[10],f[20];
signed main(){
	while(n){
		a[++cnt]=n%10;
		n/=10;
	}
	f[0]=1;
	fz(i,1,18) f[i]=f[i-1]*i;
	for(int i=1;i<=cnt;i++) if(a[i]!=0) dp[1<<(i-1)][a[i]%m]=1;
	for(int i=0;i<(1<<cnt);i++){
		for(int j=0;j<m;j++){
//			printf("%d %d %d\n",i,j,dp[i][j]);
			for(int k=1;k<=cnt;k++){
				if(!((i>>(k-1))&1)){
					dp[i|(1<<(k-1))][(j*10+a[k])%m]+=dp[i][j];
				}
			}
		}
	}
	int ans=dp[(1<<cnt)-1][0];
	for(int i=1;i<=cnt;i++) num[a[i]]++;
	for(int i=0;i<=9;i++)	ans/=f[num[i]];
	printf("%lld\n",ans); 
	return 0;
}