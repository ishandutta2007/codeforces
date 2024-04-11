#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int u[N],s[N];
vector<int> v[N];

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
            cin>>u[i];
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=1;i<=n;i++)
            v[u[i]].push_back(s[i]);
        for(int i=1;i<=n;i++)
            sort(v[i].begin(),v[i].end(),greater<>());
        for(int i=1;i<=n;i++)
            for(int j=1;j<v[i].size();j++)
                v[i][j]+=v[i][j-1];
        sort(v+1,v+n+1,[](vector<int>&a,vector<int>&b){return a.size()>b.size();});
//        for(int i=1;i<=n;i++)
//        {
//            cout<<i<<" : ";
//            for(int j:v[i])
//                cout<<j<<" ";
//            cout<<"\n";
//        }
        for(int k=1;k<=n;k++)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
                if(v[i].size()>=k)
                    ans+=v[i][v[i].size()/k*k-1];
                else
                    break;
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}