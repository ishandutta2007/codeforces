#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
vector<int> rasl[maxn];bool used[maxn];
map <int,int> u;int a[maxn];
bool cmp(int x,int y)
{
    return u[x]<u[y];
}
int get(vector<int> v)
{
    if(v.empty()) return (-1);
    if(v.size()==1) return 1;
    int ans=0;
    for(int i=0;i<v.size();++i)
    {
        for(int j=i+1;j<v.size();++j)
        {
            ans=__gcd(ans,a[v[i]]*a[v[j]]);
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                int x=j;
                while(x%i==0) {rasl[j].push_back(i);x/=i;}
            }
        }
    }
    for(int i=0;i<maxn;++i) used[i]=false;
    int n;cin>>n;for(int i=0;i<n;++i) {cin>>a[i];u[a[i]]=i;}
    int x=a[0];int y=a[1];vector<int> v;
    v.push_back(0);v.push_back(1);
    used[0]=true;used[1]=true;
    for(int p:rasl[x])
    {
        int el1=(-1);int el2=(-1);int cnt1=(-1);int cnt2=(-1);
        for(int i=0;i<n;++i)
        {
            if(used[i]) continue;
            int u=a[i];int cnt=0;while(u%p==0) {u/=p;++cnt;}
            if(el1==(-1) || cnt<cnt1) {cnt2=cnt1;el2=el1;cnt1=cnt;el1=i;}
            else if(el2==(-1) || cnt<cnt2) {cnt2=cnt1;el2=i;}
        }
        if(el1!=(-1)) {v.push_back(el1);used[el1]=true;} if(el2!=(-1)) {v.push_back(el2);used[el2]=true;}
    }
    for(int p:rasl[y])
    {
        if(x%p==0) continue;
        int el1=(-1);int el2=(-1);int cnt1=(-1);int cnt2=(-1);
        for(int i=0;i<n;++i)
        {
            if(used[i]) continue;
            int u=a[i];int cnt=0;while(u%p==0) {u/=p;++cnt;}
            if(el1==(-1) || cnt<cnt1) {cnt2=cnt1;el2=el1;cnt1=cnt;el1=i;}
            else if(el2==(-1) || cnt<cnt2) {cnt2=cnt1;el2=i;}
        }
        if(el1!=(-1)) {v.push_back(el1);used[el1]=true;} if(el2!=(-1)) {v.push_back(el2);used[el2]=true;}
    }
    while(true)
    {
        bool ok=false;
        for(int i=0;i<v.size();++i)
        {
            vector<int> g;
            for(int j=0;j<v.size();++j) if(j!=i) g.push_back(v[j]);
            if(get(g)==get(v))
            {
                v=g;
                ok=true;
                break;
            }
        }
        if(!ok) break;
    }
    if(get(v)==1)
    {
        cout<<0;return 0;
    }
    int ans=0;
    for(int mask=0;mask<(1<<v.size());++mask)
    {
        int cnt=__builtin_popcount(mask);
        if(cnt==1) ++ans;
        else if(cnt!=0) {ans+=(cnt-2);}
    }
    sort(v.begin(),v.end());
    assert(ans<=100000);
    cout<<ans<<'\n';
    for(int mask=0;mask<(1<<v.size());++mask)
    {
        int cnt=__builtin_popcount(mask);
        if(cnt==0) continue;
        if(cnt==1)
        {
            for(int j=0;j<1;++j)
            {
            cout<<0<<' ';
            cout<<cnt<<' ';
            for(int i=0;i<v.size();++i)
            {
                if(mask & (1<<i))
                {
                    cout<<v[i]+1<<' ';
                }
            }
            cout<<'\n';
            }
        }
        else if(cnt%2==0)
        {
            for(int j=0;j<cnt-2;++j)
            {
            cout<<0<<' ';
            cout<<cnt<<' ';
            for(int i=0;i<v.size();++i)
            {
                if(mask & (1<<i))
                {
                    cout<<v[i]+1<<' ';
                }
            }
            cout<<'\n';
            }
        }
        else
        {
            for(int j=0;j<cnt-2;++j)
            {
            cout<<1<<' ';
            cout<<cnt<<' ';
            for(int i=0;i<v.size();++i)
            {
                if(mask & (1<<i))
                {
                    cout<<v[i]+1<<' ';
                }
            }
            cout<<'\n';
            }
        }
    }
    return 0;
}