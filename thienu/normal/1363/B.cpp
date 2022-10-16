#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ones(n+1, 0);
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            ones[i+1] = ones[i] + 1;
        }
        else{
            ones[i+1] = ones[i] - 1;
        }
    }
    int mini = 1e9 + 5;
    for(int i = 0; i <= n; i++){
        mini = min(mini, (i-ones[i])/2 + (n-i+(ones[n] - ones[i])) / 2);
        mini = min(mini, n-((i-ones[i])/2 + (n-i+(ones[n] - ones[i])) / 2));
    }

    //  -((ones[n] - ones[i]) - (n-i))/2
    cout << mini << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}