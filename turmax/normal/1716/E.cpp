#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=(1<<18);
vector<vector<int> > go(vector<int> a)
{
    if(a.size()==1) {int o=max(0LL,a[0]);return {{o},{o},{o}};}
    vector<int> a1(a.size()/2),a2(a.size()/2);for(int i=0;i<a.size()/2;++i) {a1[i]=a[i];} for(int i=a.size()/2;i<a.size();++i) {a2[i-a.size()/2]=a[i];}
    int sum1=0;for(auto h:a1) sum1+=h; int sum2=0;for(auto h:a2) sum2+=h;
    vector<vector<int> > res1=go(a1);vector<vector<int> > res2=go(a2);
    vector<int> ans(a.size()),pr(a.size()),suf(a.size());
    for(int i=0;i<a.size()/2;++i) {ans[i]=max({res1[0][i],res2[0][i],res1[2][i]+res2[1][i]});pr[i]=max({res1[1][i],sum1+res2[1][i]});suf[i]=max({res2[2][i],sum2+res1[2][i]});}
    for(int i=0;i<a.size()/2;++i) {ans[i+a.size()/2]=max({res2[0][i],res1[0][i],res2[2][i]+res1[1][i]});pr[i+a.size()/2]=max({res2[1][i],sum2+res1[1][i]});suf[i+a.size()/2]=max({res1[2][i],sum1+res2[2][i]});}
    return {ans,pr,suf};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;vector<int> a(1<<n);for(int i=0;i<(1<<n);++i) cin>>a[i];
    vector<vector<int> > res=go(a);vector<int> ans=res[0];
    int x=0;
    int t;cin>>t;
    while(t--)
    {
        int k;cin>>k;x^=(1<<k);
        cout<<ans[x]<<'\n';
    }
    return 0;
}