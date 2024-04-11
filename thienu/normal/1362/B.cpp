#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }
    set<int> pos;
    for(int i : v){
        for(int j : v){
            if(i != j)
                pos.insert(i ^ j);
        }
    }

    int mini = 1e9 + 5;
    for(int k : pos){
        if(k > mini) continue;
        set<int> done;
        bool ok = true;
        for(int i : v){
            int next = i ^ k;
            if(s.find(next) == s.end()){
                ok = false;
                break;
            }
            if(done.find(next) != done.end()){
                ok = false;
                break;
            }
            done.insert(next);
        }
        if(ok){
            mini = k;
        }
    }
    if(mini == 1e9 + 5){
        cout << -1 << endl;
    }
    else{
        cout << mini << endl;
    }
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