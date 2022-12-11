#include <iostream>
#include <vector>
#include <cstring>
#define int long long

using namespace std;

const int M = 998244353;

int bin_pow(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x % M;
    if (n % 2 == 0) {
        int mem = bin_pow(x, n / 2);
        return (mem * mem) % M;
    }
    return (bin_pow(x, n - 1) * x) % M;
}

int obr(int x) {
    return bin_pow(x, M - 2);
}

const int N = 1e6 + 7;
vector <int> a[N];
int cnt[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            cnt[x]++;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int good = 0, all = 0;
        for (int elem : a[i]) {
            all = (all + n) % M;
            good = (good + cnt[elem]) % M;
            //cout << all << ' ' << good << endl;
        }
        int cur = (good * obr(all)) % M;
        cur = (cur * obr(n)) % M;
        res = (res + cur) % M;
    }
    cout << res << endl;
    return 0;
}