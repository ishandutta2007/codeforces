// author: xay5421
// created: Fri Nov  5 21:59:49 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const long double PI=acos(-1);
namespace Module{ // by txc
	using namespace std;
	const int N=400005;
	struct cp{
		double x,y;
		cp operator+(const cp&k)const{return(cp){x+k.x,y+k.y};}
		cp operator-(const cp&k)const{return(cp){x-k.x,y-k.y};}
		cp operator*(const cp&k)const{return(cp){x*k.x-y*k.y,x*k.y+y*k.x};}
	}A[N],B[N];
	void FFT(cp*a,int lim,int op){
		for(int i=0,j=0;i<lim;++i){
			if(i<j)swap(a[i],a[j]);
			for(int k=lim>>1;(j^=k)<k;k>>=1);
		}
		for(int i=1;i<lim;i<<=1){
			cp wn=(cp){(double)cos(PI/i),op*(double)sin(PI/i)};
			for(int j=0;j<lim;j+=i<<1){
				cp w=(cp){1,0};
				for(int k=0;k<i;++k,w=w*wn){
					cp x=a[j+k],y=a[i+j+k]*w;
					a[j+k]=x+y,a[i+j+k]=x-y;
				}
			}
		}
	}
	vector<LL> Prod(const vector<LL> &a, const vector<LL> &b){
		int need=SZ(a)+SZ(b)-1;
		int lim=1;
		while(lim<=need)lim<<=1;
		rep(i,0,lim-1){
			if(i<SZ(a))A[i]=(cp){1.*a[i],0.};else A[i]=(cp){0.,0.};
			if(i<SZ(b))B[i]=(cp){1.*b[i],0.};else B[i]=(cp){0.,0.};
		}
		FFT(A,lim,1),FFT(B,lim,1);
		rep(i,0,lim-1)A[i]=A[i]*B[i];
		FFT(A,lim,-1);
		vector<LL>c(need);
		rep(i,0,need-1){
			c[i]=(LL)(A[i].x/lim+0.5);
		}
		return c;
	}
}
using Module::Prod;
const int N=100005;
int n,m,Q,a[N],b[N];
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	//int L=max(*max_element(a+1,a+1+n),*max_element(b+1,b+1+n));
	const int L=100000;
	vector<LL>V;
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n){
			++f1[a[i]];
		}
		rep(i,1,m){
			++f2[b[i]];
		}
		V=Prod(f1,f2);
		V.resize(200001);
		per(i,200000-1,0)V[i]+=V[i+1];
	}
	vector<LL>E(200001);
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n){
			if(i<n)++f1[min(a[i],a[i+1])];
		}
		rep(i,1,m)++f2[b[i]];
		vector<LL>E1(Prod(f1,f2));
		E1.resize(200001);
		per(i,200000-1,0)E1[i]+=E1[i+1];
		rep(i,1,200000)E[i]-=E1[i];
	}
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n){
			++f1[a[i]];
		}
		rep(i,1,m-1)++f2[min(b[i],b[i+1])];
		vector<LL>E1(Prod(f1,f2));
		E1.resize(200001);
		per(i,200000-1,0)E1[i]+=E1[i+1];
		rep(i,1,200000)E[i]-=E1[i];
	}
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n-1){
			++f1[max(a[i],a[i+1])];
		}
		rep(i,1,m)++f2[b[i]];
		vector<LL>E1(Prod(f1,f2));
		E1.resize(200001);
		rep(i,1,200000)E1[i]+=E1[i-1];
		rep(i,1,200000)E[i]+=E1[i-1];
	}
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n){
			++f1[a[i]];
		}
		rep(i,1,m-1)++f2[max(b[i],b[i+1])];
		vector<LL>E1(Prod(f1,f2));
		E1.resize(200001);
		rep(i,1,200000)E1[i]+=E1[i-1];
		rep(i,1,200000)E[i]+=E1[i-1];
	}
	vector<LL>F(200001);
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n-1){
			++f1[min(a[i],a[i+1])];
		}
		rep(i,1,m-1)++f2[min(b[i],b[i+1])];
		vector<LL>F1(Prod(f1,f2));
		F1.resize(200001);
		per(i,200000-1,0)F1[i]+=F1[i+1];
		rep(i,1,200000)F[i]-=F1[i];
	}
	{
		vector<LL>f1(L+1),f2(L+1);
		rep(i,1,n-1){
			++f1[max(a[i],a[i+1])];
		}
		rep(i,1,m-1)++f2[max(b[i],b[i+1])];
		vector<LL>F1(Prod(f1,f2));
		F1.resize(200001);
		rep(i,1,200000)F1[i]+=F1[i-1];
		rep(i,1,200000)F[i]+=F1[i-1];
	}
	while(Q--){
		int x;
		scanf("%d",&x);
		LL ans=V[x]-(V[0]-V[x]);
		ans+=E[x];
		ans-=F[x];
		printf("%lld\n",ans);
	}
	return 0;
}