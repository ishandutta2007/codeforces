#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e5+5;
int pr[maxn];
int z[maxn];
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
int inv(int x)
{
    return po(x,p-2);
}
void go()
{
    int u10=1;
    for(int i=0;i<maxn;++i)
    {
        z[i]=u10*(i+1);
        z[i]%=p;
        u10*=10;
        u10%=p;
    }
    pr[0]=0;
    for(int i=0;i<(maxn-1);++i)
    {
        pr[i+1]=pr[i]+z[i];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    go();
    //cout<<pr[0]<<' '<<pr[1]<<' '<<pr[2]<<endl;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int ans=0;
    int u10=1;
    int u11=1;
    int po[s.size()+1];
    po[0]=1;
    for(int i=0;i<s.size();++i)
    {
        po[i+1]=po[i]*2;
        po[i+1]%=p;
    }
    for(int i=0;i<s.size();++i)
    {
        int x=s[i]-'0';
        ans+=(((((s.size()-i)*(s.size()-i-1))/2)*x)%p)*u10;
        ans+=(pr[i]*x)%p;
        ans%=p;
        u10*=10;
        u11*=11;
        u10%=p;u11%=p;
    }
    cout<<(ans%p+p)%p;
    return 0;
}