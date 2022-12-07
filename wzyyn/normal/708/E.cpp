#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
const int N=100005;
const int M=1505;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,m,A,B,k,p,S;
int fac[N],inv[N],val[M];
int f[M][M],pr[M],su[M];
int npr[M],nsu[M];
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&k);
	p=1ll*A*power(B,mo-2)%mo;
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,0,min(m,k)) val[i]=1ll*power(p,i)*power(1+mo-p,k-i)%mo*C(k,i)%mo;
	f[1][m]=nsu[m]=npr[1]=1;
	For(i,1,n){
		S=0;
		For(j,1,m) S=(S+npr[j])%mo;
		Rep(j,m,1) pr[j]=(npr[j]+pr[j+1])%mo;
		For(j,1,m) su[j]=(nsu[j]+su[j-1])%mo;
		int SS=0,SSS=0;
		For(j,1,m){
			SS=(SS+1ll*su[j-1]*val[j-1])%mo;
			SSS=(SSS+val[j-1])%mo;
			nsu[j]=(1ll*(S+mo-pr[j+1])*SSS+mo-SS)%mo;
			nsu[j]=1ll*nsu[j]*val[m-j]%mo;
		}
		SS=0,SSS=0;
		Rep(j,m,1){
			SS=(SS+1ll*pr[j+1]*val[m-j])%mo;
			SSS=(SSS+val[m-j])%mo;
			npr[j]=(1ll*(S+mo-su[j-1])*SSS+mo-SS)%mo;
			npr[j]=1ll*npr[j]*val[j-1]%mo;
		}
	}
	int ans=0;
	For(j,1,m) ans=(ans+npr[j])%mo;
	printf("%d\n",ans);
}
/*
10 10
23 66
15
*/