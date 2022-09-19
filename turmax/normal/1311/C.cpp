#include <bits/stdc++.h>

using namespace std;
#define int long long
void pl(vector <int> &a,vector <int> &b)
{
    for(int i=0;i<26;++i)
    {
        a[i]+=b[i];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n,m;
        cin>>n>>m;
        string s;
        vector <vector <int> > u(n+1);
        cin>>s;
        vector <int> v(26);
        for(int i=0;i<26;++i)
        {
            v[i]=0;
        }
        u[0]=v;
        for(int i=0;i<n;++i)
        {
            v[s[i]-'a']++;
            u[i+1]=v;
        }
        vector <int> ans(26);
        for(int i=0;i<26;++i)
        {
            ans[i]=0;
        }
        int x;
        for(int i=0;i<m;++i)
        {
            cin>>x;
            pl(ans,u[x]);
        }
        pl(ans,u[n]);
        for(int i=0;i<26;++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}