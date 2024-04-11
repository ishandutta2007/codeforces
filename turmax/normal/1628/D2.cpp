#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e6+5;
int fact[maxn];
int invf[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int c(int n,int k)
{
    if(n<k || k<0 || n<0) return 0;
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;invf[0]=1;
    for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    int inv2=(p+1)/2;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        m=(n-m);
        int ans=0;
        for(int i=0;i<=n;++i)
        {
            int val=c(n-i-1,m-1);val*=k;val%=p;val*=i;val%=p;val*=po(inv2,n-i);val%=p;
            //cout<<i<<" i "<<val<<" val "<<endl;
            ans+=val;ans%=p;
        }
        if(m==0)
        {
            ans=(k*n);
            ans%=p;
        }
        /*int a[n+1][n+1];
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(i==j)
                {
                    a[i][j]=0;
                    continue;
                }
                else if(j==0)
                {
                    a[i][j]=(-k*i);
                    a[i][j]=(a[i][j]%p+p)%p;
                }
                else
                {
                    int u1=a[i-1][j];int u2=a[i-1][j-1];
                    a[i][j]=(u1+u2)*inv2;a[i][j]%=p;a[i][j]+=p;a[i][j]%=p;
                }
            }
        }*/
        //int ans=a[n][m];
        cout<<(ans%p+p)%p<<'\n';
    }
    return 0;
}