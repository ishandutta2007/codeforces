#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
ll push[300001];
vector<int> adj[300001];
vector<pair<pair<int,int>,int>> queries[300001];
int depth[300001];
ll currSum;
ll add[300005];
void dfs(int curr=0, int par=-1){
    if(par!=-1) depth[curr]=depth[par]+1;
    for(int next : adj[curr])
        if(next!=par) dfs(next,curr);
}
void dfs2(int curr=0, int par=-1){
    for(pair<pair<int,int>,int> temp : queries[curr]){
        add[min(depth[curr]+temp.first.first,300004)]+=temp.first.second;  
        currSum+=temp.first.second;
    }
    push[curr] += currSum;
    //remove dead queries
    currSum-=add[depth[curr]];
    for(int next : adj[curr]){
        if(next!=par) dfs2(next,curr);
    }
    currSum+=add[depth[curr]];
    //get the erased queries back
    for(pair<pair<int,int>,int> temp : queries[curr]){
        add[min(depth[curr]+temp.first.first,300004)]-=temp.first.second;  
        currSum-=temp.first.second;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs();
    int m;
    scanf("%d",&m);
    while(m--){
        int v,d,x;
        scanf("%d%d%d",&v,&d,&x);
        v--;
        if(d==0) push[v]+=x;
        else{
            queries[v].push_back(mp(mp(d,x),m));
        }
    }
    dfs2();
    for(int i=0;i<n;i++)
        printf("%lld\n",push[i]);
    
}