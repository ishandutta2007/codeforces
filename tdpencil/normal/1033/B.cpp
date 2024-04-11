#include <bits/stdc++.h>


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    auto isprime = [](int64_t x) {
        if(x == 1) return false;
        if(x == 2) return true;
        if(x == 3) return true;

        if(x % 2 == 0 || x % 3 == 0) return false;

        for(int64_t i = 5; i * i <= x; i += 6) {
            if(x % i == 0 || x % (i + 2) == 0) return false;
        }
        return true;
    };
    for(int tt=0; tt < T; tt++) {
        int64_t A, B;
        cin >> A >> B;
        if(A - B != 1) {
            cout << "NO\n";
            continue;
        }
        if(isprime(A + B)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}