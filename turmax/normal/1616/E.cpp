#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int t[4*maxn];
void build(int sz)
{
    for(int i=0;i<4*sz;++i) t[i]=0;
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1) {t[node]=val;return;}
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=t[2*node+1]+t[2*node+2];
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t[node];
    if(tl>=r || tr<=l) return 0;
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r)+get(2*node+2,tm,tr,l,r);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sz=n+2;build(sz);
        for(int i=0;i<n;++i) to(0,0,sz,i,1);
        string s,t;cin>>s>>t;
        if(s<t) {cout<<0<<endl;continue;}
        int res=1e18;
        int cnt[26];for(int i=0;i<26;++i) cnt[i]=2e18;
        for(int i=0;i<s.size();++i) cnt[s[i]-'a']=min(cnt[s[i]-'a'],i);
        int ans=0;
        int l=0;int r=0;bool ok[n];for(int i=0;i<n;++i) ok[i]=true;
        while(r!=n)
        {
            if(s[l]<t[r])
            {
                res=min(res,ans);break;
            }
            for(int j=0;j<t[r]-'a';++j)
            {
                if(cnt[j]<n) res=min(res,ans+get(0,0,sz,l,cnt[j]));
            }
            int d=cnt[t[r]-'a'];
            if(d>=n)
            {
                break;
            }
            cnt[t[r]-'a']=2e18;
            for(int i=d+1;i<n;++i) if(s[i]==t[r]) {cnt[t[r]-'a']=i;break;}
            ans+=get(0,0,sz,l,d);
            //cout<<l<<" l "<<d<<" d "<<endl;
            ok[d]=false;
            to(0,0,sz,d,0);
            ++r;while(!ok[l]) ++l;
        }
        if(res==1e18) cout<<(-1)<<endl;
        else cout<<res<<endl;
    }
    return 0;
}