#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int p[maxn];
struct query
{
    int typ;
    int l;
    int r;
};
int get(int x) {if(p[x]==x) return x;int ans=get(p[x]);p[x]=ans;return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) p[i]=i;
    int t;
    cin>>t;
    vector <query> que;
    while(t--)
    {
        int typ;
        cin>>typ;
        if(typ==1){int l;cin>>l;query q;q.typ=typ;q.l=l;q.r=(-1);que.push_back(q);}
        else {int l,r;cin>>l>>r;query q;q.typ=typ;q.l=l;q.r=r;que.push_back(q);}
    }
    reverse(que.begin(),que.end());
    vector <int> ans;
    for(auto h:que)
    {
        if(h.typ==2)
        {
            p[h.l]=p[h.r];
        }
        else
        {
            ans.push_back(p[h.l]);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto h:ans) cout<<h<<' ';
    return 0;
}