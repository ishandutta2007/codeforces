#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
struct node
{
    int tl;
    int tr;
    int pref;
    int suf;
    int val;
};
node t[4*maxn];
node merg(node u,node v)
{
    //cout<<"merg "<<u.tl<<' '<<u.tr<<' '<<u.pref<<' '<<u.suf<<' '<<u.val<<' '<<v.tl<<' '<<v.tr<<' '<<v.pref<<' '<<v.suf<<' '<<v.val<<endl;
    node ans;
    ans.tl=u.tl;ans.tr=v.tr;
    if(u.pref==(u.tr-u.tl))
    {
        ans.pref=u.pref+v.pref;
    }
    else
    {
        ans.pref=u.pref;
    }
    if(v.suf==(v.tr-v.tl))
    {
        ans.suf=u.suf+v.suf;
    }
    else
    {
        ans.suf=v.suf;
    }
    ans.val=(u.val+v.val-(u.suf*(u.suf+1))/2-(v.pref*(v.pref+1))/2+((u.suf+v.pref)*(u.suf+v.pref+1))/2);
    return ans;
}
void to(int node1,int pos,int val)
{
    int tl=t[node1].tl;int tr=t[node1].tr;
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1)
    {
        if(val==0)
        {
            node u;
            u.tl=tl;u.tr=tr;u.pref=0;u.suf=0;u.val=0;
            t[node1]=u;
            return;
        }
        else
        {
            node u;
            u.tl=tl;u.tr=tr;u.pref=1;u.suf=1;u.val=1;
            t[node1]=u;
            return;
        }
    }
    to(2*node1+1,pos,val);to(2*node1+2,pos,val);
    t[node1]=merg(t[2*node1+1],t[2*node1+2]);
}
void build(int node1,int tl,int tr)
{
    node u;
    u.tl=tl;u.tr=tr;u.pref=0;u.suf=0;u.val=0;
    t[node1]=u;
    if((tr-tl)==1) return;
    int tm=(tl+tr)/2;
    build(2*node1+1,tl,tm);build(2*node1+2,tm,tr);
}
node get(int node1,int l,int r)
{
    //cout<<node1<<' '<<t[node1].tl<<' '<<t[node1].tr<<' '<<l<<' '<<r<<endl;
    int tl=t[node1].tl;int tr=t[node1].tr;
    if(tl>=l && tr<=r) return t[node1];
    if(tl>=r || tr<=l) {node u;u.tl=tl;u.tr=tr;u.pref=0;u.suf=0;u.val=0;return u;}
    //cout<<2*node1+1<<' '<<2*node1+2<<endl;
    node ans1=get(2*node1+1,l,r);node ans2=get(2*node1+2,l,r);
    return merg(ans1,ans2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //node z1={0,3,1,1,2};node z2={3,6,1,1,2};
    //node h=merg(z1,z2);
    //cout<<h.tl<<' '<<h.tr<<' '<<h.pref<<' '<<h.suf<<' '<<h.val<<endl;
    build(0,0,maxn);
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <vector <int> > v;
    for(int i=0;i<(n-1);++i) {v.push_back({i,a[i+1]>=a[i]});to(0,i,a[i+1]>=a[i]);}
    int t1=0;
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int pos,y;
            cin>>pos>>y;
            pos--;
            a[pos]=y;
            if(pos!=0)
            {
                to(0,pos-1,a[pos]>=a[pos-1]);
                v.push_back({pos-1,a[pos]>=a[pos-1]});
            }
            if(pos!=(n-1))
            {
                to(0,pos,a[pos+1]>=a[pos]);
                v.push_back({pos,a[pos+1]>=a[pos]});
            }
        }
        else
        {
            ++t1;
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<get(0,l,r).val+(r-l+1)<<'\n';
            v.push_back({l,r,t1});
        }
    }
    //vector <pair<int,int> > res=go(v,0,n);
   // for(auto h:res) cout<<h.second<<endl;
    return 0;
}