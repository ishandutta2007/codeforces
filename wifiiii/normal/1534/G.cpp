#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int x, y;
    bool operator < (const node & n) const {
        return x < n.x;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<node> a(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i].x = x + y;
        a[i].y = x - y;
    }
    a.push_back({0, 0});
    n += 1;
    sort(a.begin(), a.end());
    priority_queue<ll> ql;
    priority_queue<ll, vector<ll>, greater<ll>> qr;
    ql.push(a[0].y);
    qr.push(a[0].y);
    ll shift = 0, ans = 0;
    for(int i = 1; i < n; ++i) {
        shift += a[i].x - a[i-1].x;
        // ql : x -> x - shift
        // qr : x -> x + shift
        ll lborder = ql.top() - shift, rborder = qr.top() + shift;
        if(a[i].y < lborder) {
            ql.push(a[i].y + shift);
            ql.push(a[i].y + shift);
            ql.pop();
            qr.push(lborder - shift);
            ans += lborder - a[i].y;
        } else if(a[i].y > rborder) {
            qr.push(a[i].y - shift);
            qr.push(a[i].y - shift);
            qr.pop();
            ql.push(rborder + shift);
            ans += a[i].y - rborder;
        } else {
            ql.push(a[i].y + shift);
            qr.push(a[i].y - shift);
        }
    }
    cout << ans / 2 << '\n';
}