#include <bits/stdc++.h>

using namespace std;

int main() {

    long long limT, n, A, B, k;
    cin >> limT >> n >> A >> B >> k;
    if (k > n) {
        cout << 0;
        return 0;
    }
    long long nA = (n + 1) / 2, nB = n / 2; 
    if (A > B) {
        swap(nA, nB);
        swap(A, B);
    }

    if (k <= nB) {
        cout << min(limT, (nB * B + nA * A) / k); 
        return 0;
    }

    long long L = 1, R = B;
    while (L <= R) {
        long long mid = (L + R) / 2;
        long long desA = mid * (k - nB);
        if (desA > A * nA) {
            R = mid - 1;
            continue;
        }
        if (A - (desA + nA - 1) / nA <= B - mid) L = mid + 1;
        else R = mid - 1;
    }
    
    long long ans = R;
    long long remA = A * nA - R * (k - nB);
    long long rA = remA / nA, modA = remA % nA;
    
    ans += (modA + (nA + nB) * rA) / k; 
    ans = min(ans, limT);
    cout << ans;
}