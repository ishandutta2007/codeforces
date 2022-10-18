#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010;

int a[N],b[N];
int pref[N],suff[N],seg[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    pref[0]=0;
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]+a[i]*b[i];
    suff[n+1]=0;
    for(int i=n;i>=1;i--)
        suff[i]=suff[i+1]+a[i]*b[i];
    for(int i=1;i<=n;i++)
        seg[i][i]=a[i]*b[i];
    for(int i=1;i<=n-1;i++)
        seg[i][i+1]=a[i]*b[i+1]+b[i]*a[i+1];
    for(int d=2;d<=n;d++)
        for(int i=1;i<=n-2;i++)
            if(int j=i+d;j<=n)
                seg[i][j]=seg[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
    int ans=pref[n];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            ans=max(ans,pref[i-1]+seg[i][j]+suff[j+1]);
    cout<<ans<<"\n";
}