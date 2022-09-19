#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
#ifdef LOCAL
#define __int128 long long
#endif // LOCAL
__int128 f()
{
    string s;cin>>s;
    __int128 x=0;
    reverse(s.begin(),s.end());__int128 u=1;
    for(auto h:s)
    {
        x+=(h-'0')*u;
        u*=10;
    }
    return x;
}
void go(__int128 d)
{
    string ans;while(d!=0) {ans.push_back('0'+(d%10));d/=10;}
    reverse(ans.begin(),ans.end());cout<<ans<<' ';
}
struct zz
{
    int n;vector<__int128> v;vector<__int128> t;
    void build(int node,int tl,int tr)
    {
        if((tr-tl)==1) {t[node]=v[tl];return;}
        int tm=(tl+tr)/2;
        build(2*node+1,tl,tm);build(2*node+2,tm,tr);
        t[node]=((t[2*node+1]/__gcd(t[2*node+1],t[2*node+2]))*t[2*node+2]);
    }
    void build(int n,vector<__int128> v)
    {
        this->n=n;this->v=v;t.resize(4*n);
        build(0,0,n);
    }
    void to(int node,int tl,int tr,int pos)
    {
        if(tl>pos || tr<=pos) return;
        if((tr-tl)==1) {t[node]=1;return;}
        int tm=(tl+tr)/2;
        to(2*node+1,tl,tm,pos);to(2*node+2,tm,tr,pos);
        t[node]=((t[2*node+1]/__gcd(t[2*node+1],t[2*node+2]))*t[2*node+2]);
    }
    __int128 get()
    {
        return t[0];
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;vector<__int128> a(n);vector<__int128> b(m);for(int i=0;i<n;++i) a[i]=f(); for(int j=0;j<m;++j) b[j]=f();
        zz a2[n];zz b2[m];for(int i=0;i<n;++i) {vector<__int128> v;for(auto h:b) v.push_back(__gcd(h,a[i]));a2[i].build(m,v);} for(int i=0;i<m;++i) {vector<__int128> v;for(auto h:a) v.push_back(__gcd(b[i],h));b2[i].build(n,v);}
        vector<int> u1,u2;
        for(int i=0;i<n;++i) u1.push_back(i);
        for(int i=0;i<m;++i) u2.push_back(i);
        while(true)
        {
            vector<int> u11,u21;
            for(auto h:u1)
            {
                if(a2[h].get()==a[h]) {u11.push_back(h);}
                else {for(int x:u2) {b2[x].to(0,0,n,h);}}
            }
            for(auto h:u2)
            {
                if(b2[h].get()==b[h]) {u21.push_back(h);}
                else {for(int x:u11) {a2[x].to(0,0,m,h);}}
            }
            if(u11.size()==u1.size() && u21.size()==u2.size())
            {
                break;
            }
            u1=u11;u2=u21;
        }
        if(!u1.empty() && !u2.empty())
        {
            cout<<"YES"<<'\n';
            cout<<u1.size()<<' '<<u2.size()<<'\n';
            for(auto h:u1) go(a[h]); cout<<'\n';
            for(auto h:u2) go(b[h]); cout<<'\n';
        }
        else {cout<<"NO"<<'\n';}
    }
    return 0;
}