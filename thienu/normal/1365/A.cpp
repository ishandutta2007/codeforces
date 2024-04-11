#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    set<int> used_rows;
    set<int> used_cols;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x){
                used_rows.insert(i);
                used_cols.insert(j);
            }
        }
    }
    int turns = min(n - used_rows.size(), m - used_cols.size());
    cout << (turns % 2 == 0 ? "Vivek" : "Ashish") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}