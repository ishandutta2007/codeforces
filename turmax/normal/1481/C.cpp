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
        int n,m;
        cin>>n>>m;
        int a[n],b[n];
        vector <int> l[n];
        for(int i=0;i<n;++i) {cin>>a[i];a[i]--;}
        for(int i=0;i<n;++i) {cin>>b[i];b[i]--;l[b[i]].push_back(i);}
        int c[m];
        vector <int> o[n];
        for(int i=0;i<m;++i) {cin>>c[i];c[i]--;}
        for(int i=0;i<n;++i) {if(a[i]!=b[i]) o[b[i]].push_back(i);}
        vector <int> v;
        bool ans=true;
        for(int i=(m-1);i>=0;i--)
        {
            int x=c[i];
            if(o[x].empty())
            {
                if(l[x].empty() && v.empty())
                {
                    ans=false;
                }
                else if(l[x].size())
                {
                    v.push_back(l[x].back());
                }
                else
                {
                    v.push_back(v.back());
                }
            }
            else
            {
                int z=o[x].back();
                v.push_back(z);
                o[x].pop_back();
            }
        }
        for(int i=0;i<n;++i) ans=(ans && o[i].empty());
        if(ans)
        {
            cout<<"YES"<<endl;
            reverse(v.begin(),v.end());
            for(auto h:v) cout<<h+1<<' ';
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}