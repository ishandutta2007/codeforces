#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <complex>
#include <regex>
#include <numeric>
#include <typeinfo>
#include <type_traits>
#include <fstream>
#pragma comment(linker, "/STACK:167772160")

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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int INF = (int)1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
#pragma endregion

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
	return ll(a) * b % P;
}
int bpow(int x, int p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}
int inv(int x)
{
	return bpow(x, P - 2);
}

const int T = 5010;
int n, k;
int dp[T][T];

void solve()
{
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			// (1+x)^(n-j)*x^j
			dp[i + 1][j + 1] = sum(dp[i + 1][j + 1], mul(dp[i][j], n - j));
			dp[i + 1][j] = sum(dp[i + 1][j], mul(dp[i][j], j));
		}
	}
	int res = 0;
	int t = bpow(2, n);
	int r2 = inv(2);
	for (int i = 0; i <= k; ++i)
	{
		res = sum(res, mul(dp[k][i], t));
		t = mul(t, r2);
	}
	cout << res << endl;
}

/*
1 1 1 1 1 1 1 1 1
4 6 10 18 34 66 130 258 514
12 24 54 132 342 924 2574 7332 21222
32 80 224 680 2192 7400 25904 93320 343952
80 240 800 2880 11000 44040 183200 786480 3465800
192 672 2592 10752 47232 217392 1040112 5141472 26129952
448 1792 7840 36736 181888 942592 5076400 28254016 161787808
1024 4608 22528 117504 646144 3714048 22171648 136761984 868063744
2304 11520 62208 357120 2156544 13593600 88915968 600698880 4175432064
*/

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