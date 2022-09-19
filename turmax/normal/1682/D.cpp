#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
bool ok[maxn];bool h[maxn];set <int> d;int pr[maxn];int nxt[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;string s;cin>>s;int sum=0;for(int i=0;i<n;++i) {sum+=(s[i]-'0');} if(sum%2==1 || sum==0) {cout<<"NO"<<'\n';continue;}
        d.clear();for(int i=0;i<n;++i) {h[i]=(s[i]-'0');if(h[i]) d.insert(i);}
        for(int i=0;i<n;++i) {pr[i]=(i+n-1)%n;nxt[i]=(i+1)%n;}
        for(int i=0;i<n;++i) ok[i]=true;
        vector<pair<int,int> > res;
        while(!d.empty())
        {
            int x=(*d.begin());d.erase(d.begin());
            if(!ok[x]) continue;
            if(!h[x]) continue;
            int y=nxt[x];int z=pr[x];
            if(!h[y]) {res.push_back({x,y});h[y]=true;d.insert(y);}
            else if(!h[z]) {res.push_back({x,z});h[z]=true;d.insert(z);}
            else {res.push_back({x,y});h[y]=false;if(d.count(y)) d.erase(y);}
            ok[x]=false;pr[y]=z;nxt[z]=y;
        }
        cout<<"YES"<<'\n';
        for(auto h:res) cout<<h.first+1<<' '<<h.second+1<<'\n';
    }
    return 0;
}