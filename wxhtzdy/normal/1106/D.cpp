#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
vector<int> E[N];
bool was[N];
int ans[N],sz=0;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    for(int i=0,u,v;i<m;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
    for(int i=1;i<=n;i++)sort(E[i].begin(),E[i].end());
    for(int i=1;i<=n;i++)was[i]=false;
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(1);
    was[1]=true;
    while(!q.empty()){
        int x=q.top();
        ans[sz++]=x;\
        q.pop();
        for(int c:E[x]){
            if(!was[c])q.push(c),was[c]=true;
        }
    }
    for(int i=0;i<sz;i++)printf("%i ",ans[i]);
    return 0;
}