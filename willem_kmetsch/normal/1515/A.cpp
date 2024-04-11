#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int mod1=1e9+7;
const int mod2=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,x,tot;
int a[N];
void solve()
{
    rd(n);rd(x);tot=0;
    for (int i=1;i<=n;i++) rd(a[i]),tot+=a[i];
    if (tot==x) puts("NO");
    else 
    {
        tot=0;
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++) 
        {
            tot+=a[i];
            if (tot==x) swap(a[i],a[i+1]);
        }
        puts("YES");
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}
signed main()
{
    int T;cin>>T;while (T--)
    {
	solve();

    }

}