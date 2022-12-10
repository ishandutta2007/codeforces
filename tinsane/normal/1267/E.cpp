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

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi a(m, vi(n + 1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j], a[i][n] = i;
    vector<int> best_ans(m + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        //cout << 'i' << i << '\n';
        sort(all(a), [&](const vi& a, const vi& b) {
            return a[i] - a[n - 1] > b[i] - b[n - 1];
        });
        int sum_i = 0;
        int sum_n = 0;
//        for (int i = 0; i < m; ++i, cout << '\n')
//            for (int j = 0; j < n; ++j)
//                cout << a[i][j] << ' ';
        for (int j = 0; j < m; ++j)
        {
            sum_i += a[j][i], sum_n += a[j][n - 1];
            //cout << sum_i << ' ' << sum_n << '\n';
            if (sum_i < sum_n) {
                //cout << 'j' << j << '\n';
                vector<int> cur_ans;
                for (int k = j; k < m; ++k)
                    cur_ans.pb(a[k][n]);
                if (cur_ans.size() < best_ans.size())
                    best_ans = cur_ans;
                break;
            }
        }
        if (sum_i >= sum_n) // geq
            best_ans = {};
    }
    cout << best_ans.size() << '\n';
    for (int x : best_ans)
        cout << x + 1 << ' ';
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
    solve();
    return 0;
}
/*

*/