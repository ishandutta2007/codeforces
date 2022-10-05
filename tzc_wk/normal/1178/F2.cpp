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
int n=read(),m=read(),a[1000005],dp[1005][1005];
vector<int> pos[505];
signed main(){
	for(int i=1;i<=m;i++)	a[i]=read();
	m=unique(a+1,a+m+1)-(a+1);
	if(m>2*n) return puts("0"),0;
	for(int i=1;i<=m;i++)	pos[a[i]].push_back(i);
	for(int i=1;i<=m+1;i++)	dp[i][i-1]=1;
	for(int len=1;len<=m;len++){
		for(int i=1,j=len;j<=m;i++,j++){
			int p=*std::min_element(a+i,a+j+1);
			int l=pos[p].front(),r=pos[p].back();
			if(l<i||r>j){
				dp[i][j]=0;
				continue;
			}
			int a=0,b=0;
			for(int k=i;k<=l;k++){
				a=(a+dp[i][k-1]*dp[k][l-1]%MOD)%MOD;
			}
			for(int k=r;k<=j;k++){
				b=(b+dp[r+1][k]*dp[k+1][j]%MOD)%MOD;
			}
			dp[i][j]=a*b%MOD;
			for(int k=1;k<pos[p].size();k++){
				dp[i][j]=dp[i][j]*dp[pos[p][k-1]+1][pos[p][k]-1]%MOD;
			}
		}
	}
	cout<<dp[1][m]<<endl;
	return 0;
}