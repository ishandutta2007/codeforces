#include <bits/stdc++.h>
using namespace std;
int n;
set<int> order;
vector<pair<int, int>> vec;
vector<int> graph[500005];
set<int> cover;
int idx[1000010];
void dfs(int curr,int par){
    cover.insert(curr);
    for(int next : graph[curr]){
        if(next!=par && cover.find(next)==cover.end()){
            dfs(next,curr);
        }
    }
}
void solve(){
    sort(vec.begin(),vec.end());
    int curr = 1;
    bool work = true;
    int num = 0;
    for(int i=0;i<n;i++){
        curr =vec[i].first;
        auto it = order.begin();
        while(it != order.end() && *it<curr){
            order.erase(it++);
        
        }
        it = order.begin();
        order.insert(vec[i].second);
        while(it != order.end() && *it<vec[i].second){
            num++;
            
            graph[idx[vec[i].second]].push_back(idx[*it]);
            graph[idx[*it]].push_back(idx[vec[i].second]);
            it++;
        }
        if(num>n-1){
            work = false;
            break;
        }
        
    }
    if(num!=n-1 || !work){
        cout << "NO" << endl;
        
    }
    else{
        dfs(0,-1);
        if(cover.size()!=n){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}

   
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        vec.push_back({l,r});
        idx[l] = i; idx[r] = i;
    }
    solve();
}