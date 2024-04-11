#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll lo = 0, hi = 1e12;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        int ok = 0;
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            if(abs(a[i] - b[cur]) > mid) continue;
            int lo2 = cur, hi2 = m - 1;
            while(lo2 < hi2) {
                ll m2 = (lo2 + hi2 + 1) / 2;
                ll p1 = b[cur], p2 = b[m2];
                assert(p1 <= p2);
                ll dis = 0;
                if(p2 <= a[i]) dis = a[i] - p1;
                else if(p1 >= a[i]) dis = p2 - a[i];
                else dis = min(abs(a[i] - p2), abs(a[i] - p1)) + abs(p1 - p2);
                if(dis <= mid) lo2 = m2;
                else hi2 = m2 - 1;
            }
            cur = lo2 + 1;
            if(cur >= m) break;
        }
        if(cur == m) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}