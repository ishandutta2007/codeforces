#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=4e5+100,MOD=1e9+7;

int a[N],b[N],p[N],was[N];

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
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        bool bad=false;
        for(int i=1;i<=n;i++)
        {
            p[a[i]]=b[i];
            if(a[i]==b[i])
                bad=true;
        }
        if(bad==true)
        {
            cout<<0<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
            was[i]=false;
        int ans=1;
        for(int i=1;i<=n;i++)
            if(!was[i])
            {
                ans=ans*2%MOD;
                for(int j=i;!was[j];j=p[j])
                    was[j]=true;
            }
        cout<<ans<<"\n";
    }
}