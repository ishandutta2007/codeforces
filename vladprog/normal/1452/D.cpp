#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=998244353;

int dp[N];

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int even=dp[0]=1,odd=dp[1]=1;
    for(int i=2;i<=n;i++)
        if(i%2)
            (odd+=dp[i]=even)%=MOD;
        else
            (even+=dp[i]=odd)%=MOD;
    cout<<dp[n]*ppow(ppow(2,n),MOD-2)%MOD;
}