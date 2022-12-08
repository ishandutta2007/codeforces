
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    int cnt0=0,cnt1=0;
    rep(i,n)
    {
        if(a[i]%2) cnt1++;
        else cnt0++;
    }
    if(!cnt0 || !cnt1)
    {
        rep(i,n) cout<<a[i]<<" ";
    }
    else
    {
        sort(a+1,a+1+n);
        rep(i,n) cout<<a[i]<<" ";
    }
}