// author: xay5421
// created: Tue Jan  5 20:55:25 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int n,p[N],w[N];
int cnt,ch[N*2][2],fa[N*2],sz[N*2];
int get(int x){
	return ch[fa[x]][1]==x;
}
struct FHQ{
	const static int N=::N*30;
	int tot,lc[N],rc[N],val[N],ran[N],sz[N];
	void upd(int k1){sz[k1]=sz[lc[k1]]+sz[rc[k1]]+1;}
	void init(int k1,int k2){val[k1]=k2,ran[k1]=rng()&0X7FFFFFFF,sz[k1]=1;}
	int newnode(int v){
		init(++tot,v);
		return tot;
	}
	int mer(int k1,int k2){
		if(!k1||!k2)return k1+k2;
		if(ran[k1]<ran[k2]){
			rc[k1]=mer(rc[k1],k2);
			upd(k1);
			return k1;
		}else{
			lc[k2]=mer(k1,lc[k2]);
			upd(k2);
			return k2;
		}
	}
	int ask_small(int k1,int k2){
		if(!k1)return 0;
		if(val[k1]<k2){
			return sz[lc[k1]]+1+ask_small(rc[k1],k2);
		}else{
			return ask_small(lc[k1],k2);
		}
	}
	int ask_big(int k1,int k2){
		if(!k1)return 0;
		if(val[k1]>k2){
			return sz[rc[k1]]+1+ask_big(lc[k1],k2);
		}else{
			return ask_big(rc[k1],k2);
		}
	}
	void split_sz(int k1,int k2,int&l,int&r){
		if(!k1){l=0,r=0;return;}
		if(sz[lc[k1]]+1<=k2){
			l=k1;
			split_sz(rc[k1],k2-sz[lc[k1]]-1,rc[k1],r);
			upd(k1);
		}else{
			r=k1;
			split_sz(lc[k1],k2,l,lc[k1]);
			upd(k1);
		}
	}
	void split_v(int k1,int k2,int&l,int&r){
		if(!k1){l=0,r=0;return;}
		if(val[k1]<=k2){
			l=k1;
			split_v(rc[k1],k2,rc[k1],r);
			upd(k1);
		}else{
			r=k1;
			split_v(lc[k1],k2,l,lc[k1]);
			upd(k1);
		}
	}
}t;
int rt[N*2];
LL res[N*2],all[N*2],ans;
int bud(int l,int r){
	int u=l>r?l:++cnt;
	sz[u]=1;
	rep(i,l,r+1){
		int L,R;
		t.split_v(rt[u],p[i],L,R);
		rt[u]=t.mer(L,t.mer(t.newnode(p[i]),R));
		//D("ins rt[%d] %d\n",u,p[i]);
	}
	if(l>r)return u;
	int mid=min_element(w+l,w+1+r)-w;
	fa[ch[u][0]=bud(l,mid-1)]=u;
	fa[ch[u][1]=bud(mid+1,r)]=u;
	sz[u]=sz[ch[u][0]]+sz[ch[u][1]];
	rep(i,l,mid)res[u]+=t.ask_small(rt[ch[u][1]],p[i]);
	all[u]=1LL*sz[ch[u][0]]*sz[ch[u][1]];
	ans+=min(res[u],all[u]-res[u]);
	return u;
}
int buf[N],top;
void del(int k1,int k2){
	int d;
	buf[++top]=rt[k1];
	rt[k1]=0;
	d=get(k1),k1=fa[k1];
	while(k1){
		int l,m,r;
		t.split_v(rt[k1],k2-1,l,m);
		t.split_sz(m,1,m,r);
		assert(t.sz[m]==1);
		buf[++top]=m;
		rt[k1]=t.mer(l,r);
		if(d==0){
			ans-=min(res[k1],all[k1]-res[k1]);
			res[k1]-=t.ask_small(rt[ch[k1][1]],k2);
			ans+=min(res[k1],all[k1]-res[k1]);
		}else{
			ans-=min(res[k1],all[k1]-res[k1]);
			res[k1]-=t.ask_big(rt[ch[k1][0]],k2);
			ans+=min(res[k1],all[k1]-res[k1]);
		}
		d=get(k1),k1=fa[k1];
	}
}
void ins(int k1,int k2){
	rt[k1]=buf[top--];
	t.init(rt[k1],k2);
	int d;
	d=get(k1),k1=fa[k1];
	while(k1){
		int l,m=buf[top--],r;
		t.init(m,k2);
		t.split_v(rt[k1],k2,l,r);
		rt[k1]=t.mer(l,t.mer(m,r));
		if(d==0){
			ans-=min(res[k1],all[k1]-res[k1]);
			res[k1]+=t.ask_small(rt[ch[k1][1]],k2);
			ans+=min(res[k1],all[k1]-res[k1]);
		}else{
			ans-=min(res[k1],all[k1]-res[k1]);
			res[k1]+=t.ask_big(rt[ch[k1][0]],k2);
			ans+=min(res[k1],all[k1]-res[k1]);
		}
		d=get(k1),k1=fa[k1];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n),cnt=n;
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n-1)scanf("%d",&w[i]);
	bud(1,n-1);
	int Q;
	scanf("%d",&Q);
	rep(_,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y){
			printf("%lld\n",ans);
			continue;
		}
		del(x,p[x]);
		del(y,p[y]);
		ins(x,p[y]);
		ins(y,p[x]);
		swap(p[x],p[y]);
		printf("%lld\n",ans);
	}
	return 0;
}