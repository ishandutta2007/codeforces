#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=2e5+100;

vector<int> a[N],b[N];
int x[N],y[N];
int cnt[N];

signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        a[i].resize(m),
        b[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j],
            b[i][j]=i*m+j+1,
            x[i*m+j+1]=i,
            y[i*m+j+1]=j;
    int ans=0;
    for(int j=0;j<m;j++)
    {
        int res=n;
        for(int i=0;i<n;i++)
            cnt[i]=0;
        for(int i=0;i<n;i++)
            if(a[i][j]<=n*m&&y[a[i][j]]==j)
                cnt[(i-x[a[i][j]]+n)%n]++;
        for(int i=0;i<n;i++)
            res=min(res,i+n-cnt[i]);
        ans+=res;
    }
    cout<<ans;
}