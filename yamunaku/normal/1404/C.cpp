//
// Created by yamunaku on 2020/08/27.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

struct SegmentTree {
private:
    int n;
    vector<int> node;
public:
    SegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
    }

    int get(int k) {
        k += (n - 1);
        int ans = node[k];

        while (k > 0) {
            k = (k - 1) / 2;
            ans += node[k];
        }
        return ans;
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            node[k] += x;
            return;
        }

        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
};

int main() {
    CFS;
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    SegmentTree seg(n);
    vector<vector<pair<int, int>>> que(n);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        que[n - 1 - y].emplace_back(x, i);
    }
    vector<int> ans(q);
    rep(i, n) {
        if(a[i] <= i+1){
            int l = -1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (seg.get(mid) < (i + 1) - a[i]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            seg.add(0, min(i + 1, r), 1);
        }
        for (auto &p:que[i]) {
            ans[p.second] = seg.get(p.first);
        }
    }
    for (auto &x : ans) {
        cout << x << "\n";
    }
    cout << flush;
    return 0;
}