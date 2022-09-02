#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005,bs=998244853,P=1000000009,INF=0X3F3F3F3F;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int n,a[N],h[N],pw[N],pws[N],id[N],rk[N];
int get(int l,int r){
	//D("get(%d,%d)=%d\n",l,r,su(su(h[r],mu(h[l-1],pw[r-l+1])),mu(a[l],pws[r-l])));
	return su(su(h[r],mu(h[l-1],pw[r-l+1])),mu(a[l],pws[r-l]));
}
int get2(int l,int r){
	return su(0,get(l,r));
}
int lcp2(int k1,int k2,int r){
	int l=1,res=0;
	r=min(r,n-k2+1);
	while(l<=r){
		int mid=(l+r)>>1;
		if(get2(k1,k1+mid-1)==get(k2,k2+mid-1))res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
int getL(int k1,int len){
	int l=1,r=n,res=n+1;
	while(l<=r){
		int mid=(l+r)>>1;
		int t=lcp2(k1,id[mid],len-1);
		if(a[k1]-a[k1+t]<=a[id[mid]+t]-a[id[mid]]){
			r=mid-1,res=mid;
		}else l=mid+1;
	}
	return res;
}
int getR(int k1,int len){
	int l=1,r=n,res=n+1;
	while(l<=r){
		int mid=(l+r)>>1;
		int t=lcp2(k1,id[mid],len-1);
		if(a[k1]-a[k1+t]<a[id[mid]+t]-a[id[mid]]){
			r=mid-1;
		}else l=mid+1,res=mid;
	}
	return res;
}
const int M=N*40;
int ind,rt[N],lc[M],rc[M],sz[M];
void ins(int&k1,int k2,int l,int r,int x){
	k1=++ind;
	sz[k1]=sz[k2]+1,lc[k1]=lc[k2],rc[k1]=rc[k2];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)ins(lc[k1],lc[k2],l,mid,x);else ins(rc[k1],rc[k2],mid+1,r,x);
}
int qry(int k1,int k2,int l,int r,int lx,int rx){
	if(l>rx||r<lx)return 0;
	if(!k1&&!k2)return 0;
	if(lx<=l&&r<=rx){
		return sz[k1]-sz[k2];
	}
	int mid=(l+r)>>1;
	return qry(lc[k1],lc[k2],l,mid,lx,rx)+qry(rc[k1],rc[k2],mid+1,r,lx,rx);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=pws[0]=1;
	rep(i,1,N-1)pw[i]=mu(pw[i-1],bs),pws[i]=ad(pws[i-1],pw[i]);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),h[i]=ad(mu(h[i-1],bs),a[i]),id[i]=i;
	a[n+1]=~INF;
	sort(id+1,id+1+n,[&](int k1,int k2)->bool{
		int l=1,r=n-max(k1,k2)+1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(get(k1,k1+mid-1)==get(k2,k2+mid-1))res=mid,l=mid+1;
			else r=mid-1;
		}
		return a[k1+res]-a[k1]<a[k2+res]-a[k2];
	});
	rep(i,1,n)rk[id[i]]=i;
	rep(i,1,n)ins(rt[i],rt[i-1],1,n,id[i]);
	int Q;
	scanf("%d",&Q);
	rep(_,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		int len=r-l+1;
		int L=getL(l,len);
		int R=getR(l,len);
		printf("%d\n",R-L+1-qry(rt[R],rt[L-1],1,n,max(1,l-len+1),r));
	}
	return 0;
}