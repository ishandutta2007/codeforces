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
const int N=150005,INF=0X3F3F3F3F;
int n,a[N],ia[N];
LL ans[N];
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	void clear(){
		memset(t,0,sizeof(t));
	}
}B;
struct SEG{
	struct ff{
		int v,ct;
		bool operator<(const ff&k)const{return v<k.v;}
		ff operator+(const ff&k)const{
			if(v<k.v)return k;
			if(v>k.v)return*this;
			return (ff){v,ct+k.ct};
		}
	}mx[N*4][2];
	int sz[N*4],tg[N*4];
	LL sum[N*4];
	void pst(int k1,int k2){
		sum[k1]+=1LL*sz[k1]*k2;
		tg[k1]+=k2;
		if(mx[k1][0].ct)mx[k1][0].v+=k2;
		if(mx[k1][1].ct)mx[k1][1].v+=k2;
	}
	void pst2(int k1,int k2){
		if(k2<mx[k1][0].v){
			sum[k1]-=1LL*mx[k1][0].ct*(mx[k1][0].v-k2);
			mx[k1][0].v=k2;
			assert(mx[k1][0].v>mx[k1][1].v);
		}
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
		pst2(k1*2,mx[k1][0].v);
		pst2(k1*2+1,mx[k1][0].v);
	}
	void upd(int k1){
		sum[k1]=sum[k1*2]+sum[k1*2+1];
		mx[k1][0]=mx[k1*2][0]+mx[k1*2+1][0];
		if(mx[k1*2][0].v==mx[k1*2+1][0].v){
			mx[k1][1]=mx[k1*2][1]+mx[k1*2+1][1];
		}else{
			mx[k1][1]=mx[k1*2][1]+mx[k1*2+1][1]+min(mx[k1*2][0],mx[k1*2+1][0]);
		}
	}
	void bud(int k1,int k2,int k3){
		sz[k1]=0,tg[k1]=0,sum[k1]=0,mx[k1][0]=(ff){0,0},mx[k1][1]=(ff){-INF,0};
		if(k2==k3)return;
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	}
	void umin(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4||k6>=mx[k1][0].v)return;
		if(k4<=k2&&k3<=k5&&mx[k1][1].v<k6){
			pst2(k1,k6);
			return;
		}
		int mid=(k2+k3)>>1;
		psd(k1);
		umin(k1*2,k2,mid,k4,k5,k6),umin(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
		if(k2>k5||k3<k4)return;
		sz[k1]+=k7;
		if(k4<=k2&&k3<=k5){
			if(k7){
				mx[k1][0].ct=1;
			}
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6,k7),mdf(k1*2+1,mid+1,k3,k4,k5,k6,k7);
		upd(k1);
	}
}A;
void sol(){
	B.clear();
	rep(i,1,n)ia[a[i]]=i;
	A.bud(1,1,n);
	rep(i,1,n){
		A.umin(1,1,n,1,ia[i],B.qry(ia[i]));
		A.mdf(1,1,n,ia[i],ia[i],i-1,1);
		A.mdf(1,1,n,ia[i],n,1,0);
		ans[i]+=A.sum[1];
		B.upd(ia[i],1);
		//D("ans[%d]=%lld\n",i,ans[i]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sol();
	reverse(a+1,a+1+n);
	sol();
	rep(i,1,n){
		printf("%lld\n",ans[i]-1LL*i*i);
	}
	return 0;
}