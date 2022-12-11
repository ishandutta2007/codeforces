#include <iostream>
 
using namespace std;

const int MAX_N = 1e5 + 5;
long long pref[MAX_N + 1], V[MAX_N + 1], T[MAX_N + 1], eps[MAX_N + 1], ans[MAX_N + 1];
long long n;

long long my_bs(long long num) {
    long long l = num - 1, r = n + 1, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (pref[m] - pref[num - 1] >= V[num]) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
        eps[i] = 1;
        ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + T[i];
    }
    long long last;
    for (int i = 1; i <= n; i++) {
        last = my_bs(i);
        eps[last]--;
        ans[last] += V[i] - (pref[last - 1] - pref[i - 1]);
    }
    long long now = 0;
    for (int i = 1; i <= n; i++) {
        now += eps[i];
        ans[i] += T[i] * now;
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}