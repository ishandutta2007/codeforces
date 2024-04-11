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
int n=read(),a[505],dp[505][505];
int is[505][505];
inline int dfs(int l,int r){
	if(l>r)			return 0;
	if(l==r)		return 1;
	if(~dp[l][r])	return dp[l][r];
	dp[l][r]=r-l+1;
	fz(i,l,r)		if(is[l][i])	dp[l][r]=min(dp[l][r],1+dfs(i+1,r));
	fz(i,l,r-1)		dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r));
	return dp[l][r];
}
int mn[505][505];
signed main(){
	fz(i,1,n)	a[i]=read(),is[i][i]=a[i];
	fz(i,1,n)	fz(j,1,i){
		mn[j][i]=0x3f3f3f3f;
		fz(k,j,i)	mn[j][i]=min(mn[j][i],a[k]);
	}
	fz(len,2,n){
		for(int l=1,r=len;r<=n;l++,r++){
			fz(i,l,r-1){
				if(is[l][i]&&is[i+1][r]){
					if(is[l][i]==is[i+1][r])	is[l][r]=is[l][i]+1;
				}
			}
//			cout<<l<<" "<<r<<" "<<is[l][r]<<endl;
		}
	}
	fill1(dp);
	cout<<dfs(1,n)<<endl;
	return 0;
}
/*
10
4 3 3 4 5 6 7 8 9 10 
*/
/*
8
4 3 1 1 1 1 4 4
*/