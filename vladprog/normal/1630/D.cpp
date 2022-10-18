#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int a[N];
vector<int> lst[N];
bool par[N];

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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int k=0;
        while(m--)
        {
            int b;
            cin>>b;
            k=__gcd(k,b);
        }
        for(int i=0;i<k;i++)
            lst[i].clear(),
            par[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
                par[i%k]=!par[i%k];
            lst[i%k].push_back(abs(a[i]));
        }
        for(int i=0;i<k;i++)
            sort(lst[i].begin(),lst[i].end());
        int ans=-1e18;
        for(int _=0;_<2;_++)
        {
            int res=0;
            for(int i=0;i<k;i++)
                if(par[i])
                    res+=accumulate(lst[i].begin()+1,lst[i].end(),0ll)-lst[i].front();
                else
                    res+=accumulate(lst[i].begin(),lst[i].end(),0ll);
            ans=max(ans,res);
            for(int i=0;i<k;i++)
                par[i]=!par[i];
        }
        cout<<ans<<"\n";
    }
}