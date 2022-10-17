#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> dp(101);
    dp[0] = 1;
    for(int i = 6; i <= 100; ++i) dp[i] |= dp[i-6];
    for(int i = 8; i <= 100; ++i) dp[i] |= dp[i-8];
    for(int i = 10; i <= 100; ++i) dp[i] |= dp[i-10];
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n > 100) n = (n + 1) / 2 * 2;
        else while(!dp[n]) ++n;
        cout << n * 5 / 2 << endl;
    }
}