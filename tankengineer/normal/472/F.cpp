#include <cassert>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int N = 10005;

int getBit(int x) {
    int ret = 0;    
    while (x) {
        x >>= 1;
        ++ret;
    }
    return ret - 1;
}

vector<int> clear(vector<int> &x, vector<pair<int, int> > &ans) {
    int base = 0;
    vector<int> bit;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < base; ++j) {
            if (x[i] >> bit[j] & 1) {
                x[i] ^= x[j];
                ans.push_back(make_pair(i, j));
            }
        }
        if (x[i]) {
            if (i != base) {
                ans.push_back(make_pair(base, i));
                ans.push_back(make_pair(i, base));
                ans.push_back(make_pair(base, i));
                swap(x[i], x[base]);
            }
            bit.push_back(getBit(x[base]));
            ++base;
            for (int j = 0; j < base; ++j) {
                for (int k = j + 1; k < base; ++k) {
                    if (bit[k] > bit[j]) {
                        ans.push_back(make_pair(j, k));
                        ans.push_back(make_pair(k, j));
                        ans.push_back(make_pair(j, k));
                        swap(x[j], x[k]);
                        swap(bit[j], bit[k]);
                    }
                }
            }
            for (int j = 0; j < base; ++j) {
                for (int k = j + 1; k < base; ++k) {
                    if (x[j] >> bit[k] & 1) {
                        ans.push_back(make_pair(j, k));
                        x[j] ^= x[k];
                    }
                }
            }
        }
    }
    return bit;
}

vector<int> x, y;

bool trans(vector<int> &bitx, vector<int> &bity, vector<pair<int, int> > &mid) {
    int n = bitx.size(), m = bity.size();
    if (n < m) {
        return false;
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j == m) {
            mid.push_back(make_pair(i, i));
            x[i] = 0;
            continue;
        }
        if (bitx[i] > bity[j]) {
            mid.push_back(make_pair(i, i));
            x[i] = 0;
            continue;
        }
        if (bitx[i] < bity[j]) {
            return false;
        }
        int delta = x[i] ^ y[j];
        for (int k = i + 1; k < n; ++k) {
            if (delta >> bitx[k] & 1) {
                delta ^= x[k];
                mid.push_back(make_pair(i, k));
                x[i] ^= x[k];
            }
        }
        if (delta) {
            return false;
        }
        ++j;
    }
    if (j != m) {
        return false;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (x[i] == 0) {
            for (int j = i; j + 1 < n; ++j) {
                x[j] = x[j + 1];
                mid.push_back(make_pair(j, j + 1));
                mid.push_back(make_pair(j + 1, j + 1));
            }
            x[n - 1] = 0;
            --n;
        }
    }
    /*
for (int i = 0; i < ::n; ++i) {
    cout << x[i] << ' ';
}
cout << endl;
for (int i = 0; i < ::n; ++i) {
    cout << y[i] << ' ';
}
cout << endl;
    */
    return true;
}

bool check(vector<int> x, vector<int> y, vector<pair<int, int> > ans) {
    for (int i = 0; i < (int)ans.size(); ++i) {
        int u = ans[i].first, v = ans[i].second;
        x[u] ^= x[v];
    }
    return x == y;
}

int main() {
    scanf("%d", &n);
    x.resize(n), y.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y[i]);
    }
    vector<int> cx = x, cy = y;
    vector<pair<int, int> > ans1, ans2, mid;
    vector<int> bitx, bity;
    bitx = clear(x, ans1);
    bity = clear(y, ans2);
    if (trans(bitx, bity, mid)) {
        assert(x == y);
        vector<pair<int, int> > full = ans1;
        full.insert(full.end(), mid.begin(), mid.end());
        reverse(ans2.begin(), ans2.end());
        full.insert(full.end(), ans2.begin(), ans2.end());
        printf("%d\n", (int)full.size());
        for (int i = 0; i < (int)full.size(); ++i) {
            printf("%d %d\n", full[i].first + 1, full[i].second + 1);
        }
        assert(check(cx, cy, full));
    } else {
        printf("-1\n");
    }
    return 0;
}