// author: xay5421
// created: Sun Feb 28 10:02:54 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=0X3F3F3F3F;
const int N=200005;
int n,K=8,q[N],he,ta,dis[N],deg[N],id[N];
char s[N];
LL ans[N];
ULL b[N];
vector<int>e0[N],e1[N],e[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%s",&n,s+1);
	rep(i,1,n){
		int x=s[i]-'a'+1;
		e0[i].push_back(n+x),e1[n+x].push_back(i);
	}
	rep(i,1,n-1){
		int k1=i,k2=i+1;
		scanf("%d%d",&k1,&k2);
		e1[k1].push_back(k2),e1[k2].push_back(k1);
	}
	memset(id,-1,sizeof(id));
	rep(i,1,K){
		he=0,ta=0;
		q[++ta]=i+n;
		fill(dis+1,dis+1+n+K,K*2+1);
		dis[i+n]=1;
		while(he!=ta){
			int k1=q[++he];
			for(int x:e0[k1])if(dis[k1]<dis[x])dis[x]=dis[k1],q[he--]=x;
			for(int x:e1[k1])if(dis[k1]+1<dis[x])dis[x]=dis[k1]+1,q[++ta]=x;
		}
		rep(k1,1,n+K)e[k1].clear(),deg[k1]=0;
		rep(k1,1,n+K){
			for(int x:e0[k1])if(dis[k1]==dis[x])e[k1].push_back(x),++deg[x];
			for(int x:e1[k1])if(dis[k1]+1==dis[x])e[k1].push_back(x),++deg[x];
		}
		he=0,ta=0;
		for(int x:e[i+n]){
			assert(!--deg[x]);
			q[++ta]=x;
			id[x]=ta-1;
		}
		vector<pair<int,int> >t;
		while(he!=ta){
			int k1=q[++he];
			for(int x:e[k1]){
				t.emplace_back(x,k1);
				if(!--deg[x]){
					q[++ta]=x;
				}
			}
		}
		for(int l=0;l<SZ(e1[i+n]);l+=64){
			int r=min(SZ(e1[i+n])-1,l+63),sz=r-l+1;
			rep(k1,1,n+K)b[k1]=0;
			rep(j,l,r)b[e1[i+n][j]]|=1ULL<<(j-l);
			for(auto x:t){
				b[x.first]|=b[x.second];
			}
			rep(k1,1,n){
				int t=__builtin_popcountll(b[k1]);
				ans[dis[k1]]+=sz-t;
				ans[dis[k1]-1]+=t;
			}
		}
		for(int x:e[i+n])id[x]=-1;
		/*D("i=%d\n",i);
		rep(k1,1,K*2+1)D("%lld ",ans[k1]);
		D("\n");*/
	}
	ans[1]=0;
	int res=K*2+1;
	while(!ans[res])--res;
	printf("%d %lld\n",res-1,ans[res]/2);
	return 0;
}