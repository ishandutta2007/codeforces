#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n % k == 0) cout << 1 << endl;
        else cout << max(2, (k + n - 1) / n) << endl;
    }
}