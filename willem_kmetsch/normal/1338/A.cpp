#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=4e6+5;
const int M=170;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n;
int a[N],k[N];
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    a[0]=-1e9-1;
    int x=0,ans=0;
    for (int i=1;i<=n;i++)
    {
        x=max(a[i-1]-a[i],x);
        a[i]=max(a[i],a[i-1]);
    }
    while (x) ans++,x/=2;
    cout<<ans<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/