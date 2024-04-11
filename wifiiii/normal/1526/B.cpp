#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2000];
int main() {
    int lim = 11 * 111;
    dp[0] = 1;
    for(int i : {11, 111, 1111}) {
        for(int j = i; j <= lim; ++j) {
            dp[j] |= dp[j-i];
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        if(x >= lim) cout << "YES" << endl;
        else cout << (dp[x] ? "YES" : "NO") << endl;
    }
}