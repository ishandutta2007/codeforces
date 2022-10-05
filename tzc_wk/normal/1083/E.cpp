/*
Contest: -
Problem: Codeforces 1083E
Author: tzc_wk
Time: 2020.7.21
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
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read();
struct bar{
	int x,y,w;
	friend bool operator <(bar a,bar b){
		return a.x<b.x;
	}
} a[1000005];
int dp[1000005];
inline double sl(int j,int k){
	return 1.0*(dp[j]-dp[k])/(a[j].x-a[k].x);
}
int q[1000005],hd=1,tl=0;
signed main(){
	fz(i,1,n)	a[i].x=read(),a[i].y=read(),a[i].w=read();
	sort(a+1,a+n+1);
	fillbig(dp);
	dp[0]=0;
	q[++tl]=0;
	int ans=0;
	fz(i,1,n){
		while(hd<tl&&sl(q[hd],q[hd+1])>a[i].y)	hd++;
		int j=q[hd];
		dp[i]=dp[j]+(a[i].x-a[j].x)*a[i].y-a[i].w;
//		printf("%lld\n",dp[i]);
		while(hd<tl&&sl(q[tl-1],q[tl])<sl(q[tl],i))	tl--;
		q[++tl]=i;
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}