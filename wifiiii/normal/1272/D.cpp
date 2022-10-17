#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[200005],pre[200005],suf[200005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    a[n+1] = 2e9;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(a[i] > a[i-1]) pre[i] = pre[i-1] + 1;
        else pre[i] = 1;
        ans = max(ans, pre[i]);
    }
    for(int i=n;i>=1;--i)
    {
        if(a[i] < a[i+1]) suf[i] = suf[i+1] + 1;
        else suf[i] = 1;
    }
    for(int i=2;i<n;++i)
    {
        if(a[i-1] < a[i+1]) ans = max(ans, pre[i-1] + suf[i+1]);
    }
    cout << ans << endl;
}