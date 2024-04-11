#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[200005];
int main()
{
    int n;
    cin>>n;
    rep(i,n) cin>>a[i],a[i]=abs(a[i]);
    sort(a+1,a+1+n);
    ll ans = 0;
    rep(i,n)
    {
        ll tmp = upper_bound(a+1,a+1+n,2*a[i])-a-1-i;
        ans += tmp;
    }
    cout << ans << endl;
}