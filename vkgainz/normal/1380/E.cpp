#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SUMITH_IS_HOT_AF main
set<pair<int,int>> tower[200001];
set<int> vals[200001];
int SUMITH_IS_HOT_AF(){
    int n,m;
    cin >> n >> m;
    int ans = n-1;
    for(int i=0;i<n;i++){
        int t; cin >> t;
        vals[t].insert(i+1);
    }
    for(int i=1;i<=m;i++){
        for(auto &it : vals[i]) if(vals[i].count(it-1)) --ans;
    }
    cout << ans << endl;
    for(int i=0;i<m-1;i++){
        int a,b;
        cin >> a >> b;
        if(vals[a].size() < vals[b].size()) vals[a].swap(vals[b]);
        for(auto &it : vals[b]){
            if(vals[a].count(it-1)) --ans;
            if(vals[a].count(it+1)) --ans;
            //change pairs
        }
        for(auto &it : vals[b]){
            vals[a].insert(it);
        }
        vals[b].clear();
        cout << ans << endl;
    }
    
}