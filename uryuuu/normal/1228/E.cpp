#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1000000007;
ll p[300],inv[300],d[300][300],p1[300],p2[300];
ll ksm(ll x,ll y)//
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res;
}

void add(ll&x,ll y)
{
    x+=y;
    if(x>=Mod)
        x-=Mod;
    if(x<0)
        x+=Mod;
}

ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main()
{
    p[0]=inv[0]=1;
    for(int i=1;i<=250;i++)
    {
        p[i]=p[i-1]*i%Mod;
        inv[i]=ksm(p[i],Mod-2);
    }
    int n,k;
    cin>>n>>k;
    p1[0]=p2[0]=1;
    for(int i=1;i<=n;i++)
    {
        p1[i]=p1[i-1]*k%Mod;
        p2[i]=p2[i-1]*(k-1)%Mod;
    }
    for(int i=1;i<=n;i++)
    {
        d[1][i]=C(n,i)*p2[n-i]%Mod;
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int p=j;p<=n;p++)
            {
                ll res=C(n-j,p-j)*p2[n-p]%Mod*p1[j]%Mod;
                if(j==p)
                    res=(p1[p]-p2[p]+Mod)%Mod*p2[n-p]%Mod;
                    add(d[i][p],d[i-1][j]*res%Mod);
            }
    cout<<d[n][n]<<endl;
    return 0;
}