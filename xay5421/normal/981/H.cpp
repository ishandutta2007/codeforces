#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,  k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005,INF=0X3F3F3F3F;
int n,K,fac[N],inv[N],ifac[N],sz[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int A(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k1-k2]);
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],mu(ifac[k2],ifac[k1-k2]));
}
int getlim(int x){
	int y=1;
	while(y<=x)y<<=1;
	return y;
}
void NTT(vector<int>&a,int g,int lim){
	a.resize(lim);
	for(int i=0,j=0;i<lim;++i){
		if(i<j)swap(a[i],a[j]);
		for(int k=(lim>>1);(j^=k)<k;k>>=1);
	}
	vector<int>w(lim>>1);
	w[0]=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=1,wn=po(g,(P-1)/(i<<1));j<i;++j)w[j]=mu(w[j-1],wn);
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				int x=a[j+k],y=mu(a[i+j+k],w[k]);
				a[j+k]=ad(x,y),a[i+j+k]=su(x,y);
			}
		}
	}
	if(g!=3){
		int t=po(lim,P-2);
		rep(i,0,lim-1)a[i]=mu(a[i],t);
	}
}
vector<int>pmu(vector<int>a,vector<int>b,int nd=INF){
	nd=min(nd,SZ(a)+SZ(b)-1);
	int lim=getlim(nd);
	NTT(a,3,lim),NTT(b,3,lim);
	rep(i,0,SZ(a)-1)a[i]=mu(a[i],b[i]);
	NTT(a,332748118,lim);
	return a.resize(nd),a;
}
vector<int>pad(vector<int>a,vector<int>b){
	if(SZ(a)<SZ(b))swap(a,b);
	rep(i,0,SZ(a)-1)a[i]=ad(a[i],b[i]);
	return a;
}
int f[N],sumf[N],cur;
namespace DC{
	vector<int>F[20],G[20];
	vector<int>A,B;
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			F[k1]={1,A[k2]};
			G[k1]={sumf[B[k2]],mu(sumf[B[k2]],n-sz[cur])};
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1+1,k2,mid);
		F[k1]=F[k1+1];
		G[k1]=G[k1+1];
		bud(k1+1,mid+1,k3);
		G[k1]=pad(pmu(F[k1],G[k1+1]),pmu(F[k1+1],G[k1]));
		F[k1]=pmu(F[k1],F[k1+1]);
	}
}
int ans,co1,co2;
void dfs(int k1,int k2){
	sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs(to[i],k1);
	}
	DC::A.clear();
	DC::B.clear();
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		sz[k1]+=sz[to[i]];
		sumf[k1]=ad(sumf[k1],sumf[to[i]]);
		DC::A.PB(sz[to[i]]);
		DC::B.PB(to[i]);
	}
	if(!SZ(DC::A))DC::A.PB(0),DC::B.PB(0);
	if(SZ(DC::A))
		cur=k1,DC::bud(0,0,SZ(DC::A)-1);
	int len=min(K,SZ(DC::F[0])-1);
	rep(i,0,len){
		f[k1]=ad(f[k1],mu(A(K,i),DC::F[0][i]));
	}
	ans=su(ans,mu(f[k1],sumf[k1]));
	co1=ad(co1,f[k1]);
	co2=ad(co2,mu(f[k1],f[k1]));
	sumf[k1]=ad(sumf[k1],f[k1]);
	rep(i,0,len){
		ans=ad(ans,mu(A(K,i),DC::G[0][i]));
	}
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%d",&n,&K);
	if(K==1){
		printf("%d\n",mu(mu(n,n-1),(P+1)>>1));
		return 0;
	}
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs(1,0);
	int rest=mu(su(mu(co1,co1),co2),(P+1)>>1);
	ans=ad(ans,rest);
	printf("%d\n",ans);
	return 0;
}