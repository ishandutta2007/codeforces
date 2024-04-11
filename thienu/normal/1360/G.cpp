#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n * a == m * b){
        cout << "YES" << endl;
        int period = __gcd(n, m);
        int per_period = a * period / m;
        string s = "";
        for(int i = 0; i < m/period; i++){
            for(int j = 0; j < per_period; j++){
                s += "1";
            }
            for(int j = 0; j < period-per_period; j++){
                s += "0";
            }
        }
        for(int i = 0; i < n; i++){
            cout << s << endl;
            s = s.substr(1, s.size()-1) + s[0];
        }
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}