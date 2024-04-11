#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+5;
map <pair<int,int>,int> res;
int t[maxn];int pr[maxn];
typedef pair<int,int> pt;
void go(vector<int> a,vector<pair<pt,pt> > que,int bit,int cur)
{
    /*for(auto h:a) cout<<h<<' '; cout<<" a "<<endl;
    cout<<bit<<' '<<cur<<endl;
    for(auto h:que) cout<<h.first.first<<' '<<h.first.second<<" h "<<endl;*/
    if(que.empty()) return;
    if(bit==(-1))
    {
        for(auto h:que) {res[h.second]=cur;}
        return;
    }
    int n=a.size();vector<int> v0,v;
    for(int i=0;i<=n;++i) pr[i]=0;
    vector<int> id;for(auto h:que) {int l=h.first.first;int r=h.first.second;pr[l]++;pr[r]--;}
    int cur1=0;for(int i=0;i<n;++i) {cur1+=pr[i];if(cur1!=0) id.push_back(i);} id.push_back(n);
    vector<int> a1;for(int i=0;i<id.size()-1;++i) a1.push_back(a[id[i]]); a=a1; n=a.size();
    for(auto& h:que) {h.first.first=lower_bound(id.begin(),id.end(),h.first.first)-id.begin();h.first.second=lower_bound(id.begin(),id.end(),h.first.second)-id.begin();}
    vector<int> id0;
    for(int i=0;i<n;++i) {t[i]=(a[i] & (1<<bit))>>bit;if(!t[i]) {v0.push_back(a[i]);id0.push_back(i);}  v.push_back(a[i]);}
    id0.push_back(n);
    for(int i=0;i<=n;++i) pr[i]=0;
    for(int i=0;i<n;++i) {pr[i+1]=pr[i]+t[i];}
    vector<pair<pt,pt> > que0,que1;
    for(auto h:que)
    {
        int l=h.first.first;int r=h.first.second;
        assert(l!=r);
        if(r-l==1)
        {
            assert(false);
        }
        else if(r-l==2)
        {
            res[h.second]=((a[l] | a[l+1]) & ((1<<(bit+1))-1))+cur;
            continue;
        }
        else
        {
            if(pr[r]-pr[l]>=(r-l-1))
            {
                 que1.push_back(h);
                 continue;
            }
            else
            {
                que0.push_back({{lower_bound(id0.begin(),id0.end(),l)-id0.begin(),lower_bound(id0.begin(),id0.end(),r)-id0.begin()},h.second});
                continue;
            }
        }
    }
    go(v0,que0,bit-1,cur);go(v,que1,bit-1,cur+(1<<bit));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        res.clear();
        int n;cin>>n;vector<int> a(n);for(auto &h:a) cin>>h; vector<pair<pt,pt> > que;int q;cin>>q;que.resize(q);for(auto &h:que) {cin>>h.first.first>>h.first.second;h.first.first--;h.second=h.first;}
        go(a,que,29,0);for(auto h:que) {cout<<res[h.second]<<'\n';}
    }
    return 0;
}
/*
1
5
1 2 3 4 5
10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
*/