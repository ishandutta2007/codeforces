#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz


struct Tree
{
    const int n;
    vector<ll> tree;
    vector<int> swap;

    Tree(int n) : n(n)
    {
        swap.assign(n, 0);
        tree.assign(1 << (n + 1), 0);
    }

    int left(int p) { return p << 1; }
    int right(int p) { return p << 1 | 1; }

    void traverse(int x, function<void(int)> f, function<void(int)> g)
    {
        int cur = 1; f(cur);
        for (int i = n - 1; i >= 0; --i)
        {
            if (((x >> i) & 1) ^ swap[i])
            {
                if (not swap[i]) g(left(cur));
                cur = right(cur);
            }
            else
            {
                if (swap[i]) g(right(cur));
                cur = left(cur);
            }
            f(cur);
        }
        g(cur);
    }

    void replace(int x, ll k)
    {
        auto dummy = [](int p) { };

        ll sum = 0;
        auto f = [&](int q) { sum = tree[q]; };
        traverse(x, f, dummy);

        auto g = [&](int q) { tree[q] += k - sum; };
        traverse(x, g, dummy);
    }

    ll sum(int x)
    {
        ll sum = 0;

        auto dummy = [](int p) { };
        auto f = [&](int p) { sum += tree[p]; };

        traverse(x, dummy, f);

        return sum;
    }

    ll sum(int l, int r)
    {
        if (l > 0) return sum(r) - sum(l - 1);
        else return sum(r);
    }
};

int main()
{ _
    int n, q; cin >> n >> q;
    Tree tree(n);
    for (int i = 0; i < (1 << n); ++i)
    {
        ll a; cin >> a;
        tree.replace(i, a);
    }

    // for (int i = 0; i < (1 << n); ++i)
    // {
    //     ll sum = tree.sum(i);
    //     debug(sum);
    // }

    while (q--)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int x; ll k; cin >> x >> k; --x;
            tree.replace(x, k);
        }
        if (t == 2)
        {
            int k; cin >> k;
            for (int i = 0; i < k; ++i)
                tree.swap[i] ^= 1;
        }
        if (t == 3)
        {
            int k; cin >> k;
            tree.swap[k] ^= 1;
        }
        if (t == 4)
        {
            int l, r; cin >> l >> r; --l, --r;
            cout << tree.sum(l, r) << endl;
        }
    }

    exit(0);
}