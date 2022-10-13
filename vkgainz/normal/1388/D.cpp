#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[200001];
ll ans;
int a[200001];
vector<int> pos;
vector<int> other;
ll dfs(int curr,int par){
    ll ret = a[curr];
    for(int next : adj[curr]){
        if(next!=par){
            ret+=dfs(next,curr);
        }
    }
    ans+=ret;
    if(ret>0) pos.push_back(curr);
    else other.push_back(curr);
    return max(ret,0LL);
}
int main(){
    int n; cin >> n;
    int b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(b[i]>0){
            --b[i];
            adj[i].push_back(b[i]);
            adj[b[i]].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]==-1){
            dfs(i,-1);
        }
    }
    cout << ans << endl;
    for(auto &it : pos) cout << (it+1) << " ";
    reverse(other.begin(),other.end());
    for(auto &it : other) cout << (it+1) << " ";
    cout << endl;
}