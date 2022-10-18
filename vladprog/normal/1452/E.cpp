#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

pii p[N];

bool cmp(pii a,pii b)
{
    return a.x+a.y<b.x+b.y;
}

int s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>p[i].x>>p[i].y;
    sort(p+1,p+m+1,cmp);
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            s[j]=0;
        for(int j=1;j<=i;j++)
            s[p[j].x]++,
            s[p[j].y+1]--;
        for(int j=1;j<=n;j++)
            s[j]+=s[j-1];
        for(int j=1;j<=n;j++)
            s[j]+=s[j-1];
        int res=0;
        for(int j=k;j<=n;j++)
            res=max(res,s[j]-s[j-k]);

        for(int j=0;j<=n;j++)
            s[j]=0;
        for(int j=i+1;j<=m;j++)
            s[p[j].x]++,
            s[p[j].y+1]--;
        for(int j=1;j<=n;j++)
            s[j]+=s[j-1];
        for(int j=1;j<=n;j++)
            s[j]+=s[j-1];
        for(int j=k;j<=n;j++)
            ans=max(ans,res+s[j]-s[j-k]);
    }
    cout<<ans;
}