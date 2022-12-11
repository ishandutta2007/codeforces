#include <iostream>

using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    unsigned long long ans = 1;
    while (ans <= n) {
        ans *= 2;
    }
    ans--;
    cout << ans << endl;
    return 0;
    
}