#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=998244353;
const int N=5005;
int cnt[N],a[N],fac[N];
int n,ans,f[N][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),++cnt[a[i]];
	fac[0]=1;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo;
	f[0][0]=1;
	For(i,1,n){
		For(j,1,N-1) f[i][j]=(f[i][j-1]+f[i-1][j-1])%mo;
		For(j,1,N-1)
			if (!cnt[j]) f[i][j]=0;
			else{
				if (cnt[j]>=2&&i!=n){
					int ways=1ll*cnt[j]*(cnt[j]-1)*f[i][j]%mo;
					ans=(ans+1ll*ways*fac[n-i-1])%mo;
				}
				f[i][j]=1ll*f[i][j]*cnt[j]%mo;
			}
	}
	ans=1ll*ans*power(fac[n],mo-2)%mo;
	printf("%d\n",ans);
}