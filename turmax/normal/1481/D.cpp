#include <bits/stdc++.h>

using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        vector <int> v;
        bool ans=false;
        for(int i=0;i<n && !ans;++i) for(int j=(i+1);j<n && !ans;++j) {if(a[i][j]==a[j][i] || m%2==1) {ans=true;for(int k=0;k<=m;++k) {if(k%2==0) v.push_back(i);else v.push_back(j);}}}
        if(ans)
        {
            cout<<"YES"<<endl;
            for(auto h:v) cout<<h+1<<' ';
            cout<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n && !ans;++i) for(int j=0;j<n && !ans;++j) for(int k=0;k<n;++k)
        {
            if(a[i][j]==a[j][k])
            {
                if(i==j || j==k || k==i) continue;
            vector <int> z;
            if(m%4==0)
            {
                z.push_back(j);
                for(int i1=0;i1<(m/4);++i1)
                {
                    z.push_back(i);
                    z.push_back(j);
                    z.push_back(k);
                    z.push_back(j);
                }
            }
            else
            {
                z.push_back(i);
                z.push_back(j);
                for(int i1=0;i1<(m/4);++i1)
                {
                    z.push_back(i);
                    z.push_back(j);
                    z.push_back(k);
                    z.push_back(j);
                }
                z.push_back(k);
            }
            ans=true;
            cout<<"YES"<<endl;
            //for(int i=0;i<z.size()-1;++i) cout<<a[z[i]][z[i+1]]<<' ';
            //cout<<endl;
            for(auto h:z) cout<<h+1<<' ';
            cout<<endl;
            break;
            }
        }
        if(!ans) assert(false);
    }
    return 0;
}