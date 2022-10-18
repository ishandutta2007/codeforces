#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
#define int ll

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=1e9;

int a[N],d[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    d[0] = -INF;
    for (int i=1; i<=n+10; ++i)
        d[i] = INF;
    for (int i=1; i<=n; i++) {
        int j = int (upper_bound (d, d+n+1, a[i]) - d);
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        if(d[i]<INF)
            ans=i;
    cout<<ans;
}