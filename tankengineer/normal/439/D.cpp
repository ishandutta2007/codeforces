#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
vector<int> a, b;

long long cal(int u) {
    long long ret = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] < u) {
            ret += u - a[i];
        }
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        if (b[i] > u) {
            ret += b[i] - u;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        b.push_back(t);
    }
    int l = 0, r = 1000000002;
    while (l < r) {
        int m1 = ((long long)l + l + r) / 3,
            m2 = ((long long)l + r + r) / 3;
        if (cal(m1) > cal(m2)) {
            l = m1 + (l == m1);
        } else {
            r = m2 - (r == m2);
        }
    }
    cout << cal(l) << endl;
    return 0;
}