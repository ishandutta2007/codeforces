#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+7;
static int t[4*maxn];
static int delay[4*maxn];
inline void push(int node)
{
    t[2*node+1]+=delay[node];t[2*node+2]+=delay[node];
    delay[2*node+1]+=delay[node];delay[2*node+2]+=delay[node];
    delay[node]=0;
    t[node]=min(t[2*node+1],t[2*node+2]);
}
inline void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tl>=l && tr<=r)
    {
        t[node]+=val;
        delay[node]+=val;
        return;
    }
    int val1=delay[node];
    t[2*node+1]+=val1;t[2*node+2]+=val1;
    delay[2*node+1]+=val1;delay[2*node+2]+=val1;
    delay[node]=0;
    t[node]=min(t[2*node+1],t[2*node+2]);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
inline int get(int node,int tl,int tr,int pos)
{
    if((tr-tl)==1)
    {
        return t[node];
    }
    int val=delay[node];
    t[2*node+1]+=val;t[2*node+2]+=val;
    delay[2*node+1]+=val;delay[2*node+2]+=val;
    delay[node]=0;
    t[node]=min(t[2*node+1],t[2*node+2]);
    int tm=(tl+tr)/2;
    if(pos<tm) return get(2*node+1,tl,tm,pos);
    else return get(2*node+2,tm,tr,pos);
}
int sz;
long long go(vector <int> a)
{
    vector <pair<int,int> > b;
    int n=a.size();
    /*int o=0;
    for(int i=0;i<n;++i) for(int j=(i+1);j<n;++j) if(a[j]<a[i]) ++o;
    cout<<o<<" o "<<endl;*/
    sz=(n+5);
    for(int i=0;i<n;++i) b.push_back({a[i],i});
    sort(b.begin(),b.end());
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=get(0,0,sz,b[i].second);
        to(0,0,sz,0,b[i].second,1);
    }
    for(int i=0;i<4*sz;++i) {t[i]=0;delay[i]=0;}
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    /*cout<<go({1,2,3,4})<<endl;
    cout<<go({4,2,4,1})<<endl;
    cout<<go({7,3,9,2,5,3,4,3,5,6,4})<<endl;*/
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        sz=n+5;
        vector <int> a(n);vector <int> b(m);
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<m;++i) cin>>b[i];
        long long ans=go(a);
        //cout<<t[0]<<" t[0] "<<endl;
        //cout<<ans<<" ans0 "<<endl;
        sort(b.begin(),b.end());
        int z[n];
        vector <int> h[m+1];
        vector <int> u[m];
        for(int i=0;i<n;++i)
        {
            z[i]=upper_bound(b.begin(),b.end(),a[i])-b.begin();
            if(z[i]!=0 && b[z[i]-1]==a[i])
            {
                u[z[i]-1].push_back(i);
            }
            h[z[i]].push_back(i);
        }
        //for(int i=0;i<n;++i) cout<<i<<" i "<<z[i]<<" z[i] "<<endl;
        for(int i=0;i<n;++i)
        {
            to(0,0,sz,0,i+1,1);
        }
        int lans=(-1);
        for(int i=m-1;i>=0;--i)
        {
            if(i!=(m-1) && b[i]==b[i+1])
            {
                //cout<<lans<<" lans "<<endl;
                ans+=lans;
                continue;
            }
            for(auto l:h[i+1])
            {
                if(a[l]!=b[i])
                {
                    //cout<<l<<" l "<<endl;
                //cout<<i<<" i "<<l<<" l "<<endl;
                to(0,0,sz,0,l+1,-1);
                to(0,0,sz,l+1,sz,1);
                }
            }
            for(auto l:u[i])
            {
                //cout<<i<<" i1 "<<l<<" l "<<endl;
                //cout<<l<<" l1 "<<endl;
                to(0,0,sz,0,l+1,-1);
            }
            //cout<<t[0]<<" t[0] "<<endl;
            lans=t[0];
            ans+=t[0];
            for(auto l:u[i])
            {
                to(0,0,sz,l+1,sz,1);
            }
        }
        cout<<ans<<'\n';
        for(int i=0;i<4*sz;++i) {t[i]=0;delay[i]=0;}
    }
    return 0;
}