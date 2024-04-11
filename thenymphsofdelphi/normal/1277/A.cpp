#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 2e5 + 5;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--){
        string s; cin >> s;
        int n = s.length();
        int ans = (n - 1) * 9;
        for (int i = 1; i <= 9; i++){
            string t = "";
            for (int j = 1; j <= n; j++){
                t += (char)(i + '0');
            }
            if (s >= t) ans++;
            else break;
        }
        cout << ans << endl;
    }
}