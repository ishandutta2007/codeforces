#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100,MOD=998244353;

int divs[N],pw[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            divs[j]++;
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*2%MOD;
    int ans=divs[n];
    for(int i=1;i<=n-1;i++)
        ans=(ans+divs[i]*pw[n-i-1])%MOD;
    cout<<ans;
}