#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> &x, pair<long long, long long> &y) {
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<long long, long long>> in(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i].first >> in[i].second;
    }
    sort(in.begin(), in.end(), cmp);

    long long lo = 0LL, hi = 1e15, tot = 0LL;
    for(int i = 0; i < n; i++) {
        tot += in[i].first;
    }
    for(int j = 0; j < 60; j++) {
        long long tst = (lo + hi) / 2;
        long long soFar = tst;
        for(int i = 0; i < n; i++) {
            if(soFar >= in[i].second)
                soFar += in[i].first;
        }
        if(soFar >= tot) {
            hi = tst;
        }
        else lo = tst + 1;
    }
    cout << tot + lo << "\n";
}