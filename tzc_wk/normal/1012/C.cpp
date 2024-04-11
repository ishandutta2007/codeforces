/*
Contest: -
Problem: P6304
Author: tzc_wk
Time: 2020.6.1
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),a[5005],dp[5005][5005][3];
signed main(){
	fz(i,1,n)	a[i]=read();
	fillbig(dp);
	dp[1][0][0]=dp[1][1][1]=0;
	fz(i,2,n){
		fz(j,0,n){
			dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][2]);
            dp[i][j][1]=min(dp[i-1][j-1][0]+max(0,a[i-1]-a[i]+1),dp[i-1][j-1][2]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1));
            dp[i][j][2]=dp[i-1][j][1]+max(0,a[i]-a[i-1]+1);
		}
	}
	fz(i,1,ceil(1.0*n/2))	cout<<min(dp[n][i][0],min(dp[n][i][1],dp[n][i][2]))<<" ";
	return 0;
}