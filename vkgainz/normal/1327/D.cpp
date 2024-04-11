#include <bits/stdc++.h>
using namespace std;
bool visited[200001];
vector<int> adj[200001];
vector<int> in;
int cnt = 0;
int c[200001];
int x;
bool works(int i){
    for(int a=0;a<i;a++){
        int col = c[in[a]];
        bool work = true;
        for(int b=a;b<x && work;b+=i){
            if(c[in[b]] != col){
                work = false;
            }
        }
        if(work) return true;
    }
    return false;
}
int findMin(){
    x = in.size();
    for(int i=1;i<=x;i++){
        if(x%i!=0){
            continue;
        }
        if(works(i)) return i;

    }
    return 2000000;
}
void dfs(int i){
    visited[i] = true;
    in.push_back(i);
    for(int next : adj[i]){
        if(!visited[next]){
            dfs(next);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[n];
        for(int i=0;i<n;i++){
            cin >> p[i];
            p[i]--;
        }
        for(int i=0;i<n;i++){
            cin >> c[i];
        }
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        for(int i=0;i<n;i++){
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
        int ret = n;
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        for(int a=0;a<n;a++){
            if(!visited[a]){
                cnt = 0;
                dfs(a);
                ret = min(ret,findMin());
                in.clear();
            }
        }
        cout << ret << endl;
    }
}