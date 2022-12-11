#include <bits/stdc++.h>
#define int long long

using namespace std;

unordered_map <int, vector <int>> mp;

const int N = 4e5 + 7;

vector <int> fact(int n) {
    int i = 2;
    vector <int> res;
    while (i * i <= n) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
        i++;
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    set <int> now;
    for (int i = 0; i < min(n, 3ll); i++) {
        vector <int> kek = fact(a[i]);
        for (int elem : kek) now.insert(elem);
    }
    int ans = 1;
    for (int elem : now) {
        int mini = N, secmini = N;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            int now = a[i];
            while (now % elem == 0) {
                now /= elem;
                cur++;
            }
            if (cur < mini) {
                secmini = mini;
                mini = cur;
            } else {
                if (cur < secmini) {
                    secmini = cur;
                }
            }
        }
        for (int j = 0; j < secmini; j++) {
            ans *= elem; 
        }
    }
    cout << ans << endl;
    return 0;
}