#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int m,k;
        cin>>m>>k;
        int a[k];
        pair <int,int> b[k];
        for(int i=0;i<k;++i) {cin>>a[i];b[i]={a[i],i};}
        int ma=(*max_element(a,a+k));
        int n=0;
        while(n*n-((n/2)*(n/2))<m || ((n+1)/2)*n<ma)
        {
            ++n;
        }
        cout<<n<<endl;
        vector <pair<int,int> > l;
        for(int i=0;i<n;i+=2) for(int j=1;j<n;j+=2) l.push_back({i,j});
        for(int i=0;i<n;i+=2) for(int j=0;j<n;j+=2) l.push_back({i,j});
        for(int i=1;i<n;i+=2) for(int j=0;j<n;j+=2) l.push_back({i,j});
        sort(b,b+k);reverse(b,b+k);
        int curr=0;
        int res[n][n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) res[i][j]=0;
        for(int i=0;i<k;++i)
        {
            for(int s=curr;s<(curr+b[i].first);++s)
            {
                 res[l[s].first][l[s].second]=b[i].second+1;
                 if(s==(curr+b[i].first-1)) {curr+=b[i].first;break;}
            }
        }
        for(int i=0;i<n;++i) {for(int j=0;j<n;++j) cout<<res[i][j]<<' '; cout<<endl;}
    }
    return 0;
}