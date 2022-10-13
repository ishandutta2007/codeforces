#include <bits/stdc++.h>
using namespace std;
int n;;
int a[300001];
int ans[300001];
vector<int> f[300001];

void dfs(int curr,int par){
    
    for(int next : f[curr]){
        if(next!=par){
            dfs(next,curr);
        }
    }
    if(a[curr]==1){
        ans[curr] = 300001;
    }
    if(f[curr].size()==1&& curr !=0){
        ans[curr] = 1;
    }

    
    for(int next : f[curr]){
        if(next!=par){
            if(a[curr]==1){
                ans[curr] = min(ans[curr],ans[next]);
            }
            else {
                ans[curr]+=ans[next];
            }
        }
    }

}


void solve(){
    int nc = 0;
    for(int i=1;i<n;i++){
        if(f[i].size()==1){
            nc++;
        }
    }
    dfs(0,-1);
    int ret = nc-ans[0]+1;
    cout << ret << endl;
}


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        int p;
        cin >> p;
        p--;
        f[i+1].push_back(p);
        f[p].push_back(i+1);
    }
    solve();
}