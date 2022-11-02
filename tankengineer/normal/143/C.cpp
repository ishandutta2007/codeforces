#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define div DIV

vector<pair<int, int> > div;

long long mins, maxs;

void go(int i, long long a, long long b, long long c) {
//cout << i << ' ' << a << ' ' << b << ' ' << c << endl;
    if (i == div.size()) {
        mins = min(mins, (a + 1) * (b + 2) * (c + 2));
        maxs = max(maxs, (a + 1) * (b + 2) * (c + 2));
        return;
    }
    long long nb = b, nc = c;
    for (int j = 0; j < (int)div[i].second; ++j) {
        nc *= div[i].first;
    }
    for (int j = 0; j <= (int)div[i].second; ++j) {
        b = nb, c = nc;
        for (int k = 0; k + j <= (int)div[i].second; ++k) {
            go(i + 1, a, b, c);
            c /= div[i].first;
            b *= div[i].first;
        }
        a *= div[i].first;
        nc /= div[i].first;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int on = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            div.push_back(make_pair(i, cnt));
        }
    }
    if (n != 1) {
        div.push_back(make_pair(n, 1));
        n = 1;
    }
    mins = 1ll << 60, maxs = 0;
    go(0, 1, 1, 1);
    cout << mins - on << ' ' << maxs - on << endl;
    return 0;
}