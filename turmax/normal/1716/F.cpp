#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int h[2005][2005];int fact[2005];int invm[2005];int poi[2005];
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<2005;++i) {fact[i]=(fact[i-1]*i)%p;invm[i]=inv(i);}
    int t;cin>>t;
    for(int i=1;i<=2000;++i)
    {
        for(int j=1;j<=2000;++j)
        {
            if(i>j) h[i][j]=0;
            else if(i==j)
            {
                h[i][j]=fact[i];
            }
            else
            {
                h[i][j]=(h[i][j-1]*i+h[i-1][j-1]*i)%p;
            }
        }
    }
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;int pr=((m+1)/2)*inv(m);pr%=p;int o=po(m,n);
        poi[0]=1;for(int i=1;i<2005;++i) {poi[i]=(poi[i-1]*pr)%p;}
        int cur=1;int ans=0;
        for(int i=1;i<=k;++i)
        {
            cur*=(n-i+1);cur%=p;cur*=invm[i];cur%=p;
            ans+=((cur*h[i][k])%p)*poi[i];ans%=p;
        }
        cout<<((ans*o)%p+p)%p<<'\n';
    }
    return 0;
}