#include<bits/stdc++.h>
#define P 998244353
#define N 100005

inline int fmo(int x){
	return x+((x>>31)&P);
}
int fac[N],inv[N],ifac[N];
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=n;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
inline int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int T;

int n,a[N];
char s[N];

int main(){
	init(100000);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			a[i]=s[i]-'0';
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			y+=!a[i];
			if(i<n&&a[i]&&a[i+1]){
				x++;
				i++;
			}
		}
		printf("%d\n",C(x+y,x));
	}
}