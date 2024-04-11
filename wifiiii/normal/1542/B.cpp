#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int a, int b) {
    ll x = 1;
    while(x <= n) {
        if((n - x) % b == 0) return 1;
        x = x * a;
        if(a == 1) return 0;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << (solve(n, a, b) ? "Yes" : "No") << endl;
    }
}