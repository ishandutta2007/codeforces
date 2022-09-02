#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,m,dis[N],baba[N];
int pp,lnk[N],nxt[N],to[N],we[N];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
struct ff{
	int l,r;
	bool operator<(const ff&k)const{return l<k.l;}
	// solve sth in [l,r]
};
vector<ff>v;
struct LCT{
	int fa[N],ch[N][2],mn[N],tim[N],tg[N],st[N],top;
	int isrt(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
	int get(int k1){return ch[fa[k1]][1]==k1;}
	void upd(int k1){
		if(ch[k1][0])mn[k1]=mn[ch[k1][0]];
		else mn[k1]=k1;
	}
	void pst(int k1,int k2){
		if(k1)tg[k1]=tim[k1]=k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(ch[k1][0],tg[k1]);
			pst(ch[k1][1],tg[k1]);
			tg[k1]=0;
		}
	}
	void rotate(int k1){
		int k2=fa[k1],x=get(k1);
		if(!isrt(k2))ch[fa[k2]][get(k2)]=k1;
		fa[k1]=fa[k2];
		fa[ch[k2][x]=ch[k1][x^1]]=k2;
		fa[ch[k1][x^1]=k2]=k1;
		upd(k2),upd(k1);
	}
	void splay(int k1){
		//D("splay %d\n",k1);
		st[top=1]=k1;
		for(int i=k1;!isrt(i);i=fa[i])st[++top]=fa[i];
		per(i,top,1)psd(st[i]);
		for(;!isrt(k1);rotate(k1))if(!isrt(fa[k1]))rotate(get(k1)==get(fa[k1])?fa[k1]:k1);
	}
	void access(int k1,int t){
		int i;
		int cnt=0;
		splay(k1);
		int k=k1,tem=ch[k][1];
		for(i=0;k1;i=k1,k1=fa[k1]){
			splay(k1);
			int k2=mn[k1];
			if(k2!=1){
				++cnt;
				splay(baba[k2]);
				v.PB((ff){tim[baba[k2]]+dis[baba[k2]]+1,t+dis[baba[k2]]});
			}
			ch[k1][1]=i;
			upd(k1);
		}
		splay(k);
		if(ch[k][0])pst(ch[k][0],t);
		ch[k][1]=tem;
		//D("wow %d\n",cnt);
	}
}A;
void dfs(int k1,int k2){
	//D("oh %d %d\n",k1,k2);
	A.fa[k1]=k2,baba[k1]=k2,A.tim[k1]=-dis[k1];
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dis[to[i]]=dis[k1]+we[i];
		dfs(to[i],k1);
	}
	if(lnk[k1]){
		A.ch[k1][1]=to[lnk[k1]];
	}
	A.upd(k1);
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%lld%lld",&n,&m);
	rep(i,1,n-1){
		int k1,k2,k3;
		scanf("%lld%lld%lld",&k1,&k2,&k3);
		ae(k1,k2,k3);
	}
	dfs(1,0);
	rep(i,1,m){
		int k1,k2;
		scanf("%lld%lld",&k1,&k2);
		A.access(k1,k2);
	}
	sort(v.begin(),v.end());
	int j=0;
	priority_queue<int,vector<int>,greater<int> >q;
	int ans=0;
	for(int i=1;j<SZ(v)||SZ(q);++i){
		if(SZ(q)==0){
			i=v[j].l;
		}
		while(j<SZ(v)&&v[j].l==i){
			q.push(v[j].r);
			++j;
		}
		if(SZ(q)){
			auto ddl=q.top();
			if(i>ddl){
				int tot=0;
				rep(j,0,SZ(v)-1)if(v[j].r<i-1)++tot;
				printf("%lld %lld\n",i-1,tot);
				exit(0);
			}
			++ans;
			q.pop();
		}
	}
	printf("%lld %lld\n",-1LL,ans);
	return 0;
}