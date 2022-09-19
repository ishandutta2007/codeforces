#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int inv(int x)
{
    return po(x,p-2);
}
const int maxk=1100001;
int fact[maxk];
int invf[maxk];
int a[maxk];
int32_t main()
{// after editorial
    int u=1;
    for(int i=0;i<maxk;++i)
    {
        fact[i]=u;
        u*=(i+1);
        u%=p;
        invf[i]=inv(fact[i]);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=(k+1);++i)
    {
        sum+=po(i,k);
        sum%=p;
        a[i]=sum;
        //cout<<i<<" "<<a[i]<<endl;
    }
    a[0]=0;
    int pr=1;
    if(n<=(k+1))
    {
        cout<<a[n]<<" ";
        return 0;
    }
    for(int i=0;i<=(k+1);++i)
    {
        pr*=(n-i);
        pr%=p;
    }
    //cout<<pr<<" pr "<<endl;
    sum=0;
    for(int i=1;i<=(k+1);++i)
    {
        //cout<<inv(n-i)<<endl;
        if((k-i+1)%2==0)
        sum+=((a[i]*pr)%p*((inv(n-i)*invf[i])%p)%p*((invf[k-i+1])%p));
        else
        sum-=((a[i]*pr)%p*((inv(n-i)*invf[i])%p)%p*((invf[k-i+1])%p));
        //cout<<sum<<" sum "<<endl;
        sum%=p;
    }
    cout<<(sum%p+p)%p;
    return 0;
}