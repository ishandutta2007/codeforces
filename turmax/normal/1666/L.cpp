#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector<int> a[maxn];int t[maxn];int pr[maxn];queue<int> q;
vector<int> go(int x,int s)
{
    vector<int> ans;
    while(x!=(-1))
    {
        ans.push_back(x);
        x=pr[x];
    }
    reverse(ans.begin(),ans.end());return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,s;cin>>n>>m>>s;--s;
    for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);}
    for(int i=0;i<n;++i) {t[i]=(-1);} pr[s]=(-1);
    for(int v:a[s]) {q.push(v);pr[v]=s;t[v]=v;}
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int v:a[x])
        {
            if(v==s) continue;
            if(t[v]==t[x]) continue;
            if(t[v]==(-1))
            {
                t[v]=t[x];pr[v]=x;q.push(v);continue;
            }
            vector<int> ans1=go(x,s);vector<int> ans2=go(v,s);
            ans1.push_back(v);
            cout<<"Possible"<<'\n';
            cout<<ans1.size()<<'\n';for(auto h:ans1) cout<<h+1<<' '; cout<<'\n';
            cout<<ans2.size()<<'\n';for(auto h:ans2) cout<<h+1<<' '; return 0;
        }
    }
    cout<<"Impossible";
    return 0;
}