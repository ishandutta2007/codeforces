/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+1]={0},b[n+1]={0};
    vector<int> adj[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int z;
        cin>>z;
        adj[z].push_back(i+1);
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==0)
        {
            a[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(vector<int>::iterator it = adj[i].begin();it!=adj[i].end();it++)
        {
            if(a[(*it)]==1)
            {
                b[i]++;
            }
        }
    }
    bool c=1;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>0 && b[i]<3)
        {
            c=0;
            break;
        }
        if(b[i]==0 && adj[i].size()>0)
        {
            c=0;
            break;
        }
    }
    if(c==1)
    {
        cout<<"Yes";
    }
    else 
    {
        cout<<"No";
    }
    return 0;
}