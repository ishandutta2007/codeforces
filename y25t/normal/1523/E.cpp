#include<cstdio>
#include<algorithm>
#define P 1000000007
#define N 100005

inline int fmo(int x){
	return x+((x>>31)&P);
}

int T;

int n,k;

int fac[N],inv[N],ifac[N];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(P-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
inline int C(int x,int y){
	if(x<y||x<0||y<0)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}
inline int iC(int x,int y){
	if(x<y||x<0||y<0)
		return 0;
	return 1ll*ifac[x]*fac[y]%P*fac[x-y]%P;
}

int ans;

int main(){
	init(100000);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ans=1;
		for(int i=1;i<=n&&(i-1)*(k-1)<=n;i++){
			ans=fmo(ans+1ll*C(n-(i-1)*(k-1),i)*iC(n,i)%P-P);
		}
		printf("%d\n",ans);
	}
}