#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=k;i++)
        sum+=n+1-i;
    int prv=0;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if(p>=n+1-k)
        {
            if(prv)
                cnt=cnt*(i-prv)%MOD;
            prv=i;
        }
    }
    cout<<sum<<" "<<cnt;
}