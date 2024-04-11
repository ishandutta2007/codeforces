#include <bits/stdc++.h>
using namespace std;
int freq[200000];
bool visited[200000];
map<pair<int,int>,pair<int,int>> sign;
vector<int> adj[200000];
vector<int> in;
vector<int> ans;
void dfs(int i){
    visited[i] = true;
    in.push_back(i);
    for(int next : adj[i]){
        if(!visited[next]) dfs(next);
    }
}
void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        freq[i] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
        freq[a[i]]++;
    }
    int b[n];
    for(int i=0;i<n;i++){
        cin >> b[i];
        b[i]--;
        freq[b[i]]++;
    }
    sign.clear();
    for(int i=0;i<n;i++){
        adj[i].clear();
    }
    bool work = true;
    for(int i=0;i<n;i++){
        if(freq[i]!=2){
            work = false;
        }
    }
    if(!work) {
        cout << -1 << endl;
        return;
    }
    for(int i=0;i<n;i++) visited[i] = false;
    ans.clear();
    for(int i=0;i<n;i++){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        auto x = make_pair(a[i],b[i]);
        auto y = make_pair(b[i],a[i]);
        if(sign[x].second!=0 || sign[y].second!=0){
            if(sign[x].second==1 && sign[y].second==-1){
                ans.push_back(i);
            }
            visited[a[i]] = true;
            visited[b[i]] = true;
        }
        sign[make_pair(a[i],b[i])] = {i,1};
        sign[make_pair(b[i],a[i])] = {i,-1};
        
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            in.clear();
            dfs(i);
            int x =0,y =0;
            for(int j=0;j<in.size();j++){
                auto temp = sign[make_pair(in[j],in[(j+1)%in.size()])];
                if(temp.second==1) x++;
                else y++;
            }
            for(int j=0;j<in.size();j++){
                auto temp = sign[make_pair(in[j],in[(j+1)%in.size()])];
                if(x>y){
                    if(temp.second==-1) ans.push_back(temp.first);
                }
                else
                    if(temp.second==1) ans.push_back(temp.first);
            }

        }
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << (x+1) << " ";
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}