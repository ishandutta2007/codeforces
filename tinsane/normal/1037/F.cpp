#define _CRT_SECURE_NO_WARNINGS
#ifdef LOCAL
#include <bits/stdc++.h>
#else
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cmath>
#pragma comment(linker, "/STACK:167772160")
#endif

using namespace std;

#ifdef LOCAL

template <typename T, typename Q>
ostream& operator<<(ostream& os, pair<T, Q> p)
{
	return (os << '(' << p.first << ", " << p.second << ')');
}

int _iterable_indent = 0;
template<class T>
std::ostream& print_iterable(std::ostream& os, T beg, T end)
{
	if (_iterable_indent > 0)
		os << "\n";
	for (int i = 0; i < _iterable_indent; ++i)
		os << "\t";
	os << "[";
	for (auto it = beg; it != end; ++it)
	{
		if (it != beg)
			os << ", ";
		++_iterable_indent;
		os << *it;
		--_iterable_indent;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	return print_iterable(os, v.begin(), v.end());
}
template <class T >
std::ostream& operator << (std::ostream& os, const std::set<T>& v)
{
	return print_iterable(os, v.begin(), v.end());
}
template <class T >
std::ostream& operator << (std::ostream& os, const std::multiset<T>& v)
{
	return print_iterable(os, v.begin(), v.end());
}
template <class T >
std::ostream& operator << (std::ostream& os, const std::unordered_set<T>& v)
{
	return print_iterable(os, v.begin(), v.end());
}
template <class T, class Q>
std::ostream& operator << (std::ostream& os, const std::map<T, Q>& v)
{
	return print_iterable(os, v.begin(), v.end());
}
template <class T, class Q>
std::ostream& operator << (std::ostream& os, const std::unordered_map<T, Q>& v)
{
	return print_iterable(os, v.begin(), v.end());
}

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	auto arr_skip = false;
	while (getline(ss, x, c))
	{
		while (x[0] == ' ')
			x = x.substr(1);
		if (arr_skip)
		{
			for (auto h : x)
				if (h == ')')
					arr_skip = false;
			continue;
		}
		if (x.size() >= 3 && x.substr(0, 3) == "ARR")
		{
			arr_skip = true;
			v.emplace_back(x.substr(4));
		}
		else
			v.emplace_back(x);
	}
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
	string name = it->substr((*it)[0] == ' ', it->length());
	if (isalpha(name[0]))
		cerr << name << " = " << a << endl;
	else
		cerr << name << endl;
	_print(++it, args...);
}

template<class T>
auto _kekeke(T x)
{
	return x;
}

template<class T>
auto make_vector(T arr)
{
	return arr;
}

template<class T, class... Args>
auto make_vector(T arr, int len, Args... args)
{
	auto inside = make_vector(arr[0], args...);
	vector<decltype(_kekeke(inside))> v;
	for (int i = 0; i < len; ++i)
		v.push_back(make_vector(arr[i], args...));
	return v;
}

#define dbg(...) { _print(_split(#__VA_ARGS__, ',').begin(), __VA_ARGS__); }
#define ARR(arr, ...) make_vector(arr, __VA_ARGS__)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif
#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using dbl = double;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;

const int P = 1e9 + 7;
int sum(int a, int b)
{
    a += b;
    return a >= P ? a - P : a;
}
int sub(int a, int b)
{
    return sum(a, P - b);
}
int mul(int a, int b)
{
    return (ll) a * b % P;
}

const int N = 1e6 + 10;
const int H = (P + 1) / 2;
int a[N], n, k;

int get(int x, int y)
{
    if (min(x, y) == -1)
        return max(x, y);
    if (a[x] < a[y])
        return y;
    return x;
}

struct Segt
{
    int arr[4 * N];
    void build(int ind, int l, int r)
    {
        if (l == r)
        {
            arr[ind] = l;
            return;
        }
        int m = (l + r) / 2;
        build(ind * 2, l, m);
        build(ind * 2 + 1, m + 1, r);
        arr[ind] = ::get(arr[ind * 2], arr[ind * 2 + 1]);
    }
    int get(int ind, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return arr[ind];
        if (r < L || R < l)
            return -1;
        int m = (l + r) / 2;
        return ::get(get(ind * 2, l, m, L, R), get(ind * 2 + 1, m + 1, r, L, R));
    }
    int get(int l, int r)
    {
        return get(1, 0, n - 1, l, r);
    }
} segt;

int prog(int len)
{
    --len;
    dbg(k);
    int rem = len % (k - 1);
    len /= (k - 1);
    return sum(mul(k - 1, mul(len, mul(len + 1, H))), mul(rem, len + 1));
}

int cnt(int pos, int len)
{
    auto p = prog(pos + 1);
    int q = sub(prog(len + 1), prog(len - pos));
    return sub(sub(q, p), 1);
}

int solve(int l, int r)
{
    if (l > r)
        return 0;
    int id = segt.get(l, r);
    int ans = sum(solve(id + 1, r), solve(l, id - 1));
    int add = mul(a[id], cnt(id - l, r - l + 1));
    return sum(ans, add);
}

void solve()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    segt.build(1, 0, n - 1);
    printf("%d\n", solve(0, n - 1));
}

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		ios_base::sync_with_stdio(false);
		while (true)
			solve();
#endif

#ifdef CASES
#define MULTITEST
#endif

#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
	dbg_time();
}