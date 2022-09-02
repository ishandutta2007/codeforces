#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=100005,INF=0X3F3F3F3F;
int n,m,Q,L[N],ans[N];
vector<tuple<int,int> >qs[N];
struct segTreeBeats{
	int mx[N*4],mx_[N*4];
	void upd(int k1){
		if(mx[k1*2]==mx[k1*2+1]){
			mx[k1]=mx[k1*2];
			mx_[k1]=max(mx_[k1*2],mx_[k1*2+1]);
		}else if(mx[k1*2]<mx[k1*2+1]){
			mx[k1]=mx[k1*2+1];
			mx_[k1]=max(mx[k1*2],mx_[k1*2+1]);
		}else{
			mx[k1]=mx[k1*2];
			mx_[k1]=max(mx[k1*2+1],mx_[k1*2]);
		}
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			mx[k1]=k2,mx_[k1]=~INF;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void psd(int k1){
		int t=max(mx[k1*2],mx[k1*2+1]);
		if(mx[k1*2]==t)umax(mx[k1*2],mx[k1]);
		if(mx[k1*2+1]==t)umax(mx[k1*2+1],mx[k1]);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			if(mx[k1]<k6)return;
			if(mx_[k1]<k6){
				mx[k1]=k7;
				return;
			}
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6,k7),mdf(k1*2+1,mid+1,k3,k4,k5,k6,k7);
		upd(k1);
	}
	int ask(int k1,int k2,int k3,int k4){
		if(k2==k3){
			return mx[k1];
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		if(k4<=mid)return ask(k1*2,k2,mid,k4);
		else return ask(k1*2+1,mid+1,k3,k4);
	}
}tr;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int l,r;
		scanf("%d%d",&l,&r);
		L[r]=l;
	}
	scanf("%d",&Q);
	rep(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		qs[r].eb(l,i);
	}
	tr.bud(1,1,n);
	rep(i,1,n){
		if(L[i]>0){
			tr.mdf(1,1,n,1,L[i],L[i],i);
		}
		for(auto&_:qs[i]){
			int l,id;
			tie(l,id)=_;
			ans[id]=tr.ask(1,1,n,l);
		}
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}