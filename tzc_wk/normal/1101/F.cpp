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
int dp[405][405][2],a[250005],b[250005],c[250005],d[250005],n=read(),m=read(),t[405];
vector<int> q[250005];
int ans=0;
signed main(){
	fz(i,1,n)	t[i]=read();
	fz(i,1,m){
		a[i]=read();
		b[i]=read();
		c[i]=read();
		d[i]=read();
		d[i]++;
		d[i]=min(d[i],b[i]-a[i]);
		q[d[i]].push_back(i);
	}
	fillbig(dp);
	fz(i,1,n)	fz(j,i,n)	dp[i][j][1]=t[j]-t[i];
	fz(k,1,n-1){
		foreach(it,q[k]){
			ans=max(ans,dp[a[*it]][b[*it]][k&1]*c[*it]);
		}
		fz(i,1,n){
			dp[i][i][(k+1)&1]=0;
			int l=i;
			for(int j=i+1;j<=n;j++){
				while(dp[i][l][k&1]<t[j]-t[l])	l++;
				dp[i][j][(k+1)&1]=min(dp[i][l][k&1],t[j]-t[l-1]);
//				cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][(k+1)&1]<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
10 10
2 3 4 8 9 10 12 13 15 19
3 8 3 1
3 4 3 2
1 9 2 1
1 9 3 1
6 10 2 1
3 9 2 0
3 7 2 1
2 3 3 0
3 9 2 0
4 10 3 0
*/