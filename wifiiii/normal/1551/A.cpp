#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 3 <= 1) cout << n - n / 3 * 2 << " " << n / 3 << '\n';
        else cout << n - (n / 3 + 1) * 2 << " " << n / 3 + 1 << '\n';
    }
}