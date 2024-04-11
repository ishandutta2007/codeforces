#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 

int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int f(int n,int m){n--;m--;return C(n+m,n);}
int n,ans,idn,id1;
bool flagn,flag1;
int a,b;

void solve()
{
	rd(a);rd(b);if (b==1) puts("NO"); else 
	{
		puts("YES");
		if (b==2) cout<<a<<" "<<a*3<<" "<<a*4<<endl;
		else cout<<a<<" "<<a*(b-1)<<" "<<a*b<<endl;
	}

}
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		solve();
	}
}