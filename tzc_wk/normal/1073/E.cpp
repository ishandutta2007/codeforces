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
int l=read(),r=read(),k=read();
int a[20],cnt,P[20];
pii dp[20][1024];
inline pii dfs(int pos,int sta,bool lead,bool limit){
	if(!~pos)	return pii(__builtin_popcount(sta)<=k,0);
	if(!lead&&!limit&&~dp[pos][sta].fi)	return dp[pos][sta];
	int up=(limit)?a[pos]:9;
	pii ans=pii(0,0);
	for(int i=0;i<=up;i++){
		int nsta=(lead&&i==0)?sta:(sta|(1<<i));
		pii nxt=dfs(pos-1,nsta,(lead&&i==0),(limit&&i==up));
		ans=pii((ans.fi+nxt.fi)%MOD,(nxt.fi*P[pos]%MOD*i%MOD+nxt.se+ans.se)%MOD);
	}
//	cout<<pos<<" "<<sta<<" "<<ans.fi<<" "<<ans.se<<endl;
	if(!limit&&!lead)	dp[pos][sta]=ans;
	return ans;
}
inline int solve(int x){
	fill0(a);cnt=0;
	while(x){
		a[cnt++]=x%10;x/=10;
	}
	fz(i,0,18)	fz(j,0,1023)	dp[i][j].fi=dp[i][j].se=-1;
	return dfs(cnt-1,0,1,1).se;
}
signed main(){
	P[0]=1;fz(i,1,18)	P[i]=P[i-1]*10%MOD;
	cout<<(solve(r)-solve(l-1)+MOD)%MOD<<endl;
	return 0;
}