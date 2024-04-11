#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N];

int solve()
{
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
        cin>>b[i];
    int days=0,ans=1e18,money=0,pos=1;
    while(pos<=n)
    {
        ans=min(ans,days+(c-money+a[pos]-1)/a[pos]);
        int cnt=max(0ll,(b[pos]-money+a[pos]-1)/a[pos]);
//        cout<<days<<" "<<money<<" "<<pos<<" -> "<<ans<<" "<<cnt<<"\n";

        days+=cnt;
        money+=cnt*a[pos];

        days++;
        money-=b[pos];
        pos++;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}