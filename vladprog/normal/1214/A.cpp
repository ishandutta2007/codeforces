#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,d,e;
    cin>>n>>d>>e;
    e*=5;
    int ans=n;
    for(int i=0;i*d<=n;i++)
        ans=min(ans,(n-i*d)%e);
    cout<<ans;
}