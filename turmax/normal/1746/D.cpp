#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector<int> ch[maxn];
int s[maxn];
unordered_map<int,int> u;
int go(int x,int k)
{
    int ha=x*maxn+k;
    if(u.count(ha)) return u[ha];
    int sz=ch[x].size();
    if(sz==0) {return k*s[x];}
    vector<int> u1;vector<int> v1;
    for(int v:ch[x])
    {
        int o=(k/sz);int o1=o+1;
        int val=go(v,o);int val1;if((k%sz)!=0) val1=go(v,o1); else val1=0;
        u1.push_back(val);v1.push_back(val1-val);
    }
    sort(v1.begin(),v1.end());reverse(v1.begin(),v1.end());
    int sum=0;for(auto h:u1) sum+=h;
    int sz1=(k%sz);
    for(int i=0;i<sz1;++i) sum+=v1[i];
    sum+=(k*s[x]);
    u[ha]=sum;return sum;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        u.clear();
        for(int i=0;i<n;++i) ch[i].clear();
        for(int i=1;i<n;++i) {int x;cin>>x;--x;ch[x].push_back(i);}
        for(int i=0;i<n;++i) cin>>s[i];
        cout<<go(0,k)<<'\n';
    }
    return 0;
}