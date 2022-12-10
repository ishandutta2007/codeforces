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
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    fi(n)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int minn = 1e9;
    for (auto pa : cnt)
    {
        minn = min(minn, pa.ss);
    }
    for (int s = minn + 1; s > 1; --s)
    {
        bool good = true;
        ll cur = 0;
        for (auto pa : cnt)
        {
            int a = pa.ss / s;
            int b = pa.ss % s;
            if (!(b == 0 || a + 1 >= s - b))
            {
                good = false;
                break;
            } else {
                if (b == 0)
                    cur += a;
                else
                    cur += a + 1;
            }
        }
        //cout << s << ' ' << good << '\n';
        if (good)
        {
            cout << cur;
            return;
        }
    }
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
    solve_multiple();
    return 0;
}
/*

*/