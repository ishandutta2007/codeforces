#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=300005;
int n,ans,F[N],C[N];
int mn[N],fac[N],inv[N];
vector<int> vec[N];
void init(){
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j])
			mn[i*j]=i;
	inv[0]=inv[1]=fac[0]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,2,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		for (;x!=1;){
			int v=mn[x],c=0;
			for (;x%v==0;x/=v,++c);
			vec[v].PB(c);
		}
	}
	F[0]=mo-1;
	For(i,1,n-1) F[0]=2ll*F[0]%mo;
	For(i,0,n) C[i]=1ll*fac[n]*inv[i]%mo*inv[n-i]%mo;
	For(i,1,n) F[i]=(F[i-1]+C[i-1])%mo;
	For(i,2,N-1) if (mn[i]==i){
		sort(vec[i].begin(),vec[i].end());
		int rem=n;
		for (;vec[i].size();vec[i].pop_back())
			ans=(ans+1ll*F[rem--]*vec[i].back())%mo;
	}
	printf("%d\n",ans);
}