#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <int> w;
vector <int> deq;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        w.resize(n);
        vector <int> z;
        int ans=0;
        for(int i=0;i<n;++i) {cin>>w[i];ans+=w[i];}
        deq.resize(n);
        for(int i=0;i<n;++i) deq[i]=0;
        for(int i=0;i<(n-1);++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
            deq[x]++;deq[y]++;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<deq[i]-1;++j)
            {
                z.push_back(w[i]);
            }
        }
        sort(z.begin(),z.end());reverse(z.begin(),z.end());
        for(int i=0;i<(n-2);++i)
        {
            cout<<ans<<' ';
            ans+=z[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}