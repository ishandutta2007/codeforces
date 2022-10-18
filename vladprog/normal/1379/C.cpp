#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=1e5+100;

pii ab[M];
int a[M],b[M],pref[M];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>ab[i].x>>ab[i].y;
    sort(ab+1,ab+m+1,greater<pii>());
    for(int i=1;i<=m;i++)
        tie(a[i],b[i])=ab[i],
        pref[i]=pref[i-1]+a[i];
    int ans=0;
    if(n<=m)
        ans=pref[n];
    for(int i=1;i<=m;i++)
    {
        int j=lower_bound(a+1,a+m+1,b[i],greater<int>())-a-1;
        int res=pref[j],cnt=j;
        if(i>j)
            res+=a[i],cnt++;
        if(cnt>n)
            continue;
        res+=b[i]*(n-cnt);
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}