#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#define EB emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005;
int n,len,xl[N],yl[N],xr[N],yr[N];
struct data{
	int x,l,r,id;
	bool operator<(const data&k2)const{return x<k2.x;}
}A[N];
set<int>S[N*4];
int mx[N*4],lim[N*4];
bool ban[N];
void upd(int k1,int isleaf){
	if(isleaf){
		mx[k1]=lim[k1]=0;
	}else{
		mx[k1]=max(mx[k1*2],mx[k1*2+1]);
		lim[k1]=min(lim[k1*2],lim[k1*2+1]);
	}
	if(S[k1].empty())return;
	int now=*--S[k1].end();
	if(ban[now])lim[k1]=max(lim[k1],now);
	else mx[k1]=max(mx[k1],now);
	if(mx[k1]<lim[k1]){
		mx[k1]=0;
	}
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	//D("mdf %d %d %d %d %d %d\n",k1,k2,k3,k4,k5,k6);
	if(k4<=k2&&k3<=k5){
		if(k6>0)S[k1].insert(k6);
		else S[k1].erase(-k6);
		upd(k1,k2==k3);
		return;
	}
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1,0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d%d%d",xl+i,yl+i,xr+i,yr+i);
	auto fun=[&](int*a,int*b){
		vector<int>num;
		rep(i,1,n)num.EB(a[i]),num.EB(b[i]);
		sort(num.begin(),num.end());
		num.erase(unique(num.begin(),num.end()),num.end());
		rep(i,1,n)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
		rep(i,1,n)b[i]=lower_bound(num.begin(),num.end(),b[i])-num.begin();
	};
	fun(xl,xr),fun(yl,yr);
	rep(i,1,n){
		A[++len]=(data){xl[i],yl[i],yr[i],i};
		A[++len]=(data){xr[i]+1,yl[i],yr[i],-i};
	}
	sort(A+1,A+1+len);
	int ans=0;
	for(int l=1,r;l<=len;l=r){
		r=l+1;
		while(A[l].x==A[r].x)++r;
		D("%d %d\n",l,r);
		rep(i,l,r-1)mdf(1,1,n*2,A[i].l,A[i].r,A[i].id);
		while(mx[1]){
			D(">>> %d\n",mx[1]);
			ban[mx[1]]=1,++ans;
			mdf(1,1,n*2,yl[mx[1]],yr[mx[1]],0);
		}
	}
	printf("%d\n",ans+1);
	return 0;
}