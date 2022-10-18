#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int w[N],d[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i],
            d[i]=0;
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            d[u]++;
            d[v]++;
        }
        vector<int> a{-1};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=d[i]-1;j++)
                a.push_back(w[i]);
        sort(a.begin(),a.end(),greater<int>());
        int s=0;
        for(int i=1;i<=n;i++)
            s+=w[i];
        for(int i=1;i<=n-1;i++)
        {
            cout<<s<<" ";
            s+=a[i-1];
        }
        cout<<"\n";
    }
}