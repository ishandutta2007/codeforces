#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n, a[MAXN];
ll f[MAXN], g[MAXN];

struct Line {
    ll a, b;
    ll get(ll x) {return a*x + b;}
};

double intersect(Line l1, Line l2) {
    return 1.0 * (l2.b - l1.b) / (l1.a - l2.a);
}

bool conflict(Line l1, Line l2, Line l3) {
    return intersect(l2, l3) >= intersect(l1, l3);
}

struct ConvexHull {
    vector<Line> h;

    void addLine(Line l) {
        int k;
        while ((k = h.size()) >= 2 && conflict(h[k-2], h[k-1], l))
            h.pop_back();
        h.push_back(l);
    }

    long long query(long long x) {
        int lo = 0, hi = (int)h.size() - 2, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (h[mid].get(x) < h[mid+1].get(x)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return h[res+1].get(x);
    }
};


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    reverse(a+1, a+n+1);

    for(int i = 1; i <= n; ++i) {
        f[i] = f[i-1] + a[i];
        g[i] = g[i-1] + f[i];
    }

    ConvexHull h;
    long long ans = 0;
    for(int i = n; i >= 0; --i) {
        if (i < n) {
            long long sum = -g[i] + f[i]*i + h.query(-f[i]);
            ans = max(ans, sum);
        }
        h.addLine({i, g[i]});
    }

    cout << ans << endl;

    return 0;
}