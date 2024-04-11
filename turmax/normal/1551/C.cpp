#include <bits/stdc++.h>

using namespace std;
#define int long long
int slv(vector <vector <int> > v,int i)
{
    vector <int> z;
    int n=v.size();
    for(int j=0;j<n;++j) z.push_back(v[j][i]-v[j][(i+1)%5]-v[j][(i+2)%5]-v[j][(i+3)%5]-v[j][(i+4)%5]);
    sort(z.begin(),z.end());reverse(z.begin(),z.end());
    int res=0;
    for(int i=0;i<z.size();++i) {res+=z[i];if(res<=0) return i;}
    return n;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];vector <vector <int> > v(n);
        for(int i=0;i<n;++i) {cin>>s[i];v[i]={0,0,0,0,0};for(int j=0;j<s[i].size();++j) v[i][s[i][j]-'a']++;}
        int ans=0;
        for(int i=0;i<5;++i) ans=max(ans,slv(v,i));
        cout<<ans<<'\n';
    }
    return 0;
}