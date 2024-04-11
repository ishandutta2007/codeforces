#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
static int l[305];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n*m];map <int,int> cnt;map<int,vector <int> > d;vector <int> keys;
        for(int i=0;i<n*m;++i) {cin>>a[i];if(cnt.count(a[i])) {cnt[a[i]]++;d[a[i]].push_back(i);}else {cnt[a[i]]=1;keys.push_back(a[i]);d[a[i]]={i};}}
        int b[n*m];
        for(int i=0;i<n*m;++i)
        {
            b[i]=a[i];
        }
        for(auto h:keys) {sort(d[h].begin(),d[h].end());reverse(d[h].begin(),d[h].end());}
        sort(b,b+n*m);
        //for(auto h:b) cout<<h<<" h "<<endl;
        vector <int> v[n];set <int> o[n];vector <int> u[n];
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) {v[i].push_back(b[i*m+j]);o[i].insert(v[i].back());u[i].push_back(0);}
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=(m-1);j>=0;j--)
            {
                 int r=v[i][j];
                 l[j]=(d[r].back());d[r].pop_back();
            }
            //for(auto h:l) cout<<h<<' ';
            //cout<<endl;
            for(int j=0;j<m;++j)
            {
                for(int k=(j+1);k<m;++k)
                {
                    if(l[j]<l[k]) ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}