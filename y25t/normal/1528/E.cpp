#include<cstdio>
#include<algorithm>
#define N 1000005
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

inline int C(int x,int y){
	int res=1;
	for(int i=0;i<y;i++)
		res=1ll*res*(x+i)%P;
	for(int i=1;i<=y;i++)
		res=1ll*res*fp(i)%P;
	return res;
}

int n;

int f[N],s[N];

int ans;

int main(){
	scanf("%d",&n);
	f[0]=s[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=fmo(fmo(f[i-1]+C(f[i-1],2)-P)+(i>1?1ll*f[i-1]*s[i-2]%P:0)-P);
		s[i]=fmo(s[i-1]+f[i]-P);
	}
	ans=fmo(2ll*fmo(fmo(f[n]+C(f[n-1],3)-P)+fmo(1ll*C(f[n-1],2)*s[n-2]%P+1ll*f[n-1]*C(s[n-2],2)%P-P)-P)%P-1);
	for(int i=0;i<n-1;i++)
		ans=fmo(ans+1ll*fmo(f[i]-1)*fmo(f[n-i-1]-f[n-i-2])%P-P);
	printf("%d\n",ans);
}