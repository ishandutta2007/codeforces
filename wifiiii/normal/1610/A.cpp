#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = 2;
        if(n == 1) --ans;
        if(m == 1) --ans;
        cout << ans << '\n';
    }
}