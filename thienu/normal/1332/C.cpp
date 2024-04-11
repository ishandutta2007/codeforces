#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int maximum_value(unordered_map<char, int> m){
    int maxi = 0;
    for(auto& it : m){
        maxi = max(maxi, it.second);
    }
    return maxi;
}

void solve(){
    int n, k;
    cin >> n >> k;
    char s[n];
    cin >> s;
    int repeats = n / k;
    int total = 0;
    for(int i = 0; i < k/2; i++){
        unordered_map<char, int> count;
        for(int j = 0; j < repeats; j++){
            count[s[j*k+i]]++;
            count[s[(j+1)*k-i-1]]++;
        }
        total += 2 * repeats - maximum_value(count);
    }
    if(k % 2 == 1){
        unordered_map<char, int> count;
        for(int j = 0; j < repeats; j++){
            count[s[j*k+(k/2)]]++;
        }
        total += repeats - maximum_value(count);
    }
    cout << total << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}