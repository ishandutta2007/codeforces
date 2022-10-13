#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int> adj[200001];
int distleft[200001];
int distright[200001];
int numedge[200001];
int main(){
    int n; scanf("%d",&n);

    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int left= 0,right =0;
    int dist[200001];
    for(int i=0;i<n;i++) dist[i] = 1000000000;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(dist[x]>dist[left]) left = x;
        for(int next : adj[x]){
            if(dist[next]==1000000000){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<n;i++) dist[i] = 1000000000;
    dist[left] = 0;
    q.push(left);
    right = left;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        distleft[x] = dist[x];
        if(dist[x]>dist[right]) right = x;
        for(int next : adj[x]){
            if(dist[next]==1000000000){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<n;i++) dist[i] = 1000000000;
    dist[right] = 0;
    q.push(right);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        distright[x] = dist[x];
        for(int next : adj[x]){
            if(dist[next]==1000000000){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<n;i++) numedge[i] = 1000000000;
    numedge[left] = 0;
    q.push(left);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int next : adj[x]){
            if(numedge[next]==1000000000){
                if(distleft[next]+distright[next]==distleft[right]){
                    numedge[next] = 0;
                }
                else{
                    numedge[next] = numedge[x]+1;
                }
                q.push(next);
            }
        }
    }
    int best = -1;
    int max = -1;
    for(int i=0;i<n;i++){
        if(i!=left && i!=right && numedge[i]>max){
            max = numedge[i];
            best = i;
        }
    }
    cout << numedge[best]+distleft[right] << endl;
    cout << left+1 << " " << right+1 << " " << best+1 << endl;
    

    
}