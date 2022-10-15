#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Rectangle
{
public:
	int xl, xr, yd, yu;
};

template<typename T>
struct F1
{
    int L, R;
    T add;

    F1(T add) : add(add) {}

    void apply_aggregate(T& old) const
    {
        old.f = old.f + add.f;
    }
    void compose(const F1<T>& op)
    {
        add.f += op.add.f;
    }
    void operator=(const F1& op)
    {
        // this maybe slow if add is a vector
        add = op.add;
    }
};

template<typename T, typename F>
class SegmentTree
{
private:
    const int n, h;
    vector<T> st;
    vector<F> d;
    const T T_id;
    const F F_id;

    T combine(const T& resl, const T& resr)
    {
		if (resl.f < resr.f)
			return resl;
		if (resr.f < resl.f)
			return resr;
		return mp(resl.f, resl.s + resr.s);
    }

    void apply(int p)
    {
        d[p].apply_aggregate(st[p]);
        if (p < n)
        {
            d[p << 1].compose(d[p]);
            d[p << 1 | 1].compose(d[p]);
        }
        d[p] = F_id;
    }
    void build(int p)
    {
        while (p > 1)
        {
            p >>= 1;
            // apply(p);
            apply(p << 1);
            apply(p << 1 | 1);
            st[p] = combine(st[p << 1], st[p << 1 | 1]);
        }
    }
    void push(int p)
    {
        for (int s = h; s >= 0; --s)
        {
            int i = p >> s;
            apply(i);
            if (i < n)
            {
                apply(i << 1);
                apply(i << 1 | 1);
            }
        }
    }

public:
    SegmentTree(const vector<T>& a, T T_id, F F_id) :
        n(a.size()),
        h(sizeof(int) * 8 - __builtin_clz(n)),
        T_id(T_id), F_id(F_id)
    {
        st.assign(2 * n, T_id);
        d.assign(2 * n, F_id);

        for (int i = 0; i < n; ++i)
        {
            st[n + i] = a[i];
            d[n + i].L = d[n + i].R = i;
        }

        for (int i = n - 1; i > 0; --i)
        {
            st[i] = combine(st[i << 1], st[i << 1 | 1]);
            d[i].L = d[i << 1].L;
            d[i].R = d[i << 1 | 1].R;
        }
    }
    void update(int l, int r, F op)
    {
        l += n, r += n + 1; // computations are done in [l, r + 1) = [l, r]
        int l0 = l, r0 = r;


        // needs to push for non-commutative operations
        push(l0);
        push(r0 - 1);

        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                d[l].compose(op);
                apply(l++);
            }
            if (r & 1)
            {
                d[r - 1].compose(op);
                apply(--r);
            }
        }
        build(l0);
        build(r0 - 1);
    }
    T query(int l, int r)
    {
        l += n, r += n + 1; // computations are done in [l, r + 1) = [l, r]
        push(l);
        push(r - 1);

        T resl = T_id, resr = T_id;

        for(; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, st[l++]);
            if (r & 1)
                resr = combine(st[--r], resr);
        }
        return combine(resl, resr);
    }
};

int main()
{ _
    int n; cin >> n;

	vector<Rectangle> R(n);

	vii E;

	vi y;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		R[i] = { min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2) };
		E.pb(mp(R[i].xl, -(i + 1)));
		E.pb(mp(R[i].xr + 1, i));
		y.pb(y1), y.pb(y2);
		y.pb(y1 + 1), y.pb(y2 + 1);
	}
	sort(ALL(E));

	y.pb(-(int)1e9 - 1);
	y.pb((int)1e9 + 1);

	sort(ALL(y));
	y.erase(unique(ALL(y)), y.end());

	int k = SZ(y);
	vpll w(k, mp(0, 0));
	for (int i = 0; i + 1 < k; ++i)
		w[i].s = y[i + 1] - y[i];

	SegmentTree TREE(w, mp(0LL, 0LL), F1(mp(0LL, 0LL)));
	ll D = y[k - 1] - y[0];

	map<int, int> pos;
	for (int i = 0; i < k; ++i)
		pos[y[i]] = i;

	ll ans = 0;

	int lastx = E[0].f;
	bool last = false;
	for (auto [x, i] : E)
	{
		bool leave = true;
		if (i < 0)
		{
			leave = false;
			i = - i - 1;
		}

		if (x != lastx)
		{
			auto q = TREE.query(0, k - 1);
			ans += (q.f == 0 ? D - q.s : D) * (x - lastx);
		}

		auto [y1, y2] = mp(R[i].yd, R[i].yu);

		TREE.update(pos[y1], pos[y2], mp(leave ? -1LL : 1LL, 0LL));
		lastx = x;
	}

	cout << ans << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
 */