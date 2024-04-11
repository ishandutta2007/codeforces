//Submitting someone else's code so that Lockout bot knows I tested this contest

#include<bits/stdc++.h>
using namespace std;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n;
    cin >> n;
    vector<int> all;
    for(int i = 1;i <= n;i++)all.push_back(i);
    shuffle(all.begin(),all.end(),rng);
    for(int i = 0;i < n;i++){
        cout << all[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}