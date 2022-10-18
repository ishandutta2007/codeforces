#include<bits/stdc++.h>
#define N 400005
#define P 998244353

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int fac[N],inv[N],ifac[N];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}

namespace poly{
	const int G=114514,iG=fp(G);
	int l;
	int rev[N<<2],gn[N<<2],ign[N<<2];
	inline int init(int x,int tp=0){
		int k=0;
		while((1<<k)<=x)
			k++;
		if(!tp)
			return k;
		int lmt=1<<k;
		for(int i=0;i<lmt;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
		for(int mid=1;mid<lmt;mid<<=1){
			int Gn=fp(G,(P-1)/(mid<<1)),iGn=fp(iG,(P-1)/(mid<<1));
			gn[mid]=ign[mid]=1;
			for(int i=1;i<mid;i++){
				gn[mid+i]=1ll*gn[mid+i-1]*Gn%P;
				ign[mid+i]=1ll*ign[mid+i-1]*iGn%P;
			}
		}
		return l=k;
	}
	inline void dft(int *a,int k,int tp){
		int lmt=1<<k;
		for(int i=0;i<lmt;i++)
			if(i<(rev[i]>>(l-k)))
				std::swap(a[i],a[rev[i]>>(l-k)]);
		for(int mid=1;mid<lmt;mid<<=1)
			for(int i=0;i<lmt;i+=mid<<1)
				for(int j=0;j<mid;j++){
					int x=a[i+j],y=1ll*(tp==1?gn[mid+j]:ign[mid+j])*a[i+j+mid]%P;
					a[i+j]=fmo(x+y-P),a[i+j+mid]=fmo(x-y);
				}
		if(tp==-1){
			int tmp=fp(lmt);
			for(int i=0;i<lmt;i++)
				a[i]=1ll*a[i]*tmp%P;
		}
	}
	inline std::vector<int> mul(std::vector<int> f,std::vector<int> g){
		int len=f.size()+g.size()-1,k=init(len);
		f.resize(1<<k),g.resize(1<<k);
		dft(f.data(),k,1),dft(g.data(),k,1);
		std::vector<int> res(1<<k);
		for(int i=0;i<(1<<k);i++)
			res[i]=1ll*f[i]*g[i]%P;
		dft(res.data(),k,-1);
		res.resize(len);
		return res;
	}
}

int p[N],_p,mu[N];
bool vis[N];
inline void si(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i])
			p[++_p]=i,mu[i]=P-1;
		for(int j=1;j<=_p&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0)
				break;
			mu[i*p[j]]=P-mu[i];
		}
	}
	for(int i=1;i<=n;i++)
		mu[i]=fmo(mu[i]+mu[i-1]-P);
}

int n,k;

int ans;

int main(){
	scanf("%d%d",&n,&k);
	if(n==1||k==1)
		return puts("1"),0;
	poly::init(k<<1,1),init(k);
	n--;
	si(n);
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		int m=n/l,t=std::min(m,k);
		std::vector<int> f(t+1),g(t+1);
		for(int i=0;i<=t;i++)
			f[i]=i&1?fmo(-ifac[i]):ifac[i];
		for(int i=1;i<=t;i++)
			g[i]=1ll*ifac[i]*(i==1?m:fmo(1ll*fmo(fp(i,m+1)-1)*fp(i-1)%P-1))%P;
		f=poly::mul(f,g);
		int tmp=0;
		for(int i=1;i<=t;i++)
			tmp=fmo(tmp+1ll*f[i]*std::min(i,k-1)%P-P);
		ans=fmo(ans+1ll*tmp*fmo(mu[r]-mu[l-1])%P-P);
	}
	printf("%d\n",ans);
}