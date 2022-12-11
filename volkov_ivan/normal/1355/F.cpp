#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e9, INF = 1e18;
vector <int> pr; 

bool check(int a, int b) {
    long double aa = sqrt(a), bb = sqrt(b);
    if (aa * bb > N + 7) return 0;
    if (a * b > INF) return 0;
    return 1;
}

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve() {
    vector <pair <int, int>> our;
    int cnt = 0;
    for (int i = 0; i < (int) pr.size(); i++) {
        int j = i;
        cnt++;
        int cur = 1;
        while (j != (int) pr.size()) {
            if (!check(cur, pr[j])) break;
            cur *= pr[j];
            j++;
        }
        cout << "? " << cur << endl;
        int res;
        cin >> res;
        for (int k = i; k < j; k++) {
            if (res % pr[k] == 0) our.push_back({pr[k], 0});
        }
        i = j - 1;
    }
    //cout << cnt << endl;
    for (int i = 0; i < min((int) our.size(), 8ll); i += 4) {
        int cur = 1; 
        for (int j = i; j < min((int) our.size(), i + 4); j++) {
            int cur2 = 1;
            while (cur2 * cur2 < N) {
                cur2 *= our[j].first;
            }
            cur2 /= our[j].first;
            cur *= cur2;
        }
        cout << "? " << cur << endl;
        int res;
        cin >> res;
        for (int j = i; j < min((int) our.size(), i + 4); j++) {
            while (res % our[j].first == 0) {
                our[j].second++;
                res /= our[j].first;
            }
        }
    }
    int ans = 1;
    for (auto elem : our) ans *= (elem.second + 1);
    if (ans <= 2) cout << "! " << ans + 7 << endl;
    else cout << "! " << ans * 2 << endl;
}

signed main() {
    for (int i = 2; i * i * i <= N / 4; i++) {
        if (is_prime(i)) pr.push_back(i);
        //cout  << i << endl;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}