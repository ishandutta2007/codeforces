#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<int> adj[100001];
int flow[100001];
int nh[100001];
ll p[100001], h[100001],numBad[100001];
int n,m;
bool work = true;
void dfs(int curr,int par){
    int sumBad =0;
    bool leaf = true;
    flow[curr] = p[curr];
    for(int next : adj[curr]){
        if(next!=par){
            leaf = false;
            dfs(next,curr);
            sumBad+=numBad[next];
            flow[curr]+=flow[next];
        }
    }
    numBad[curr] = (flow[curr]-h[curr])/2;
    if((flow[curr]-h[curr])%2!=0 || numBad[curr]>flow[curr] || numBad[curr] < 0){
        work = false;
    }
    if(numBad[curr]-p[curr] > sumBad){
        work = false;
    }

            
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        for(int i=0;i<n;i++){
            cin >> h[i];
        }
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int x,y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            flow[i] =0 ;
            nh[i] = 0;
            numBad[i] = 0;
        }
        work = true;
        dfs(0,-1);
        if(!work){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }

    }
}