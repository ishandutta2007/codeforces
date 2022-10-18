#include<bits/stdc++.h>
#define P 998244353
#define N 100005

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

namespace poly{
	const int G=114514,iG=fp(G);
	int l,rev[N<<3],gn[N<<3],ign[N<<3];
	inline int init(int len,int tp=0){
		int k=0;
		while((1<<k)<len)
			k++;
		if(!tp)
			return k;
		l=k;
		for(int i=0;i<(1<<k);i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int mid=1;mid<(1<<k);mid<<=1){
			int wn=fp(G,(P-1)/(mid<<1)),iwn=fp(iG,(P-1)/(mid<<1));
			gn[mid]=1;
			for(int i=1;i<mid;i++)
				gn[mid+i]=1ll*gn[mid+i-1]*wn%P;
			ign[mid]=1;
			for(int i=1;i<mid;i++)
				ign[mid+i]=1ll*ign[mid+i-1]*iwn%P;
		}
		return k;
	}
	inline void ntt(int *a,int tp,int k){
		for(int i=0;i<(1<<k);i++)
			if(i<(rev[i]>>(l-k)))
				std::swap(a[i],a[rev[i]>>(l-k)]);
		for(int mid=1;mid<(1<<k);mid<<=1)
			for(int i=0;i<(1<<k);i+=(mid<<1))
				for(int j=0;j<mid;j++){
					int x=a[i+j],y=1ll*a[i+j+mid]*(tp==1?gn[mid+j]:ign[mid+j])%P;
					a[i+j]=fmo(x+y-P);
					a[i+j+mid]=fmo(x-y);
				}
		if(tp==-1){
			int tmp=fp(1<<k);
			for(int i=0;i<(1<<k);i++)
				a[i]=1ll*a[i]*tmp%P;
		}
	}
	inline std::vector<int> mul(std::vector<int> a,std::vector<int> b){
		static int f[N<<3],g[N<<3];
		int len=a.size()+b.size()-1,k=poly::init(len);
		for(int i=0;i<(1<<k);i++)
			f[i]=g[i]=0;
		for(int i=0;i<(int)a.size();i++)
			f[i]=a[i];
		for(int i=0;i<(int)b.size();i++)
			g[i]=b[i];
		poly::ntt(f,1,k),poly::ntt(g,1,k);
		for(int i=0;i<(1<<k);i++)
			f[i]=1ll*f[i]*g[i]%P;
		poly::ntt(f,-1,k);
		return std::vector<int>(f,f+len);
	}
}

int n,m,a[N],b[N];

int pw[N];

int f[N],g[N],h[N<<1];
inline void sol(int L,int R){
	if(L==R)
		return;
	int mid=(L+R)>>1;
	std::vector<int> A(mid-L+1),B(R-mid);
	for(int i=L;i<=mid;i++)
		A[i-L]=f[i];
	for(int i=mid+1;i<=R;i++)
		B[i-mid-1]=g[i];
	auto C=poly::mul(A,B);
	for(int i=0;i<(int)C.size();i++)
		h[i+L+mid+1]=fmo(h[i+L+mid+1]+C[i]-P);
	sol(L,mid),sol(mid+1,R);
}

int s[N],t[N];
inline int cal(int o){
	int res=0;
	for(int i=1;i<=n;i++)
		s[i]=fmo(s[i-1]+1ll*i*a[i]%P-P),t[i]=fmo(t[i-1]+a[i]-P);
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),memset(h,0,sizeof(h));
	for(int i=n,x=1;i;i--)
		if(b[i]){
			f[i]=pw[m-x],g[i]=pw[x-1];
			res=fmo(res+1ll*s[n]*f[i]%P-P);
			res=fmo(res-1ll*s[i-1]*pw[x-1]%P*f[i]%P);
			x++;
		}
	sol(1,n);
	for(int i=1;i<=n+n;i++)
		res=fmo(res+1ll*h[i]*s[(i-o)>>1]%P-P);
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),memset(h,0,sizeof(h));
	for(int i=n,x=1;i;i--)
		if(b[i]){
			f[i]=1ll*i*pw[m-x]%P,g[i]=pw[x-1];
			res=fmo(res-1ll*t[n]*f[i]%P);
			res=fmo(res+1ll*t[i-1]%P*pw[x-1]%P*f[i]%P-P);
			x++;
		}
	sol(1,n);
	for(int i=1;i<=n+n;i++)
		res=fmo(res-1ll*h[i]*t[(i-o)>>1]%P);
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for(int i=1;i<=m;i++)
		pw[i]=fmo(pw[i-1]+pw[i-1]-P);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		b[x]=i;
	}
	poly::init(n<<1|1,1);
	int res=cal(0);
	std::reverse(a+1,a+n+1),std::reverse(b+1,b+n+1);
	res=fmo(res+cal(1)-P);
	res=1ll*res*fp(fmo(pw[m]-1))%P;
	printf("%d\n",res);
}