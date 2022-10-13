#include <bits/stdc++.h>
using namespace std;
 
int dist(pair<int, int> x) {
    return __gcd(abs(x.first), abs(x.second));
}

int dist(pair<int, int> x, pair<int, int> y) {
    return dist({x.first - y.first, x.second - y.second});
}

int dist(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
    return dist(x, y) + dist(y, z) + dist(x, z);
}

bool dist(int a, int b, int c) {
    pair<int, int> x = {a / 4, a % 4}, y = {b / 4, b % 4}, z = {c / 4, c % 4};
    return dist(x, y, z) % 4 == 0;
}

inline long long ch3(int n) { return n * 1LL * (n - 1) * 1LL * (n - 2) / 6; }
inline long long ch2(int n) { return n * 1LL * (n - 1) / 2; }
inline long long ch1(int n) { return n; }


int main() {
    int n; cin >> n;
    vector<pair<int, int>> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i].first >> in[i].second;
    }
    
    vector<int> num(16);
    vector<vector<int>> f(4, vector<int>(4));
    for (int i = 0; i < n; i++)
        ++f[in[i].first % 4][in[i].second % 4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            num[i * 4 + j] = f[i][j];
    long long ans = 0LL;
    for (int a = 0; a < 16; a++) {
        for (int b = a; b < 16; b++) {
            for (int c = b; c < 16; c++) {
                if (dist(a, b, c)) {
                    if (a == b && b == c) ans += ch3(num[a]);
                    else if (a == b || b == c || a == c) {
                        if (a == b) ans += ch2(num[a]) * 1LL * ch1(num[c]);
                        else if(b == c) ans += ch2(num[b]) * 1LL * ch1(num[a]);
                        else ans += ch2(num[a]) * 1LL * ch1(num[b]);
                    }
                    else {
                        ans += ch1(num[a]) * 1LL * ch1(num[b]) * 1LL * ch1(num[c]);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}