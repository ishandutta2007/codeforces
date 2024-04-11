#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,x,tot;
int a[N];
bool chk(int x)
{
    int p=sqrt(x);
    return p*p==x;
}
void solve()
{
    rd(n);
    if ((n%2==0 && chk(n/2)) || (n%4==0 && chk(n/4))) puts("YES");else puts("NO");
    
}
signed main()
{
    int T;cin>>T;while (T--)
    {
	solve();

    }

}