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
int n=read(),m=read();
vector<pii> g[1000005],ng[1000005];
int idx=0,low[1000005],dfn[1000005],stk[1000005],top=0;
bool vis[1000005];
int from[1000005],comp=0;
int pre[1000005],sum[1000005];
inline int calc(int x){
	int l=1,r=1000000,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid*(mid-1)/2<=x)	ans=mid,l=mid+1;
		else				r=mid-1;
	}
	return x*ans-pre[ans];
}
inline void tarjan(int x){
	low[x]=dfn[x]=++idx;
	stk[++top]=x;vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].fi;
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){
		comp++;
		while(top){
			int y=stk[top];top--;
			from[y]=comp;
			vis[y]=0;
			if(x==y)	break;
		}
	}
}
int dp[1000005];
inline int dfs(int x){
	if(~dp[x])	return dp[x];
	dp[x]=0;
	for(int i=0;i<ng[x].size();i++){
		int y=ng[x][i].fi;
		dp[x]=max(dp[x],dfs(y)+ng[x][i].se);
	}
	dp[x]+=sum[x];
	return dp[x];
}
signed main(){
	fz(i,1,1000000)	pre[i]=pre[i-1]+(i*(i-1)/2);
//	cout<<calc(4)<<endl;
	fz(i,1,m){
		int u=read(),v=read(),w=read();
		g[u].push_back({v,w});
	}
	int s=read();
	tarjan(s);
	fz(i,1,n){
		foreach(it,g[i]){
			int j=it->first;
			if(!from[i]||!from[j])	continue;
			if(from[i]==from[j]){
				sum[from[i]]+=calc(it->second);
//				cout<<"-1\n";
			}
			else{
				ng[from[i]].push_back({from[j],it->second});
			}
		}
	}
//	cout<<sum[1]<<endl;
	fill1(dp);
	cout<<dfs(from[s])<<endl;
	return 0;
}