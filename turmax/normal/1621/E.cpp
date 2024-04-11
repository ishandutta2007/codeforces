#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int t[4*maxn];
int mi2[4*maxn];
void build(int sz) {for(int i=0;i<4*sz;++i) {t[i]=0;mi2[i]=0;}}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1)
    {
        t[node]+=val;mi2[node]=min(0LL,t[node]);
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=t[2*node+1]+t[2*node+2];
    mi2[node]=min(mi2[2*node+2],t[2*node+2]+mi2[2*node+1]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(),a.end());reverse(a.begin(),a.end());while(a.size()>m) a.pop_back();
        sort(a.begin(),a.end());
        int sum[m]={0};
        int sz[m]={0};
        vector <pair<int,int> > que;
        for(int i=0;i<m;++i)
        {
            int c;cin>>c;sz[i]=c;
            //cout<<i<<" i "<<sz[i]<<" sz[i] "<<endl;
            vector <int> v;
            for(int j=0;j<c;++j) {int x;cin>>x;sum[i]+=x;v.push_back(x);que.push_back({i,x});}
        }
        int sz1=m+1;
        build(sz1);
        for(int i=0;i<m;++i)
        {
            to(0,0,sz1,i,1);
        }
        for(int i=0;i<m;++i)
        {
            int o=sum[i];int r=(o+sz[i]-1)/sz[i];int d=lower_bound(a.begin(),a.end(),r)-a.begin();
            to(0,0,sz1,d,-1);
        }
        string ans;
        for(auto h:que)
        {
            int i=h.first;
            int o=sum[i];int r=(o+sz[i]-1)/sz[i];int d=lower_bound(a.begin(),a.end(),r)-a.begin();
            to(0,0,sz1,d,1);
            int val=h.second;
            sum[i]-=val;sz[i]--;
            int o1=sum[i];
            int r1=(o1+sz[i]-1)/sz[i];
            int d1=lower_bound(a.begin(),a.end(),r1)-a.begin();
            ++sz[i];sum[i]+=val;
            to(0,0,sz1,d1,-1);
            if(mi2[0]>=0) ans.push_back('1');
            else ans.push_back('0');
            to(0,0,sz1,d1,1);
            to(0,0,sz1,d,-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}