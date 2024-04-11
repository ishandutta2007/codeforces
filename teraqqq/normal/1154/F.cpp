#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pii = pair<int, int>;

const int N = 2e5+7;
const int M = 2e5+7;
const int INF = 1e9;

int n, m, k, a[N], dp[N], p[N];

struct Offer {
    int ctotal, cfree;
} offers[M];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> a[i]; sort(a, a+n);
    for(int i = 0; i < k; ++i) p[i+1] = a[i] + p[i];
    for(int i = 0; i < m; ++i) cin >> offers[i].ctotal >> offers[i].cfree;
    offers[m++] = { 1, 0 };
    sort(offers, offers+m, [](const Offer& l, const Offer& r) {
        if(l.ctotal != r.ctotal) return l.ctotal < r.ctotal;
        return l.ctotal - l.cfree < r.ctotal - r.cfree;
    });
    m = unique(offers, offers+m, [](const Offer& l, const Offer& r) {
        return l.ctotal == r.ctotal;
    }) - offers;
    
    for(int i = 0; i <= k; ++i) dp[i] = p[i];
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < m && offers[j].ctotal <= k-i; ++j)
            dp[i+offers[j].ctotal] = min(
                dp[i+offers[j].ctotal],
                dp[i] + p[i+offers[j].ctotal] - p[i+offers[j].cfree]);
    }
    cout << dp[k];
}