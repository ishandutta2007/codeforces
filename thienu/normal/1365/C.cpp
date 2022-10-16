#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> diffs(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        diffs[a[i]] += i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
        diffs[b[i]] -= i;
        diffs[b[i]] = (diffs[b[i]] + n) % n;
    }

    // for(int i : diffs){
    //     cout << i << " ";
    // }
    // cout << endl;

    u_map<int, int> cnt;
    for(int i = 0; i < n; i++){
        cnt[diffs[i]]++;
    }
    int maxi = 0;
    for(auto i : cnt){
        maxi = max(maxi, i.second);
    }
    cout << maxi << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}