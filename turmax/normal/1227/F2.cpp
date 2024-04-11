#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
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
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <int> a(n);
    int q=1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        q*=m;
        q%=p;
    }
    int s1=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=a[(i+1)%n])
        {
            ++s1;
        }
    }
    int t=0;
    int c[200005];
    int curr2=1;
    int curr=1;
    int d;
    for(int i=0;i<200005;++i)
    {
        c[i]=curr;
        d=inv(i+1)*inv(i+1);
        d%=p;
        curr*=((((2*i+1)*(2*i+2))%p)*d)%p;
        curr%=p;
    }
    /*for(int i=0;i<5;++i)
    {
        cout<<i<<" "<<c[i]<<endl;
    }*/
    int r=(m-2)*inv(m);
    r%=p;
    int h=inv(m);
    //cout<<r<<" "<<h<<endl;
    //cout<<s1<<endl;
    int u[s1+1];
    curr=1;
    u[0]=curr;
    for(int i=1;i<=s1;++i)
    {
        curr*=(s1-i+1);
        curr%=p;
        curr*=inv(i);
        curr%=p;
        u[i]=curr;
        //cout<<i<<" "<<u[i]<<endl;
    }
    for(int i=0;i<=s1;i+=2)
    {
        t+=(((po(r,(s1-i))*c[i/2])%p*po(h,i))%p)*u[i];
        t%=p;
    }
    //cout<<t<<endl;
    int o=(q*t);
    o%=p;
    int z=(q-o)*inv(2);
    z%=p;
    z+=p;
    z%=p;
    cout<<z;
    return 0;
}