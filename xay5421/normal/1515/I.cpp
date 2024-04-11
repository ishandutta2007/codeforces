// author: xay5421
// created: Mon May  3 17:34:21 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=200005;
int n,Q,_w[N],_v[N],id[N],_id[N];
LL _a[N],sw0[N*4][18],sv0[N*4][18],sw1[N*4][18];
void bud(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k2==k3){
		rep(k,1,17){
			if(_w[id[k2]]<(1<<k)){
				sw0[k1][k]=_a[id[k2]]*_w[id[k2]];
				sv0[k1][k]=_a[id[k2]]*_v[id[k2]];
			}
			sw1[k1][k]=INFLL;
			if(_w[id[k2]]>=(1<<(k-1))&&_w[id[k2]]<(1<<k)&&_a[id[k2]]){
				sw1[k1][k]=_w[id[k2]];
			}
		}
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid,k4,k5),bud(k1*2+1,mid+1,k3,k4,k5);
	rep(k,1,17){
		sw0[k1][k]=sw0[k1*2][k]+sw0[k1*2+1][k];
		sv0[k1][k]=sv0[k1*2][k]+sv0[k1*2+1][k];
		if(sw1[k1*2][k]<sw0[k1*2][k-1]+sw1[k1*2+1][k]){
			sw1[k1][k]=sw1[k1*2][k];
		}else{
			sw1[k1][k]=sw0[k1*2][k-1]+sw1[k1*2+1][k];
		}
	}
}
void add(int x,int y){
	_a[x]+=y;
	bud(1,1,n,_id[x],_id[x]);
}
LL rem,vv; int _k;
void clip(){
	while(_k>0&&(1<<(_k-1))>rem)--_k;
}
void qry(int k1,int k2,int k3){
	if(k2==k3){
		LL tt=min(_a[id[k2]],rem/_w[id[k2]]);
		rem-=tt*_w[id[k2]];
		vv+=tt*_v[id[k2]];
		return;
	}
	int mid=(k2+k3)>>1;
	clip();
	if(sw0[k1][_k]<=rem){
		rem-=sw0[k1][_k];
		vv+=sv0[k1][_k];
		return;
	}
	if(sw1[k1][_k]>rem&&sw0[k1][_k-1]<=rem){
		rem-=sw0[k1][_k-1];
		vv+=sv0[k1][_k-1];
		return;
	}
	qry(k1*2,k2,mid);
	clip();
	qry(k1*2+1,mid+1,k3);
}
void sol(LL x){
	_k=17,rem=x,vv=0;
	clip();
	qry(1,1,n);
	printf("%lld\n",vv);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n){
		scanf("%lld%d%d",&_a[i],&_w[i],&_v[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,[&](int x,int y){return _v[x]^_v[y]?_v[x]>_v[y]:_w[x]<_w[y];});
	rep(i,1,n)_id[id[i]]=i;
	bud(1,1,n,1,n);
	while(Q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			scanf("%d%d",&x,&y);
			add(y,x);
		}else if(t==2){
			int x,y;
			scanf("%d%d",&x,&y);
			add(y,-x);
		}else{
			LL x;
			scanf("%lld",&x);
			sol(x);
		}
	}
	return 0;
}