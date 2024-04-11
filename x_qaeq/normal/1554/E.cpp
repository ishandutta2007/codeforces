//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=998244353;vector<int>v[100005];
struct edge{int to,nxt;}e[200005];int et,head[100005],n;
int sz[100005],rs[100005],mu[100005],pc,pr[100005];char pv[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	pv[1]=1,mu[1]=1;for(int i=1;i<=100000;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1;
		for(int j=1;j<=pc&&pr[j]*i<=100000;j++)
		{
			if(i%pr[j]) mu[i*pr[j]]=-mu[i];else mu[i*pr[j]]=0;
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
	for(int i=2;i<=100000;i++) for(int j=i;j<=100000;j+=i) v[j].push_back(i);
}
inline char chk(int x,int fa,int K)
{
	sz[x]=0;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
		{if(!chk(e[i].to,x,K)) return 0;else sz[x]+=sz[e[i].to];}
	if(sz[x]%K==0) return sz[x]=1,1;
	if((sz[x]+1)%K==0) return sz[x]=0,1;
	return 0;
}
inline void solve()
{
	read(n),et=0;for(int i=1;i<=n;i++) head[i]=0,rs[i]=0;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	rs[1]=ksm(2,n-1);for(auto x:v[n-1]) rs[x]=chk(1,0,x);
	//for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
	{
		int s=0;for(int j=i;j<=n;j+=i) s+=rs[j]*mu[j/i];
		printf("%d%c",(s+P)%P,i==n?'\n':' ');
	}
}
int main() {int Ca;for(init(),read(Ca);Ca--;) solve();return 0;}