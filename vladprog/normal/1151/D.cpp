#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=1e5+100;

int c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        c[i]=a-b;
        ans+=b*n-a;
    }
    sort(c+1,c+n+1,greater<int>());
    for(int i=1;i<=n;i++)
        ans+=c[i]*i;
    cout<<ans;
}