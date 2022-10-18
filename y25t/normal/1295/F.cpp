#include<cstdio>
#include<algorithm>
#define P 998244353
#define N 55

inline int fp(int x,int k){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,l[N],r[N];

int val[N<<1],tot,len[N<<1];

namespace L{
	int f[N][N],g[N][N],w[N][N];
	inline void init(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i+1;j++){
				for(int k=0;k<=i;k++)
					for(int x=1;x<=j;x++)
						f[k][x]=0;
				f[0][j]=1;
				for(int k=1;k<=i;k++)
					for(int x=1;x<=j;x++)
						for(int y=x;y<=j;y++)
							f[k][x]=(f[k][x]+f[k-1][y])%P;
				for(int x=1;x<=j;x++)
					g[i][j]=(g[i][j]+f[i][x])%P;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i+1;j++){
				w[i][j]=g[i][j];
				for(int k=1;k<=i+1;k++)
					if(k!=j)
						w[i][j]=1ll*w[i][j]*fp((j-k+P)%P,P-2)%P;
			}
	}
	inline int cal(int x,int y){
		if(x<=y+1)
			return g[y][x];
		int tmp=1;
		for(int i=1;i<=y+1;i++)
			tmp=1ll*tmp*(x-i+P)%P;
		int res=0;
		for(int i=1;i<=y+1;i++)
			res=(res+1ll*tmp*w[y][i]%P*fp(x-i,P-2)%P)%P;
		return res;
	}
}

int f[N][N<<1];

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		r[i]++;
		val[++tot]=l[i];
		val[++tot]=r[i];
	}
	std::sort(val+1,val+tot+1);
	tot=std::unique(val+1,val+tot+1)-val-1;
	for(int i=1;i<=n;i++){
		l[i]=std::lower_bound(val+1,val+tot+1,l[i])-val;
		r[i]=std::lower_bound(val+1,val+tot+1,r[i])-val;
	}
	for(int i=1;i<tot;i++)
		len[i]=val[i+1]-val[i];
	L::init();
	f[0][tot]=1;
	r[0]=tot+1;
	for(int i=1;i<=n;i++)
		for(int x=l[i];x<r[i];x++)
			for(int j=i;j&&l[j]<=x&&x<r[j];j--)
				for(int y=x+1;y<r[j-1];y++)
					f[i][x]=(f[i][x]+1ll*L::cal(len[x],i-j+1)*f[j-1][y]%P)%P;
	for(int i=1;i<=tot;i++)
		ans=(ans+f[n][i])%P;
	for(int i=1;i<=n;i++)
		ans=1ll*ans*fp(val[r[i]]-val[l[i]],P-2)%P;
	printf("%d\n",ans);
}