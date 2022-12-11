#include <bits/stdc++.h>
#define int long long

using namespace std;

map <vector <signed>, int> cnt;
vector <int> prime;

bool is_prime(signed x) {
    for (signed i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void init() {
    for (int i = 2; i <= 1007; i++)
        if (is_prime(i))
            prime.push_back(i);
}

void fact(signed n) {
    vector <signed> cur;
    for (signed elem : prime) {
        if (elem * elem > n)
            break;
        if (n % elem == 0) {
            signed cnt = 0;
            while (n % elem == 0) {
                n /= elem;
                cnt++;
            }
            if (cnt & 1)
                cur.push_back(elem);
        }
    }
    if (n != 1)
        cur.push_back(n);
    cnt[cur]++;
}

void solve() {
    int n;
    cin >> n;
    cnt.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fact(x);
    }
    int q;
    cin >> q;
    int res0 = 0, res1 = 0;
    for (auto elem : cnt) res0 = max(res0, elem.second);
    res1 = res0;
    vector <signed> empt;
    int cnt0 = cnt[empt];
    for (auto elem : cnt) {
        if (elem.second % 2 == 0 && elem.first != empt)
            cnt0 += elem.second;
    }
    res1 = max(res1, cnt0);
    for (int i = 0; i < q; i++) {
        int tm;
        cin >> tm;
        if (tm == 0)
            cout << res0 << "\n";
        else
            cout << res1 << "\n";
    }
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}