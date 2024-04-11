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
const int N=100005,K=20,B=350;
int n,w,Q,ans[N];
struct ff{
	int x,id;
	bool operator<(const ff&k)const{
		return x<k.x;
	}
}q[N];
struct ST{
	int f[N][K],g[N][K],lg[N];
	void set(int i,int x){
		f[i][0]=g[i][0]=x;
	}
	void init(int n){
		rep(i,2,N-1)lg[i]=lg[i>>1]+1;
		rep(j,1,K-1)rep(i,1,n-(1<<j)+1){
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j]=max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
	}
	int ask(int l,int r){
		int x=lg[r-l+1];
		return max(g[l][x],g[r-(1<<x)+1][x])-min(f[l][x],f[r-(1<<x)+1][x]);
	}
	int getgo(int i,int lim){
		int l=i,r=n,res=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(ask(i,mid)>lim)res=mid,r=mid-1;
			else l=mid+1;
		}
		return res;
	}
}st;
struct LCT{
	int fa[N],ch[N][2],sz[N];
	int isrt(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
	int get(int k1){return ch[fa[k1]][1]==k1;}
	void upd(int k1){sz[k1]=sz[ch[k1][0]]+sz[ch[k1][1]]+1;}
	void rotate(int k1){
		int k2=fa[k1],x=get(k1);
		if(!isrt(k2))ch[fa[k2]][get(k2)]=k1;
		fa[k1]=fa[k2];
		fa[ch[k2][x]=ch[k1][x^1]]=k2;
		fa[ch[k1][x^1]=k2]=k1;
		upd(k2),upd(k1);
	}
	void splay(int k1){
		for(;!isrt(k1);rotate(k1))if(!isrt(fa[k1]))rotate(get(k1)==get(fa[k1])?fa[k1]:k1);
	}
	void access(int k1){
		for(int i=0;k1;i=k1,k1=fa[k1]){
			splay(k1);
			ch[k1][1]=i;
			upd(k1);
		}
	}
	int fd(int k1){
		access(k1);
		splay(k1);
		while(ch[k1][0])k1=ch[k1][0];
		return splay(k1),k1;
	}
	void link(int k1,int k2){
		D("link %d %d\n",k1,k2);
		access(k1);
		splay(k1);
		fa[k1]=k2;
	}
	void cut(int k1,int k2){
		D("cut %d %d\n",k1,k2);
		access(k1);
		splay(k1);
		splay(k2);
		assert(fa[k1]==k2);
		assert(ch[k2][1]==k1);
		fa[k1]=ch[k2][1]=0;
	}
}lct;
vector<int>v[N];
int go[N];
int sol(int lim,vector<int>&v){
	for(auto x:v){
		if(go[x])lct.cut(x,go[x]);
		go[x]=st.getgo(x,lim);
		if(go[x]-x<=B){
			lct.link(x,go[x]);
			if(go[x]<=n){
				int num=st.ask(x,go[x]);
				int pos=lower_bound(q+1,q+1+Q,(ff){num,0})-q;
				if(pos<=Q){
					::v[pos].PB(x);
				}
			}
		}
	}
	int res=0;
	for(int k1=1;k1<=n;){
		int k2=lct.fd(k1);
		res+=lct.sz[k2]-1;
		if(k2>n)break;
		k1=st.getgo(k2,lim);
		++res;
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&w,&Q);
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		st.set(i,x);
	}
	st.init(n);
	rep(i,1,Q)scanf("%d",&q[i].x),q[i].x=w-q[i].x,q[i].id=i;
	sort(q+1,q+1+Q);
	rep(i,1,n)v[1].PB(i);
	rep(i,1,Q){
		D("qid=%d\n",i);
		ans[q[i].id]=sol(q[i].x,v[i]);
		vector<int>tem;
		swap(tem,v[i]);
	}
	rep(i,1,Q)printf("%d\n",ans[i]-1);
	return 0;
}