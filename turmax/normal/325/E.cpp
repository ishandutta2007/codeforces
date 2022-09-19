#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
bool used[maxn];int nxt[maxn];int pr[maxn];
int get(int x)
{
    if(pr[x]==(-1)) return x;
    int ans=get(pr[x]);pr[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return;
    pr[x]=y;
}
int32_t main()
{
    for(int i=0;i<maxn;++i) pr[i]=(-1);
    int n;cin>>n;if(n%2==1) {cout<<(-1);return 0;}
    int cur=0;vector<int> ans;int cur1=0;
    for(int cur1=0;cur1<n;++cur1)
    {
        if(used[cur1]) continue;
        int cur=cur1;
        while(true)
        {
        if(used[cur]) break;
        used[cur]=true;
        if(!used[(2*cur)%n]) {nxt[cur]=(2*cur)%n;cur=nxt[cur];continue;}
        else if(!used[(2*cur+1)%n]) {nxt[cur]=(2*cur+1)%n;cur=nxt[cur];continue;}
        else {nxt[cur]=cur1;cur=nxt[cur];continue;}
        }
    }
    for(int i=0;i<n;++i)
    {
        int x=i;int y=nxt[i];
        merg(x,y);
    }
    for(int i=0;i<n/2;++i)
    {
        if(get(i)!=get(i+n/2))
        {
            swap(nxt[i],nxt[i+n/2]);
            merg(i,i+n/2);
        }
    }
    vector<int> res;{int cur=0;
    while(true)
    {
        res.push_back(cur);cur=nxt[cur];if(cur==0) break;
    }}
    res.push_back(0);
    for(auto h:res) cout<<h<<' ';
    return 0;
}