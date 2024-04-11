//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
#define int long long
const int P=1e9+7;
int n,q,sm[3000505][5],fc[3000505],fi[3000505],iv[3000505];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
signed main()
{
	read(n),read(q),fc[0]=1;for(int i=1;i<=3000500;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[3000500]=ksm(fc[3000500]);for(int i=3000500;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	iv[1]=1;for(int i=2;i<=3000500;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	sm[1][1]=1ll*(3ll*n-1)*n%P*iv[2]%P,sm[1][2]=1ll*(3ll*n+1)*n%P*iv[2]%P,sm[1][3]=1ll*(3ll*n+3)*n%P*iv[2]%P;
	for(int i=2;i<=n*3;i++)
	{
		int x=1ll*i*sm[i-1][1]%P,y=1ll*i*sm[i-1][2]%P,z=1ll*fc[3*n+1]*fi[3*n-i]%P*iv[i+1]%P;
		//printf("%d %d %d\n",x,y,z);
		sm[i][1]=1ll*iv[3]*(1ll*z-x-x-y+P+P+P)%P,sm[i][2]=(sm[i][1]+x)%P,sm[i][3]=(sm[i][2]+y)%P;
	}
	for(int x;q--;) read(x),printf("%lld\n",1ll*sm[x][3]*fi[x]%P);
	return 0;
}