#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    if(k==1)
        cout<<(n-1)*a,exit(0);
    ll ans=0;
    while(n>=k)
    {
        int cnt=n%k;
        n-=cnt;
        ans+=cnt*a;
        cnt=n-n/k;
        if(a*cnt<b)
            n-=cnt,ans+=cnt*a;
        else
            n/=k,ans+=b;
    }
    int cnt=n-1;
    n-=cnt;
    ans+=cnt*a;
    cout<<ans;
}