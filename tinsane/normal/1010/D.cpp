#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#ifndef LOCAL
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

const int N = 1e6 + 10;
int n;
char tmp[100];
int type[N];
int chs[N][2];
int dp[N][2];
int cur[N];
vector<function<int(int, int)>> funcs;

string readt()
{
    scanf("%s", tmp);
    return tmp;
}

void read2(int i)
{
    scanf("%d%d", &chs[i][0], &chs[i][1]);
    --chs[i][0], --chs[i][1];
}

void calc(int v)
{
    if (type[v] == 0)
        return;
    if (type[v] == 4)
    {
        calc(chs[v][0]);
        dbg(v, cur[chs[v][0]], cur[chs[v][1]]);
        cur[v] = !cur[chs[v][0]];
        return;
    }
    calc(chs[v][0]);
    calc(chs[v][1]);
    dbg(v, cur[chs[v][0]], cur[chs[v][1]]);
    cur[v] = funcs[type[v]](cur[chs[v][0]], cur[chs[v][1]]);
}

void dfs(int v, int p, int id = -1)
{
    if (p == -1)
    {
        dp[v][0] = funcs[type[v]](1 - cur[chs[v][0]], cur[chs[v][1]]);
        dp[v][1] = funcs[type[v]](cur[chs[v][0]], 1 - cur[chs[v][1]]);
    }
    else if (type[v] == 0)
    {
        dp[v][0] = dp[p][id];
        return;
    }
    else
    {
        int can0 = funcs[type[v]](1 - cur[chs[v][0]], cur[chs[v][1]]);
        int can1 = funcs[type[v]](cur[chs[v][0]], 1 - cur[chs[v][1]]);

        if (can0 == cur[v])
            dp[v][0] = cur[0];
        else
            dp[v][0] = dp[p][id];

        if (can1 == cur[v])
            dp[v][1] = cur[0];
        else
            dp[v][1] = dp[p][id];
    }
    dfs(chs[v][0], v, 0);
    if (type[v] != 4)
        dfs(chs[v][1], v, 1);
}

void solve()
{
    scanf("%d", &n);
    funcs.push_back([](int a, int b) { return -1; });
    funcs.push_back([](int a, int b) {return a & b;});
    funcs.push_back([](int a, int b) {return a | b;});
    funcs.push_back([](int a, int b) {return a ^ b;});
    funcs.push_back([](int a, int b) {return !a;});
    for(int i = 0; i < n; ++i)
    {
        auto s = readt();
        dbg(s);
        if (s == "IN")
        {
            type[i] = 0;
            scanf("%d", &cur[i]);
        }
        else if(s == "AND")
        {
            type[i] = 1;
            read2(i);
        }
        else if(s == "OR")
        {
            type[i] = 2;
            read2(i);
        }
        else if(s == "XOR")
        {
            type[i] = 3;
            read2(i);
        }
        else if(s == "NOT")
        {
            type[i] = 4;
            scanf("%d", &chs[i][0]);
            --chs[i][0];
        }
    }
    calc(0);
    dbg(ARR(type, n), ARR(cur, n));
    dfs(0, -1);
    dbg(n);
    for(int i = 0; i < n; ++i)
        if (type[i] == 0)
            printf("%d", dp[i][0]);
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