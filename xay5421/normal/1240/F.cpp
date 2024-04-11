#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=105,M=2005;
mt19937 rng(114514);
vector<int>G[N];
int n,m,K,w[N],deg[N],col[M],cnt[M],uu[M],vv[M],wd,c1,c2;
int pp,lnk[N],nxt[M*2],to[M*2],we[M*2];
bool pd[M*2];
void ae(int k1,int k2,int k3){
	//D("oh %d %d %d\n",k1,k2,k3);
	to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],pd[pp/2]=0,lnk[k1]=pp;
}
void euler(int k1){
	if(!lnk[k1])return;
	for(int&i=lnk[k1];i;i=nxt[i])if(!pd[i/2]){
		int tem=i;
		pd[tem/2]=1;
		euler(to[tem]);
		col[we[tem]]=(wd^=1)&1?c1:c2;
	}
}
void clip(int c1,int c2){
	D("clip %d %d\n",c1,c2);
	::c1=c1,::c2=c2;
	pp=1;
	rep(i,1,n)lnk[i]=0,deg[i]=0;
	rep(i,1,m){
		if(col[i]==c1||col[i]==c2){
			ae(uu[i],vv[i],i);
			ae(vv[i],uu[i],i);
			++deg[uu[i]],++deg[vv[i]];
			col[i]=0;
		}
	}
	int lst=0;
	rep(i,1,n){
		if(deg[i]&1){
			if(lst)ae(i,lst,0),ae(lst,i,0),lst=0;
			else lst=i;
		}
	}
	wd=0;
	rep(i,1,n)if(lnk[i])
		euler(i);
	rep(i,1,m)assert(col[i]>0);
	rep(i,1,n)assert(lnk[i]==0);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		G[k1].PB(i),G[k2].PB(i);
		uu[i]=k1,vv[i]=k2;
		col[i]=rng()%K+1;
		//col[i]=1;
	}
	while(1){
		bool flg=0;
		rep(k1,1,n){
			rep(i,1,K)cnt[i]=0;
			for(auto j:G[k1]){
				++cnt[col[j]];
			}
			int mn=min_element(cnt+1,cnt+1+K)-cnt;
			int mx=max_element(cnt+1,cnt+1+K)-cnt;
			if(cnt[mn]+2<cnt[mx]){
				clip(mn,mx);
				flg=1;
				break;
			}
		}
		if(!flg)break;
	}
	rep(i,1,m){
		printf("%d\n",col[i]);
	}
	return 0;
}