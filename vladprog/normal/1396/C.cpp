#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int a[N],x[N],y[N],dp_ok[N],dp_ret[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,r1,r2,r3,d;
    cin>>n>>r1>>r2>>r3>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        y[i]=r1*a[i]+r3;
        x[i]=min({r2+r1,r1*(a[i]+2),y[i]});
    }
//    for(int i=1;i<=n;i++)
//        cout<<i<<" -> "<<x[i]<<" "<<y[i]<<"\n";
    dp_ok[1]=y[1];
    dp_ret[1]=x[1];
    dp_ok[2]=min(y[1]+y[2]+d,x[1]+x[2]+3*d);
    dp_ret[2]=min(y[1]+x[2]+d,x[1]+x[2]+2*d);
    for(int i=3;i<=n;i++)
    {
        dp_ok[i]=min(dp_ok[i-1]+d+y[i],dp_ok[i-2]+x[i-1]+x[i]+4*d);
        dp_ret[i]=min(dp_ok[i-1]+x[i]+d,dp_ret[i-1]+x[i]+2*d);
    }
//    for(int i=1;i<=n;i++)
//        cout<<i<<" -> "<<dp_ok[i]<<" "<<dp_ret[i]<<"\n";
    cout<<min({dp_ok[n],dp_ret[n-1]+y[n]+2*d,dp_ret[n-1]+x[n]+4*d});
}