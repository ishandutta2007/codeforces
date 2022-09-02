#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=50005;
int n,m,K;
LL ans[N];
struct ff{
	int a,b,c,d;
}A[N];
struct gg{
	int x,l,r,w;
	bool operator<(const gg&k)const{return x<k.x;}
}B[N*2];
vector<int>v;
namespace SGT{
	int tg[N*8],sum[N*8];
	void upd(int k1,int k2,int k3){
		if(tg[k1]){
			sum[k1]=v[k3]-v[k2-1];
		}
		else{
			if(k2!=k3)sum[k1]=sum[k1*2]+sum[k1*2+1];
			else sum[k1]=0;
		}
	}
	void bud(int k1,int k2,int k3){
		tg[k1]=0,sum[k1]=0;
		if(k2==k3){
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1,k2,k3);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			tg[k1]+=k6;
			upd(k1,k2,k3);
			return;
		}
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1,k2,k3);
	}
}
LL sol(int len){
	int cnt=0;
	rep(i,1,m){
		int a=(A[i].a+len-1)/len;
		int c=A[i].c/len;
		int b=(A[i].b+len-1)/len;
		int d=A[i].d/len;
		//D("(%d %d %d %d)\n",a,b,c,d);
		B[++cnt]=(gg){a,b,d,1};
		B[++cnt]=(gg){c+1,b,d,-1};
	}
	auto get=[&](int x){
		return lower_bound(v.begin(),v.end(),x)-v.begin();
	};
	{
		v.clear();
		rep(i,1,cnt)v.PB(B[i].l-1),v.PB(B[i].r);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		rep(i,1,cnt)B[i].l=get(B[i].l),B[i].r=get(B[i].r);
	}
	sort(B+1,B+1+cnt);
	SGT::bud(1,0,SZ(v)-1);
	LL res=0;
	for(int i=1,j;i<=cnt;i=j){
		j=i;
		res+=1LL*(B[i].x-B[i-1].x)*SGT::sum[1];
		while(j<=cnt&&B[i].x==B[j].x){
			//D(">>> %d %d %d\n",B[j].l,B[j].r,B[j].w);
			SGT::mdf(1,0,SZ(v)-1,B[j].l,B[j].r,B[j].w);
			++j;
		}
	}
	//D(">>> len=%d res=%lld\n",len,res);
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,m){
		scanf("%d%d%d%d",&A[i].a,&A[i].b,&A[i].c,&A[i].d);
	}
	rep(i,0,30){
		if((1<<i)>K)break;
		ans[i]=sol(1<<i);
	}
	rep(i,0,30){
		if((1<<i)>K)break;
		if((ans[i]-ans[i+1])&1){
			puts("Hamed");
			exit(0);
		}
	}
	puts("Malek");
	return 0;
}