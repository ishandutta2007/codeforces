#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=2e6+5;
const int M=1e6+5;
const int SZ=450;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,cnt=2;
long long ans;
int a[N];
void DOIT()
{
	rd(n);
	for (int i=1;i<=n;i++) rd(a[i]),a[i]=abs(a[i]);
	//for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (a[i]==a[j]) {puts("YES");return ;}
	for (int S=1;S<ksm(3,n);S++)
	{
		int tot=0,cnt=0,x=S;
		for (int i=0;i<n;i++) 
		{
			if (x%3==2) tot+=a[i+1],cnt++;
			if (x%3==1) tot-=a[i+1],cnt++;
			x/=3;
		}
		if (tot==0) {puts("YES");return;}
	}
	puts("NO");
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
	DOIT();
}
/*
*/