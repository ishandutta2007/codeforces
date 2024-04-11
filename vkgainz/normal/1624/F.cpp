#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <set>

using namespace std;

int query(int c) {
    cout << "+ " << c << "\n";
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

int main() {
    int n; cin >> n;
    int clo = 1, chi = n - 1;
    for (int j = 0; j < 10; j++) {
        if (clo == chi) break;
        int mid = (clo % n + chi % n + 1) / 2;
        int mult = clo / n;
        int nxt = query(n - mid);
        if (nxt == mult) {
            //x + mid < n
            chi = mult * n + mid - 1;
        } else {
            //x + mid >= n
            clo = mult * n + mid;
        }
        clo += n - mid, chi += n - mid;
    }
    cout << "! " << clo << "\n";
}