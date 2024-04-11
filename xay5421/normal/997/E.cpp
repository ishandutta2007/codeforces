#include<cstdio>
#include<vector>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
typedef long long ll;const int N=120005;
int n,m,a[N],le[N],st1[N],st2[N],top1,top2;std::vector<int>q[N];ll ans[N];
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
namespace T{
#define lc (u<<1)
#define rc (u<<1|1)
#define ls lc,l,mid
#define rs rc,mid+1,r
	ll res,ans[N<<2];int num[N<<2],min[N<<2],tag[N<<2],tim[N<<2];
	void addtag(int u,int x){tag[u]+=x,min[u]+=x;}
	void addtim(int u,int x){tim[u]+=x,ans[u]+=1ll*num[u]*x;}
	void upd(int u){min[u]=::min(min[lc],min[rc]),ans[u]=ans[lc]+ans[rc],num[u]=(min[lc]==min[u]?num[lc]:0)+(min[rc]==min[u]?num[rc]:0);}
	void psd(int u){
		debug("?");
		if(tag[u])addtag(lc,tag[u]),addtag(rc,tag[u]),tag[u]=0;
		if(tim[u])min[lc]==min[u]?addtim(lc,tim[u]):((void)0),min[rc]==min[u]?addtim(rc,tim[u]):((void)0),tim[u]=0;
	}
	void bud(int u,int l,int r){
		debug("&");
		if(l==r)return num[u]=1,min[u]=-1,void();int mid=(l+r)>>1;
		bud(ls),bud(rs);upd(u);
	}
	void mdf(int u,int l,int r,int lx,int rx,int x){
		debug("!");
		if(l==lx&&r==rx)return addtag(u,x),void();psd(u);int mid=(l+r)>>1;
		if(rx<=mid)mdf(ls,lx,rx,x);else if(mid<lx)mdf(rs,lx,rx,x);else mdf(ls,lx,mid,x),mdf(rs,mid+1,rx,x);upd(u);
	}
	void mdf2(int u,int l,int r,int lx,int rx){
		debug("#");
		if(l==lx&&r==rx)return min[u]==-1?addtim(u,1):((void)0),void();psd(u);int mid=(l+r)>>1;
		if(rx<=mid)mdf2(ls,lx,rx);else if(mid<lx)mdf2(rs,lx,rx);else mdf2(ls,lx,mid),mdf2(rs,mid+1,rx);upd(u);
	}
	void qry(int u,int l,int r,int lx,int rx){
		debug("*");
		debug("%d %d %d %d %d\n",u,l,r,lx,rx);
		if(l==lx&&r==rx)return res+=ans[u],void();psd(u);int mid=(l+r)>>1;
		if(rx<=mid)qry(ls,lx,rx);else if(mid<lx)qry(rs,lx,rx);else qry(ls,lx,mid),qry(rs,mid+1,rx);upd(u);
	}
	void output(int u=1,int l=1,int r=n){
		if(l==r)return debug("%d^",min[u]),void();psd(u);int mid=l+r>>1;
		output(ls),output(rs);upd(u);
	}
#undef lc
#undef rc
#undef ls
#undef rs
};

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	scanf("%d",&m);
	rep(i,1,m){int l,r;scanf("%d%d",&l,&r),q[r].push_back(i),le[i]=l;}
	T::bud(1,1,n);
	rep(i,1,n){
		while(top1&&a[st1[top1]]<a[i]){
			debug("update:%d %d\n",st1[top1],i);
			T::mdf(1,1,n,st1[top1-1]+1,st1[top1],a[i]-a[st1[top1]]),--top1;
		}
		st1[++top1]=i;
		while(top2&&a[st2[top2]]>a[i])T::mdf(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]-a[i]),--top2;st2[++top2]=i;
		debug("233\n");
		T::mdf2(1,1,n,1,i);
//		T::output(1,1,n);
		rep(j,0,(int)q[i].size()-1){
			int x=q[i][j];
			T::res=0;
			T::qry(1,1,n,le[x],i);
			ans[x]=T::res;
		}
		T::mdf(1,1,n,1,i,-1);
	}
	rep(i,1,m)printf("%I64d\n",ans[i]);
	return 0;
}