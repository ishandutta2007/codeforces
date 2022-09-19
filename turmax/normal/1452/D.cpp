#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
const int p=998244353;
int ans[maxn];
void go()
{
    ans[1]=1;
    ans[2]=1;
    for(int i=3;i<maxn;++i) ans[i]=(ans[i-1]+ans[i-2])%p;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    go();
    int n;
    cin>>n;
    int u=ans[n];
    for(int i=0;i<n;++i)
    {
        u*=((p+1)/2);
        u%=p;
    }
    cout<<u;
    return 0;
}