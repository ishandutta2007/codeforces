#include <bits/stdc++.h>

using namespace std;

long long solve(long long n) {
    long long save = n;
    long long d = -1;

    for(long long i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            d = i;
            while (n%i == 0)
                n /= i;

            return (n == 1) ? d : 1;
        }
    }
    
    return save;
}

int main() {
    long long n;
    cin >> n;

    cout << solve(n) << endl;
    
    return 0;
}