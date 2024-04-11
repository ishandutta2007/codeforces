#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int x[N],y[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        set<int> s;
        for(int i=1;i<=2*n;i++)
            s.insert(i);
        for(int i=1;i<=k;i++)
        {
            cin>>x[i]>>y[i];
            s.erase(x[i]);
            s.erase(y[i]);
            if(x[i]>y[i])
                swap(x[i],y[i]);
        }
        for(int i=k+1;i<=n;i++)
            x[i]=*s.begin(),
            s.erase(s.begin());
        for(int i=k+1;i<=n;i++)
            y[i]=*s.begin(),
            s.erase(s.begin());
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j]||
                   x[j]<x[i]&&x[i]<y[j]&&y[j]<y[i])
                    ans++;
        cout<<ans<<"\n";
    }
}