#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
int a[maxn];
vector<pair<int,int> > res;
int f(int x) {if(x==0) return 30;int ans=0;while(x%2==0) {x/=2;++ans;} return ans;}
void mv(int x,int y)
{
    if(a[x]<a[y]) swap(x,y);
    res.push_back({x,y});
    a[x]-=a[y];a[y]*=2;return;
}
void go2(int x,int y,int c)
{
    if(f(a[x])==c) return; if(f(a[y])==c) return;
    mv(x,y);go2(x,y,c);
}
void go(int x,int y,int z)
{
    if(a[x]==0 || a[y]==0 || a[z]==0) return;
    int tx=f(a[x]);int ty=f(a[y]);int tz=f(a[z]);
    if(tx==ty) {mv(x,y);go(x,y,z);return;}
    if(tx==tz) {mv(x,z);go(x,y,z);return;}
    if(ty==tz) {mv(y,z);go(x,y,z);return;}
    if(tx>ty) {swap(x,y);go(x,y,z);return;} if(ty>tz) {swap(y,z);go(x,y,z);return;}
    go2(x,z,ty);go(x,y,z);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int sum=0;for(int i=0;i<n;++i) {cin>>a[i];sum+=((bool) a[i]);} if(sum<2) {cout<<(-1);return 0;}
    while(true)
    {
        int sum=0;vector<int> nz;for(int i=0;i<n;++i) {if(a[i]) nz.push_back(i);sum+=((bool) a[i]);} if(sum==2) {cout<<res.size()<<'\n';for(auto h:res) cout<<h.second+1<<' '<<h.first+1<<'\n'; return 0;}
        shuffle(nz.begin(),nz.end(),mt19937(rand()));go(nz[0],nz[1],nz[2]);
    }
    return 0;
}