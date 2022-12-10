#pragma region template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

//const double eps = 1e-8;
//const double pi = 3.141592653589793238462643383279502884;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fi(n) for (int i = 0; i < (int)(n); ++i)
#define fir(l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fj(n) for (int j = 0; j < (int)(n); ++j)
#define fjr(l, r) for (int j = (int)(l); j < (int)(r); ++j)

#pragma endregion

//template <typename T>
//struct SegmentTree
//{
//	vector<T> a;
//	function<T(T, T)> f;
//	T def;
//	int MAX_SEG;
//	SegmentTree(int size, function<T(T, T)> func, T default_value)
//	{
//		f = func;
//		def = default_value;
//		for (int i = 0; i <= 20; ++i)
//			if ((1 << i) >= size)
//			{
//				MAX_SEG = 1 << i;
//				break;
//			}
//		a.resize(MAX_SEG * 2, default_value);
//	}
//
//	void upd(int v)
//	{
//		a[v] = f(a[v * 2], a[v * 2 + 1]);
//	}
//
//	void set(int pos, int val)
//	{
//		pos += MAX_SEG;
//		a[pos] = val;
//		while (pos != 1)
//		{
//			pos /= 2;
//			upd(pos);
//		}
//	}
//
//	T calc(int l, int r)
//	{
//		return calc(1, l + 1, r + 1, 1, MAX_SEG);
//	}
//
//	T calc(int v, int l, int r, int L, int R)
//	{
//		if ((r < L) || (l > R))
//			return def;
//		if ((l <= L) && (R <= r))
//			return a[v];
//		return f(calc(v * 2, l, r, L, (L + R) / 2), calc(v * 2 + 1, l, r, (L + R) / 2 + 1, R));
//	}
//};

vvll calc_c(int n)
{
    vvll c(n, vll(n));
    c[0][0] = 1;
    fi (n)
    {
        c[i][0] = c[i][i] = 1;
    }
    fir(1, n)
    {
        fjr(1, i)
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c;
}

vvll pascal;

ll calc(const vector<pll> &nums, int total)
{
    ll max_num = total + 1;
    ll ans = 1;
    int used = 0;
    for (int i = 0; i < (int)nums.size() - 1; ++i) {
        ll cur = max_num - nums[i].ff - used;
//        cout << max_num << ' ' << nums[i].ff <<  ' ' << used << '\n';
//        cout << "c[" << cur << "][" << nums[i].ss << "]\n";
        ans *= pascal[cur][nums[i].ss];
        used += nums[i].ss;
    }
    cout << endl;
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vll nums;
    ll i = 2;
    while (n != 0)
    {
        nums.pb(n % i);
        n /= i;
        i++;
    }
    sort(all(nums));
    reverse(all(nums));
    vector<pll> np;
    for (ll x : nums)
        if (np.size() == 0 || np.back().ff != x)
            np.pb(pll(x, 1));
        else
            np.back().ss++;
//    cout << "np:\n";
//    for (auto x : np)
//        cout << x.ff << ' ' << x.ss << '\n';
//    cout <<'\n';
    ll solved = calc(np, nums.size());
    if (np.back().ff == 0)
        np.back().ss--, solved -= calc(np, nums.size() - 1);
    cout << solved - 1;
}

void solve_multiple()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
        cout << endl;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout.precision(20);
    pascal = calc_c(100);
//    fi(5) {
//        fj(5)
//                cout << pascal[i][j] << ' ';
//        cout << '\n';
//    }
    solve_multiple();
    return 0;
}
/*

*/