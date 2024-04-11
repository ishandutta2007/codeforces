#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
set <int> t[4*maxn];
void to(int node,int tl,int tr,int pos,int r)
{
    if(tl>pos || tr<=pos) return;
    if(tl<=pos && tr>pos)
    {
        t[node].insert(r);
    }
    if((tr-tl)==1) return;
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,r);to(2*node+2,tm,tr,pos,r);
}
bool get(int node,int tl,int tr,int l1,int r1,int l2,int r2)
{
    if(tl>=r1 || tr<=l1) return false;
    if(tl>=l1 && tr<=r1)
    {
        return t[node].lower_bound(l2)!=t[node].lower_bound(r2);
    }
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l1,r1,l2,r2) || get(2*node+2,tm,tr,l1,r1,l2,r2);
}
void add(int l,int r)
{
    to(0,0,maxn,l,r);
}
bool in(int l1,int r1,int l2,int r2)
{
    return get(0,0,maxn,l1,r1,l2,r2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    set <int> ok;
    for(int i=1;i<=n;++i) ok.insert(i);
    ok.insert(-1);ok.insert(n+1);
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==0)
        {
            int l,r,x;
            cin>>l>>r>>x;
            if(x==0)
            {
                set <int>::iterator it=ok.lower_bound(l);
                vector <int> dels;
                while(it!=ok.end() && (*it)<=r)
                {
                    dels.push_back(*it);++it;
                }
                for(auto h:dels) ok.erase(h);
            }
            else
            {
                add(l,r);
            }
        }
        else
        {
            int x;
            cin>>x;
            if(!ok.count(x))
            {
                cout<<"NO"<<'\n';
                continue;
            }
            else
            {
                set <int>::iterator it=ok.find(x);
                --it;int l=(*it);++it;++it;int r=(*it);
                if(in(l+1,x+1,x,r)) cout<<"YES"<<'\n';
                else cout<<"N/A"<<'\n';
            }
        }
    }
    return 0;
}