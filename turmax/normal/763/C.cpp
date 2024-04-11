#include <bits/stdc++.h>

using namespace std;
#define int long long
mt19937 rnd;
vector<int> a;
map<int,int> cnt,cnt1;
set<int> was;
int n,p;
pair<int,int> slv(vector<int> a)
{
    for(int i=1;i<n;++i) cnt[a[i]]++;
    int t1=clock();
    if(n==1)
    {
        return {a[0],1};
    }
    if(n==p)
    {
        return {a[0],1};
    }
    int cyc=0;
    while(cyc%2000!=0 || clock()-t1<1.5*CLOCKS_PER_SEC)
    {
        ++cyc;
        int id=rnd()%n;
        if(id==0) continue;
        int d=a[id]-a[0];d%=p;d+=p;d%=p;
        if(was.count(d)) continue;
        was.insert(d);
        int x=a[0];int ans=0;
        while(true)
        {
            x+=d;x%=p;
            if(!cnt[x]) break;
            ++ans;
        }
        x=a[0];
        int mi=a[0];
        while(true)
        {
            x-=d;x+=p;x%=p;
            if(!cnt[x]) break;
            mi=x;
            ++ans;
        }
        if(ans==(n-1))
        {
            return {mi,d};
        }
    }
    return {-1,-1};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(888);
    cin>>p>>n;a.resize(n);for(int i=0;i<n;++i) {cin>>a[i];cnt1[a[i]]++;}
    if(n==1)
    {
        cout<<a[0]<<' '<<0;
        return 0;
    }
    if(2*n<p || n==p)
    {
        pair<int,int> ans=slv(a);
        if(ans.first==(-1)) {cout<<(-1);return 0;}
        else cout<<ans.first<<' '<<ans.second<<endl;
        return 0;
    }
    else
    {
        vector<int> ans1;
        for(int i=0;i<p;++i)
        {
            if(!cnt1[i])
            {
                ans1.push_back(i);
            }
        }
        n=ans1.size();
        pair<int,int> res=slv(ans1);
        if(res.first==(-1)) {cout<<(-1);return 0;}
        res.first-=res.second;res.second=p-res.second;
        res.first+=p;res.first%=p;res.second%=p;
        cout<<res.first<<' '<<res.second;
        return 0;
    }
    return 0;
}