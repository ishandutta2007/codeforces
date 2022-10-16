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
int a[N],b[N];
char s[N],ch[N];
void DOIT()
{
	rd(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) ch[i]=s[i];
	sort(s+1,s+n+1);
	ans=0;
	for (int i=1;i<=n;i++) ans+=s[i]!=ch[i];
	cout<<ans<<endl;
	
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
	DOIT();
}
/*
Given is a sequence p of length N+M, which is a permutation of (1,2,N+M). The i-th term of p is pi.You can do the following Operation any number of times.Operation: Choose an integer n between 1 and N (inclusive), and an integer m between 1 and M (inclusive). Then, swap pn and pN+m.Find the minimum number of Operations needed to sort p in ascending order. We can prove that it is possible to sort p in ascending order under the Constraints of this problem.Constraints
*/