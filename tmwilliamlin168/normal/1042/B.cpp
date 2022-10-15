#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int n, dp[8]={0, INF, INF, INF, INF, INF, INF, INF}, a, b;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> a >> s;
        b=0;
        for(char c : s)
            b|=1<<(c-'A');
        for(int i=0; i<7; ++i)
            dp[i|b]=min(dp[i]+a, dp[i|b]);
    }
    cout << (dp[7]>=INF?-1:dp[7]);
}