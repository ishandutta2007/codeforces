// author: xay5421
// created: Wed Nov 10 11:06:35 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,INF=0X3F3F3F3F;
int n,m,ord[N];
vector<int>e[N];
struct ETT{
	int ch[N][2],fa[N],dep[N],tg[N],sz[N];
	pair<int,int>mn[N],mx[N];
	ETT(){
		mn[0]={INF,INF};
		mx[0]={~INF,~INF};
	}
	int get(int x){return ch[fa[x]][1]==x;}
	void pst(int k1,int k2){
		if(k1)tg[k1]+=k2,dep[k1]+=k2,mn[k1].first+=k2,mx[k1].first+=k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(ch[k1][0],tg[k1]);
			pst(ch[k1][1],tg[k1]);
			tg[k1]=0;
		}
	}
	void upd(int k1){
		sz[k1]=1+sz[ch[k1][0]]+sz[ch[k1][1]];
		mn[k1]=mx[k1]={dep[k1],k1};
		mn[k1]=min(mn[k1],min(mn[ch[k1][0]],mn[ch[k1][1]]));
		mx[k1]=max(mx[k1],max(mx[ch[k1][0]],mx[ch[k1][1]]));
	}
	void rotate(int k1){
		int k2=fa[k1],x=get(k1);
		if(fa[k2])ch[fa[k2]][get(k2)]=k1;
		fa[k1]=fa[k2];
		if(ch[k2][x]=ch[k1][x^1]){
			fa[ch[k2][x]]=k2;
		}
		ch[k1][x^1]=k2,fa[k2]=k1;
		upd(k2),upd(k1);
	}
	int st[N],top;
	void splay(int k1,int k2=0){
		top=0;
		for(int i=k1;i;i=fa[i])st[++top]=i;
		per(i,top,1)psd(st[i]);
		for(;fa[k1]!=k2;rotate(k1))if(fa[fa[k1]]!=k2)rotate(get(k1)==get(fa[k1])?fa[k1]:k1);
	}
	int bud(int l,int r){
		if(l>r)return 0;
		int mid=(l+r)>>1,u=ord[mid];
		ch[u][0]=bud(l,mid-1),fa[ch[u][0]]=u;
		ch[u][1]=bud(mid+1,r),fa[ch[u][1]]=u;
		upd(u);
		return u;
	}
	int rank(int u){
		splay(u);
		return sz[ch[u][0]]+1;
	}
	void split(int u,int v){
		splay(u);
		splay(v,u);
	}
	int ask3(int k1,int k){
		if(mx[k1].first<k||mn[k1].first>k)return -1;
		psd(k1);
		{
			int tmp=ask3(ch[k1][1],k);
			if(tmp!=-1)return tmp;
		}
		if(dep[k1]==k)return k1/2;
		return ask3(ch[k1][0],k);
	}
	int prev(int u){
		splay(u);
		assert(ch[u][0]);
		u=ch[u][0];
		while(psd(u),ch[u][1])u=ch[u][1];
		splay(u);
		return u;
	}
	int next(int u){
		splay(u);
		assert(ch[u][1]);
		u=ch[u][1];
		while(psd(u),ch[u][0])u=ch[u][0];
		splay(u);
		return u;
	}
}tr;
int ind;
void dfs0(int k1,int k2,int k3){
	ord[++ind]=k1*2,tr.dep[k1*2]=k3;
	for(auto x:e[k1])if(x!=k2){
		dfs0(x,k1,k3+1);
	}
	ord[++ind]=k1*2+1,tr.dep[k1*2+1]=k3;
}
void outs(int u){
	if(u==1)D("S ");
	else if(u==n*2+2)D("T\n");
	else{
		if(u&1){
			D("%d\' ",u/2);
		}else{
			D("%d ",u/2);
		}
	}
}
void out(int u){
	if(!u)return;
	tr.psd(u);
	out(tr.ch[u][0]);
	outs(u);
	out(tr.ch[u][1]);
	tr.upd(u);
}
void debug(int u=-1){
	/*if(u==-1){
		u=1;
		while(tr.fa[u])u=tr.fa[u];
	}
	out(u);*/
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n){
		int sz;
		rd(sz);
		e[i].assign(sz,0);
		rep(j,0,sz-1)rd(e[i][j]);
	}
	ord[++ind]=1;
	dfs0(1,0,0);
	ord[++ind]=n*2+2;
	tr.bud(1,n*2+2);
	rep(_,1,m){
		int opt;
		rd(opt);
		if(opt==1){
			int u,v;
			rd(u),rd(v);
			//if(u==v){puts("0");continue;}
			int rku=tr.rank(u*2);
			int res=tr.dep[u*2];
			int rkv=tr.rank(v*2);
			res+=tr.dep[v*2];
			if(rku>rkv){
				swap(u,v),swap(rku,rkv);
			}
			tr.split(u*2,v*2+1);
			assert(tr.ch[v*2+1][0]!=0);
			//debug();
			res-=(tr.mn[tr.ch[v*2+1][0]].first-1)*2;
			printf("%d\n",res);
		}else if(opt==2){
			int u,h;
			rd(u),rd(h);
			if(!h)continue;
			int a=tr.prev(u*2);
			tr.splay(u*2);
			int tmp=tr.ask3(a,tr.dep[u*2]-h);
			D("link %d to %d\n",u,tmp);
			int b=tr.next(u*2+1);
			tr.split(a,b);
			int cur=tr.ch[b][0];
			tr.fa[cur]=0,tr.ch[b][0]=0;
			tr.upd(b),tr.upd(a);
			tr.pst(cur,-(h-1));
			int pre_tmp=tr.prev(tmp*2+1);
			tr.split(pre_tmp,tmp*2+1);
			assert(!tr.ch[tmp*2+1][0]);
			tr.fa[cur]=tmp*2+1,tr.ch[tmp*2+1][0]=cur;
			tr.upd(tmp*2+1),tr.upd(pre_tmp);
		}else{
			int k;
			rd(k);
			tr.splay(1);
			tr.splay(n*2+2);
			int u=tr.ask3(tr.ch[n*2+2][0],k);
			printf("%d\n",u);
		}
	}
	return 0;
}