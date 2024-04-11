//Coded by tzc_wk
/*




D P 




 l l
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
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
const int MOD=998244353;
int n=read(),m=read(),a[505];
int mn[505][505],dp[505][505];
inline int dfs(int l,int r){
	if(l>=r)		return 1;
	if(~dp[l][r])	return dp[l][r];
	int sum1=0,sum2=0;
	int pos=mn[l][r];
	fz(i,l-1,pos-1){
		sum1=(sum1+dfs(l,i)*dfs(i+1,pos-1)%MOD)%MOD;
	}
	fz(i,pos,r){
		sum2=(sum2+dfs(pos+1,i)*dfs(i+1,r)%MOD)%MOD;
	}
	dp[l][r]=sum1*sum2%MOD;
	return dp[l][r];
}
signed main(){
	fz(i,1,m)	a[i]=read();
	fz(i,1,m)
		fz(j,1,i){
			mn[j][i]=j;
			fz(k,j+1,i)
				if(a[k]<a[mn[j][i]])
					mn[j][i]=k;
		}
	fill1(dp);
	cout<<dfs(1,m)<<endl;
	return 0;
}