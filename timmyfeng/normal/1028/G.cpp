#include <bits/stdc++.h>
using namespace std;

const long long M = 10004205361450474LL;
const int K = 10000;
const int Q = 5;

long long gap[Q];

long long scope(long long n, int k) {
    if (n >= K) {
        return n + gap[k];
    } else if (k == 0) {
        return n;
    } else {
        long long m = scope(n, k - 1);
        for (int i = 0; i < n; ++i) {
            m = scope(m + 1, k - 1);
        }
        return m;
    }
}

void solve(long long n, int k) {
    vector<long long> query;
    long long m = scope(n, k - 1);
    for (int i = 0; i < n && i < K; ++i) {
        query.push_back(m);
        m = scope(m + 1, k - 1);
    }

    cout << query.size() << " ";
    for (auto i : query) {
        cout << i << " ";
    }
    cout << endl;

    int index;
    cin >> index;

    if (index == -1) {
        exit(0);
    } else if (index == 0) {
        solve(n, k - 1);
    } else {
        solve(query[index - 1] + 1, k - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < Q; ++i) {
        gap[i] = gap[i - 1] * (K + 1) + K;
    }

    solve(1, Q);
}