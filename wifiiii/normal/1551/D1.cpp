#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if(n % 2 == 0) {
            // put n / 2 * m vertical dominos
            if(k % 2 == 0 && k <= n * m / 2 - n / 2) {
                cout << "YES" << endl;
                continue;
            }
        }
        if(m % 2 == 0) {
            // put m / 2 * n horizontal dominos
            if((n * m / 2 - k) % 2 == 0 && k >= m / 2) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}