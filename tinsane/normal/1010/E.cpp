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

const int N = 3e5 + 10;
int X, Y, Z;
int n, m;
int x[N], y[N], z[N];
int ans[N];
int state;

struct comp
{
    bool operator() (int a, int b)
    {
        if (state == 0)
            return y[a] < y[b];
        else
            return z[a] > z[b];
    }
};

void solve(vector<int> pts, int xmi, int ymi, int zmi)
{
    set<int, comp> s;
    for(int id : pts)
    {
        if (!(xmi <= x[id] && ymi <= y[id] && zmi <= z[id]))
            continue;
        if (id < n + m) // add
        {
            auto it = s.upper_bound(id);
            if (it != s.begin())
            {
                auto p = prev(it);
                if (z[id] >= z[*p])
                    continue;
                if (y[*p] == y[id])
                    it = p;
            }
            while(it != s.end())
            {
                if (z[*it] < z[id])
                    break;
                auto nit = next(it);
                s.erase(it);
                it = nit;
            }
            s.insert(id);
        }
        else if(ans[id] == 0) // check
        {
            if (s.empty())
                continue;
            auto it = s.upper_bound(id);
            if (it != s.begin())
            {
                auto p = prev(it);
                if (z[id] >= z[*p])
                    ans[id] = 1;
            }
        }
    }
}

void solve()
{
    scanf("%d%d%d", &X, &Y, &Z);
    int k;
    scanf("%d%d%d", &n, &m, &k);
    int xmi, xma;
    int ymi, yma;
    int zmi, zma;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        if (i == 0)
        {
            xmi = xma = x[i];
            ymi = yma = y[i];
            zmi = zma = z[i];
        }
        else
        {
            xmi = min(xmi, x[i]);
            xma = max(xma, x[i]);
            ymi = min(ymi, y[i]);
            yma = max(yma, y[i]);
            zmi = min(zmi, z[i]);
            zma = max(zma, z[i]);
        }
    }
    vector<int> inter;
    for(int i = n; i < n + m; ++i)
    {
        inter.push_back(i);
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        if (xmi <= x[i] && x[i] <= xma &&
                ymi <= y[i] && y[i] <= yma &&
                zmi <= z[i] && z[i] <= zma)
        {
            puts("INCORRECT");
            return;
        }
    }
    puts("CORRECT");
    for(int i = n + m; i < n + m + k; ++i)
    {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        if (xmi <= x[i] && x[i] <= xma &&
                ymi <= y[i] && y[i] <= yma &&
                zmi <= z[i] && z[i] <= zma)
            ans[i] = 2;
        else
            inter.push_back(i);
    }
    for(int it1 : {0, 1})
    {
        sort(inter.begin(), inter.end(), [](int a, int b) {
            if (x[a] != x[b])
                return x[a] < x[b];
            return a < b;
        });
        for(int it2 : {0, 1})
        {
            for(int it3 : {0, 1})
            {
                solve(inter, xmi, ymi, zmi);
                for(int i = 0; i < n + m + k; ++i)
                    z[i] = -z[i];
                swap(zmi, zma);
                zmi = -zmi;
                zma = -zma;
            }
            swap(ymi, yma);
            ymi = -ymi;
            yma = -yma;
            for(int i = 0; i < n + m + k; ++i)
                y[i] = -y[i];
        }
        swap(xmi, xma);
        xmi = -xmi;
        xma = -xma;
        for(int i = 0; i < n + m + k; ++i)
            x[i] = -x[i];
    }
    string arr[] = {"UNKNOWN", "CLOSED", "OPEN"};
    for(int i = n + m; i < n + m + k; ++i)
        puts(arr[ans[i]].c_str());
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