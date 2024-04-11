#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int K,Q;
unsigned ll[N],rr[N],vv[N];
struct ds{
	unsigned a[(1<<16)+5],tg[(1<<18)+5],sum[(1<<18)+5];
	void or_(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			tg[k1]|=k6;
			return;
		}
		int mid=(k2+k3)>>1;
		or_(k1*2,k2,mid,k4,k5,k6),or_(k1*2+1,mid+1,k3,k4,k5,k6);
	}
	void upd(int k1){
		sum[k1]=sum[k1*2]|sum[k1*2+1];
	}
	void down(int k1,int k2,int k3,int k4){
		k4|=tg[k1];
		if(k2==k3){
			a[k2]=k4;
			sum[k1]=k4;
			return;
		}
		int mid=(k2+k3)>>1;
		down(k1*2,k2,mid,k4),down(k1*2+1,mid+1,k3,k4);
		upd(k1);
	}
	int ask(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return 0;
		if(k4<=k2&&k3<=k5){
			return sum[k1];
		}
		int mid=(k2+k3)>>1;
		return ask(k1*2,k2,mid,k4,k5)|ask(k1*2+1,mid+1,k3,k4,k5);
	}
}high,low;
int main(){
	scanf("%d%d",&K,&Q);
	rep(i,1,Q){
		unsigned l,r,v;
		scanf("%u%u%u",&l,&r,&v);
		ll[i]=l,rr[i]=r,vv[i]=v;
		high.or_(1,0,(1<<K)-1,l>>K,r>>K,v);
		int l_=l&((1<<K)-1);
		int r_=r&((1<<K)-1);
		if((l>>K)==(r>>K)){
			low.or_(1,0,(1<<K)-1,l_,r_,v);
		}else if((l>>K)+1==(r>>K)){
			if(l_<=r_){
				low.or_(1,0,(1<<K)-1,0,(1<<K)-1,v);
			}else{
				low.or_(1,0,(1<<K)-1,l_,(1<<K)-1,v);
				low.or_(1,0,(1<<K)-1,0,r_,v);
			}
		}else{
			low.or_(1,0,(1<<K)-1,0,(1<<K)-1,v);
		}
	}
	high.down(1,0,(1<<K)-1,0);
	low.down(1,0,(1<<K)-1,0);
	rep(i,1,Q){
		unsigned l=ll[i],r=rr[i],v=vv[i];
		int l_=l&((1<<K)-1);
		int r_=r&((1<<K)-1);
		if((l>>K)==(r>>K)){
			if((high.a[l>>K]&low.ask(1,0,(1<<K)-1,l_,r_))!=v){
				puts("impossible"),exit(0);
			}
		}else{
			if((l>>K)+1<=(r>>K)-1){
				if((high.ask(1,0,(1<<K)-1,(l>>K)+1,(r>>K)-1)&low.sum[1])!=v){
					puts("impossible"),exit(0);
				}
			}
			if((high.a[l>>K]&low.ask(1,0,(1<<K)-1,l_,(1<<K)-1))!=v){
				puts("impossible"),exit(0);
			}
			if((high.a[r>>K]&low.ask(1,0,(1<<K)-1,0,r_))!=v){
				puts("impossible"),exit(0);
			}
		}
	}
	puts("possible");
	rep(i,0,(1<<K)-1)printf("%d\n",low.a[i]);
	rep(i,0,(1<<K)-1)printf("%d\n",high.a[i]);
	return 0;
}