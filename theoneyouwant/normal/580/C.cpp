/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
using namespace std;

static int counter=0;

int dfs(int m1,int s, int n, bool visited[], int cats[], vector<int> adj[],bool a2[],int m)
{
    if(visited[s])
    {
        return 0;
    }
    cats[s]=cats[m1];
    if(a2[s]==1)
    {
        cats[s]++;
    }
    else
    {
        cats[s]=0;
    }
    visited[s]=1;
    if(cats[s]>m)
    {
        return 1;
    }
    int f1=0;
    for(auto u:adj[s])
    {
        f1+= dfs(s,u,n,visited,cats,adj,a2,m);
    }
    if(f1==0 && cats[s]<=m)
    {counter++;}
    
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int cats[n+1]={0};
    cats[0]=0;
    vector<int> adj[n+1];
    bool a2[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a2[i+1];
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool visited[n+1]={0};
    visited[0]=1;
    int z1=1;
    dfs(0,z1,n,visited,cats,adj,a2,m);
    cout<<counter;
    return 0;
}