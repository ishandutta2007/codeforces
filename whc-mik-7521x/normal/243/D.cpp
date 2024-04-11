#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1e7,S=1e8;
int n,X,Y,ct;
struct node{
	int k,l,r,v;
	bool operator<(const node b) const{
		return k<b.k;
	}
}a[N*N];
void add(int x,int y,int c){
	int k=1e8,l=1e8,r=-1e8;
	for(int i=x-1;i<=x;i++){
		for(int o=y-1;o<=y;o++){
			k=min(k,X*i+Y*o);
			l=min(l,Y*i-X*o);
			r=max(r,Y*i-X*o);
		}
    }
    ct++;
	a[ct]=(node){k,l,r-1,c};
}
struct seg{
	int ls[M],rs[M],s[M],tag[M];
	void pushup(int rt){s[rt]=max(tag[rt],min(s[ls[rt]],s[rs[rt]]));}
	void upd(int &rt,int l,int r,int L,int R,int v){
		if(!rt)rt=++ct;
		if(L<=l&&r<=R)return s[rt]=max(s[rt],v),tag[rt]=max(tag[rt],v),void();
		int mid=(l+r)>>1;
		if(L<=mid)upd(ls[rt],l,mid,L,R,v);
		if(R>mid)upd(rs[rt],mid+1,r,L,R,v);
		pushup(rt);
	}
	int ask(int rt,int l,int r,int L,int R){
		if(!rt)return 0;
		if(L<=l&&r<=R)return s[rt];
		int mid=(l+r)>>1,res=1e9;
		if(L<=mid)res=min(res,ask(ls[rt],l,mid,L,R));
		if(R>mid)res=min(res,ask(rs[rt],mid+1,r,L,R));
		return max(tag[rt],res);
	}
}sgt;
int main(){
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
            add(i,j,x);
        }
    }
	stable_sort(a+1,a+n*n+1);
    ct=1;
	long long ans=0;
    int rt=0;
	for(int i=1;i<=n*n;i++){
		int res=sgt.ask(rt,1,S<<1,a[i].l+S,a[i].r+S);
		ans+=max(0,a[i].v-res);
		sgt.upd(rt,1,S<<1,a[i].l+S,a[i].r+S,a[i].v);
	}
	printf("%lld",ans);
	return 0;
}