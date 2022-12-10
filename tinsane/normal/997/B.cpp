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

const int P = 49;
const int Q = P * 9 + 4 * 9;
int minc[Q];
ll n;

void solve()
{
	scanf("%lld", &n);
	ll ans = 0;
	memset(minc, -1, sizeof minc);
	for(int b = 0; b < 9; ++b)
		for (int c = 0; c < 49; ++c)
		{
			auto x = 4 * b + 9 * c;
			if (minc[x] == -1)
				minc[x] = b + c;
			else
				minc[x] = min(minc[x], b + c);
		}
	for(int i = 0; i + P < Q; ++i)
		if (minc[i] != -1)
		{
			if (minc[i + P] == -1)
				minc[i + P] = minc[i] + 1;
			else
				minc[i + P] = min(minc[i + P], minc[i] + 1);
		}
	for (int i = 0; i < Q; ++i)
		if (minc[i] != -1 && minc[i] <= n)
			++ans;
	for (int r = 0; r < P; ++r)
	{
		int cur = minc[Q - 1 - r];
		if (cur <= n)
			ans += n - cur;
	}
	printf("%lld\n", ans);
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