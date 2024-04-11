#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxa=512;
const int maxn=1e5+5;
int s[maxn][maxa];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<=n;++i) for(int j=0;j<maxa;++j) s[i][j]=1e18;
    s[0][0]=(-1e18);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<maxa;++j)
        {
            s[i+1][j]=s[i][j];
            int val=(j^a[i]);
            if(s[i][val]<a[i])
            {
                s[i+1][j]=min(s[i+1][j],a[i]);
            }
        }
    }
    vector <int> res;
    for(int i=0;i<maxa;++i) if(s[n][i]!=1e18) res.push_back(i);
    cout<<res.size()<<'\n';
    for(auto h:res) cout<<h<<' ';
    return 0;
}