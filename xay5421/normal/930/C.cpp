#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=100005;
int n,m,cf[N],f[N],g[N];
struct node{
	int l,r;
}a[N];
struct BIT{
	int t[N];
	void clear(){memset(t,0,sizeof(t));}
	void upd(int k1,int k2){
		++k1;
		for(int i=k1;i<N;i+=i&-i)umax(t[i],k2);
	}
	int qry(int k1){
		++k1;
		int k2=0;
		for(int i=k1;i;i&=i-1)umax(k2,t[i]);
		return k2;
	}
}t;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d%d",&a[i].l,&a[i].r);
		++cf[a[i].l],--cf[a[i].r+1];
	}
	rep(i,1,m){
		cf[i]+=cf[i-1];
	}
	rep(i,1,m){
		f[i]=t.qry(cf[i])+1;
		t.upd(cf[i],f[i]);
	}
	t.clear();
	per(i,m,1){
		g[i]=t.qry(cf[i])+1;
		t.upd(cf[i],g[i]);
	}
	int ans=0;
	rep(i,1,m){
		ans=max(ans,f[i]+g[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}