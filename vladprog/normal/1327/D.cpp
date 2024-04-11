#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> divs[N];
int p[N],c[N];
bool used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
            divs[j].push_back(i);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        for(int i=1;i<=n;i++)
            cin>>c[i];
        for(int i=1;i<=n;i++)
            used[i]=false;
        int ans=1e9;
        for(int i=1;i<=n;i++)
            if(!used[i])
            {
                vector<int> cyc;
                for(int j=i;!used[j];j=p[j])
                {
                    cyc.push_back(c[j]);
                    used[j]=true;
                }
                int s=cyc.size();
                for(int d:divs[s])
                    for(int i=0;i<d;i++)
                    {
                        bool ok=true;
                        for(int j=i;j+d<s;j+=d)
                            if(cyc[j]!=cyc[j+d])
                                ok=false;
                        if(ok)
                            ans=min(ans,d);
                    }
            }
        cout<<ans<<"\n";
    }
}