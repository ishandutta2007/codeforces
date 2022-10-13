#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int shift = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] < b[(i + 1) % n]) {
            shift = (i + 1) % n;
            break;
        }
    }
    if (shift == -1) {
        //all are same
        if (accumulate(b.begin(), b.end(), 0) == 0LL) {
            cout << "YES" << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
            cout << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        cout << "YES" << "\n";
        vector<long long> a(n);
        long long sum = 0LL;
        long long k = 1e9;
        long long L = accumulate(b.begin(), b.end(), k * 1LL * b[shift]);
        for (int i = shift; i < shift + n; i++) {
            int idx = i % n;
            a[idx] = (idx == shift) ? b[idx] :
                L - sum;
            sum += (idx == shift) ? 0 : b[idx];
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}