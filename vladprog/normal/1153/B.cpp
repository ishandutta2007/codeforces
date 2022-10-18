#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=200;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,h;
    cin>>n>>m>>h;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=m;j++)
        {
            int t;
            cin>>t;
            cout<<(t?min(a[j],b[i]):0)<<" ";
        }
}