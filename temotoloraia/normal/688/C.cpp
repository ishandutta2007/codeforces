#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define N 100005
using namespace std;
int n,m,u,v,i,j,p,fix[N],k,aa;
vector<int>g[N];
queue<int>Q;
int main()
{
    cin>>n>>m;
    while (m--){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (i=1;i<=n && p==0;i++)
        if (fix[i]==0 && g[i].size()>0){
        while (Q.size()>0)Q.pop();
        Q.push(i);
        fix[i]=1;
        while (Q.size()>0 && p==0){
            k=Q.front();
            Q.pop();
            for (j=0;j<g[k].size() && p==0;j++){
                if (fix[g[k][j]]==3-fix[k])continue;
                if (fix[g[k][j]]==fix[k]){p=1;continue;}
                fix[g[k][j]]=3-fix[k];
                Q.push(g[k][j]);
            }
        }
    }
    if (p==1){cout<<-1<<endl;return 0;}
    for (i=1;i<=n;i++)
        if (fix[i]==1)aa++;
    cout<<aa<<endl;
    for (i=1;i<=n;i++)
        if (fix[i]==1)cout<<i<<" ";
    cout<<endl;
    aa=0;
    for (i=1;i<=n;i++)
        if (fix[i]==2)aa++;
    cout<<aa<<endl;
    for (i=1;i<=n;i++)
        if (fix[i]==2)cout<<i<<" ";
    return 0;
}