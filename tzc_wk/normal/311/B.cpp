/*
Contest: -
Problem: Codeforces 311B
Author: tzc_wk
Time: 2020.5.20
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
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
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
int n=read(),m=read(),k=read(),d[100005],ss[100005],a[100005],s[100005];
int dp[100005][105];
int q[100005],hd=1,tl=0;
inline int _y(int x,int p){
	return dp[x][p-1]+s[x];
}
inline int _x(int x){
	return x;
}
inline double sl(int j,int k,int p){
	return 1.0*(_y(j,p)-_y(k,p))/(_x(j)-_x(k));
}
signed main(){
	fz(i,2,n)	d[i]=read();
	fz(i,1,n)	ss[i]=ss[i-1]+d[i];
	fz(i,1,m){
		int x=read(),y=read();
		a[i]=y-ss[x];
	}
	sort(a+1,a+m+1);
//	fz(i,1,m)	cout<<a[i]<<" ";puts("");
	fz(i,1,m)	s[i]=s[i-1]+a[i];
//	fillbig(dp);
	fz(i,0,m)	fz(j,0,k)	dp[i][j]=1ll<<45;
	dp[0][0]=0;
//	fz(i,0,k)
//		dp[i][i]=0;
	fz(p,1,k){
		hd=1,tl=0;
		q[++tl]=0;
		fz(i,1,m){
			while(hd<tl&&sl(q[hd],q[hd+1],p)<a[i])	hd++;
			dp[i][p]=dp[q[hd]][p-1]+(i-q[hd])*a[i]-s[i]+s[q[hd]];
			while(hd<tl&&sl(q[tl],q[tl-1],p)>sl(q[tl],i,p))	tl--;
			q[++tl]=i;
//			cout<<i<<" "<<p<<" "<<dp[i][p]<<endl;
		}
	}
	cout<<dp[m][k]<<endl;
	return 0;
}
/*
dp[i][p]=min(dp[j][p-1]+(i-j)*a[i]-s[i]+s[j])

j>k

dp[j][p-1]+(i-j)*a[i]-s[i]+s[j]<dp[k][p-1]+(i-k)*a[i]-s[i]+s[k]
dp[j][p-1]-j*a[i]+s[j]<dp[k][p-1]-k*a[i]+s[k]
dp[j][p-1]-dp[k][p-1]+s[j]-s[k]<(j-k)*a[i]

      (dp[j][p-1]-dp[k][p-1]+s[j]-s[k])
a[i]>-----------------------------------
	  			    (j-k)
*/