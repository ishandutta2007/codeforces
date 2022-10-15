#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 20

using namespace std;
typedef long long ll;

ll gcd(ll x,ll y)
{
    if (x%y==0) return y;else return gcd(y,x%y);
}

ll a,b,ans,t,p[maxn],c,m,k,f;

ll pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tmp=pow_(x,y/2);
    tmp=tmp*tmp%mod;
    if (y&1) tmp=tmp*x%mod;
    return tmp;
}

int main()
{
    scanf("%d%d",&a,&b);
    if (b%a) {printf("0\n");return 0;}
    b/=a;c=0; a=b;
    int j=2;
    while (j*j<=b){
        if (b%j==0){
            p[c++]=j;
            while (b%j==0) b/=j;
        }
        j++;
    }
    if (b>1) p[c++]=b;
    m=(1<<c); ans=0;
    for (int i=0;i<m;i++)
    {
        k=1;t=i;f=1;
        for (int j=0;j<c;j++)
        {
            if (t&1) k*=p[j],f=-f;
            t>>=1;
        }
        ans=(ans+pow_(2,a/k-1)*f)%mod;
        ans=(ans+mod)%mod;
    }
    printf("%d\n",ans);return 0;
}