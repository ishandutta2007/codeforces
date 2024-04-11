#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int k[N];
vector<int> f[N];
int c[N];
int cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>k[i];
            f[i].resize(k[i]);
            for(int j=0;j<k[i];j++)
                cin>>f[i][j];
        }
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int i=1;i<=m;i++)
            if(k[i]==1)
                c[i]=f[i][0],
                cnt[f[i][0]]++;
        for(int i=1;i<=m;i++)
            if(k[i]>1)
            {
                int a=f[i][0],b=f[i][1];
                c[i]=(cnt[a]<cnt[b]?a:b);
                cnt[c[i]]++;
            }
        int mx=*max_element(cnt+1,cnt+n+1);
        if(mx>(m+1)/2)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=m;i++)
                cout<<c[i]<<" ";
            cout<<"\n";
        }
    }
}