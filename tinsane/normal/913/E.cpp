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

#ifdef LOCAL
#define ERR_CATCH
#define NOERR
#endif

const int ST = 256;
string dp[ST], dp1[ST];

bool ls(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

string and_brace(string s)
{
	int bal = 0;
	bool ok = true;
	for (auto c : s)
	{
		if (c == '(')
			++bal;
		else if (c == ')')
			--bal;
		if (bal == 0 && c == '|')
			ok = false;
	}
	return ok ? s : ("(" + s + ")");
}

void solve()
{
	dp[0] = "!x&x";
	dp[1] = "!(x|y|z)";
	dp[2] = "!x&!y&z";
	dp[3] = "!x&!y";
	dp[4] = "!x&!z&y";
	dp[5] = "!x&!z";
	dp[6] = "!(!y&!z|x|y&z)";
	dp[7] = "!(x|y&z)";
	dp[8] = "!x&y&z";
	dp[9] = "!(!y&z|!z&y|x)";
	dp[10] = "!x&z";
	dp[11] = "!(!z&y|x)";
	dp[12] = "!x&y";
	dp[13] = "!(!y&z|x)";
	dp[14] = "!x&(y|z)";
	dp[15] = "!x";
	dp[16] = "!y&!z&x";
	dp[17] = "!y&!z";
	dp[18] = "!(!x&!z|x&z|y)";
	dp[19] = "!(x&z|y)";
	dp[20] = "!(!x&!y|x&y|z)";
	dp[21] = "!(x&y|z)";
	dp[22] = "!(!x&!y|x&y|z)|!x&!y&z";
	dp[23] = "!((x|y)&z|x&y)";
	dp[24] = "!x&y&z|!y&!z&x";
	dp[25] = "!x&y&z|!y&!z";
	dp[26] = "!x&z|!y&!z&x";
	dp[27] = "!x&z|!y&!z";
	dp[28] = "!x&y|!y&!z&x";
	dp[29] = "!x&y|!y&!z";
	dp[30] = "!x&(y|z)|!y&!z&x";
	dp[31] = "!x|!y&!z";
	dp[32] = "!y&x&z";
	dp[33] = "!(!x&z|!z&x|y)";
	dp[34] = "!y&z";
	dp[35] = "!(!z&x|y)";
	dp[36] = "!x&!z&y|!y&x&z";
	dp[37] = "!x&!z|!y&x&z";
	dp[38] = "!x&!z&y|!y&z";
	dp[39] = "!x&!z|!y&z";
	dp[40] = "!x&y&z|!y&x&z";
	dp[41] = "!(!x&z|!z&x|y)|!x&y&z";
	dp[42] = "!(x&y)&z";
	dp[43] = "!(!z&x|y)|!x&z";
	dp[44] = "!x&y|!y&x&z";
	dp[45] = "!(!y&z|x)|!y&x&z";
	dp[46] = "!x&y|!y&z";
	dp[47] = "!x|!y&z";
	dp[48] = "!y&x";
	dp[49] = "!(!x&z|y)";
	dp[50] = "!y&(x|z)";
	dp[51] = "!y";
	dp[52] = "!x&!z&y|!y&x";
	dp[53] = "!x&!z|!y&x";
	dp[54] = "!x&!z&y|!y&(x|z)";
	dp[55] = "!x&!z|!y";
	dp[56] = "!x&y&z|!y&x";
	dp[57] = "!(!x&z|y)|!x&y&z";
	dp[58] = "!x&z|!y&x";
	dp[59] = "!x&z|!y";
	dp[60] = "!x&y|!y&x";
	dp[61] = "!(!x&!y&z|x&y)";
	dp[62] = "!x&(y|z)|!y&x";
	dp[63] = "!x|!y";
	dp[64] = "!z&x&y";
	dp[65] = "!(!x&y|!y&x|z)";
	dp[66] = "!x&!y&z|!z&x&y";
	dp[67] = "!x&!y|!z&x&y";
	dp[68] = "!z&y";
	dp[69] = "!(!y&x|z)";
	dp[70] = "!x&!y&z|!z&y";
	dp[71] = "!x&!y|!z&y";
	dp[72] = "!x&y&z|!z&x&y";
	dp[73] = "!(!x&y|!y&x|z)|!x&y&z";
	dp[74] = "!x&z|!z&x&y";
	dp[75] = "!(!z&y|x)|!z&x&y";
	dp[76] = "!(x&z)&y";
	dp[77] = "!(!y&x|z)|!x&y";
	dp[78] = "!x&z|!z&y";
	dp[79] = "!x|!z&y";
	dp[80] = "!z&x";
	dp[81] = "!(!x&y|z)";
	dp[82] = "!x&!y&z|!z&x";
	dp[83] = "!x&!y|!z&x";
	dp[84] = "!z&(x|y)";
	dp[85] = "!z";
	dp[86] = "!x&!y&z|!z&(x|y)";
	dp[87] = "!x&!y|!z";
	dp[88] = "!x&y&z|!z&x";
	dp[89] = "!(!x&y|z)|!x&y&z";
	dp[90] = "!x&z|!z&x";
	dp[91] = "!(!x&!z&y|x&z)";
	dp[92] = "!x&y|!z&x";
	dp[93] = "!x&y|!z";
	dp[94] = "!x&(y|z)|!z&x";
	dp[95] = "!x|!z";
	dp[96] = "!y&x&z|!z&x&y";
	dp[97] = "!(!x&y|!y&x|z)|!y&x&z";
	dp[98] = "!y&z|!z&x&y";
	dp[99] = "!(!z&x|y)|!z&x&y";
	dp[100] = "!y&x&z|!z&y";
	dp[101] = "!(!y&x|z)|!y&x&z";
	dp[102] = "!y&z|!z&y";
	dp[103] = "!(!y&!z&x|y&z)";
	dp[104] = "!x&y&z|!y&x&z|!z&x&y";
	dp[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	dp[106] = "!(x&y)&z|!z&x&y";
	dp[107] = "!(!z&x|y)|!x&z|!z&x&y";
	dp[108] = "!(x&z)&y|!y&x&z";
	dp[109] = "!(!y&x|z)|!x&y|!y&x&z";
	dp[110] = "!(x&y)&z|!z&y";
	dp[111] = "!x|!y&z|!z&y";
	dp[112] = "!(y&z)&x";
	dp[113] = "!(!x&y|z)|!y&x";
	dp[114] = "!y&z|!z&x";
	dp[115] = "!y|!z&x";
	dp[116] = "!y&x|!z&y";
	dp[117] = "!y&x|!z";
	dp[118] = "!y&(x|z)|!z&y";
	dp[119] = "!y|!z";
	dp[120] = "!(y&z)&x|!x&y&z";
	dp[121] = "!(!x&y|z)|!x&y&z|!y&x";
	dp[122] = "!(x&y)&z|!z&x";
	dp[123] = "!x&z|!y|!z&x";
	dp[124] = "!(x&z)&y|!y&x";
	dp[125] = "!x&y|!y&x|!z";
	dp[126] = "!x&y|!y&z|!z&x";
	dp[127] = "!(x&y&z)";
	dp[128] = "x&y&z";
	dp[129] = "!(x|y|z)|x&y&z";
	dp[130] = "!x&!y&z|x&y&z";
	dp[131] = "!x&!y|x&y&z";
	dp[132] = "!x&!z&y|x&y&z";
	dp[133] = "!x&!z|x&y&z";
	dp[134] = "!(!y&!z|x|y&z)|x&y&z";
	dp[135] = "!(x|y&z)|x&y&z";
	dp[136] = "y&z";
	dp[137] = "!(x|y|z)|y&z";
	dp[138] = "!x&z|y&z";
	dp[139] = "!x&!y|y&z";
	dp[140] = "!x&y|y&z";
	dp[141] = "!x&!z|y&z";
	dp[142] = "!x&(y|z)|y&z";
	dp[143] = "!x|y&z";
	dp[144] = "!y&!z&x|x&y&z";
	dp[145] = "!y&!z|x&y&z";
	dp[146] = "!(!x&!z|x&z|y)|x&y&z";
	dp[147] = "!(x&z|y)|x&y&z";
	dp[148] = "!(!x&!y|x&y|z)|x&y&z";
	dp[149] = "!(x&y|z)|x&y&z";
	dp[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	dp[151] = "!((x|y)&z|x&y)|x&y&z";
	dp[152] = "!y&!z&x|y&z";
	dp[153] = "!y&!z|y&z";
	dp[154] = "!x&z|!y&!z&x|y&z";
	dp[155] = "!(x&z|y)|y&z";
	dp[156] = "!x&y|!y&!z&x|y&z";
	dp[157] = "!(x&y|z)|y&z";
	dp[158] = "!x&(y|z)|!y&!z&x|y&z";
	dp[159] = "!x|!y&!z|y&z";
	dp[160] = "x&z";
	dp[161] = "!(x|y|z)|x&z";
	dp[162] = "!y&z|x&z";
	dp[163] = "!x&!y|x&z";
	dp[164] = "!x&!z&y|x&z";
	dp[165] = "!x&!z|x&z";
	dp[166] = "!x&!z&y|!y&z|x&z";
	dp[167] = "!(x|y&z)|x&z";
	dp[168] = "(x|y)&z";
	dp[169] = "!(x|y|z)|(x|y)&z";
	dp[170] = "z";
	dp[171] = "!x&!y|z";
	dp[172] = "!x&y|x&z";
	dp[173] = "!(!y&z|x)|x&z";
	dp[174] = "!x&y|z";
	dp[175] = "!x|z";
	dp[176] = "!y&x|x&z";
	dp[177] = "!y&!z|x&z";
	dp[178] = "!y&(x|z)|x&z";
	dp[179] = "!y|x&z";
	dp[180] = "!x&!z&y|!y&x|x&z";
	dp[181] = "!(x&y|z)|x&z";
	dp[182] = "!x&!z&y|!y&(x|z)|x&z";
	dp[183] = "!x&!z|!y|x&z";
	dp[184] = "!y&x|y&z";
	dp[185] = "!(!x&z|y)|y&z";
	dp[186] = "!y&x|z";
	dp[187] = "!y|z";
	dp[188] = "!x&y|!y&x|x&z";
	dp[189] = "!x&!z|!y&x|y&z";
	dp[190] = "!x&y|!y&x|z";
	dp[191] = "!x|!y|z";
	dp[192] = "x&y";
	dp[193] = "!(x|y|z)|x&y";
	dp[194] = "!x&!y&z|x&y";
	dp[195] = "!x&!y|x&y";
	dp[196] = "!z&y|x&y";
	dp[197] = "!x&!z|x&y";
	dp[198] = "!x&!y&z|!z&y|x&y";
	dp[199] = "!(x|y&z)|x&y";
	dp[200] = "(x|z)&y";
	dp[201] = "!(x|y|z)|(x|z)&y";
	dp[202] = "!x&z|x&y";
	dp[203] = "!(!z&y|x)|x&y";
	dp[204] = "y";
	dp[205] = "!x&!z|y";
	dp[206] = "!x&z|y";
	dp[207] = "!x|y";
	dp[208] = "!z&x|x&y";
	dp[209] = "!y&!z|x&y";
	dp[210] = "!x&!y&z|!z&x|x&y";
	dp[211] = "!(x&z|y)|x&y";
	dp[212] = "!z&(x|y)|x&y";
	dp[213] = "!z|x&y";
	dp[214] = "!x&!y&z|!z&(x|y)|x&y";
	dp[215] = "!x&!y|!z|x&y";
	dp[216] = "!z&x|y&z";
	dp[217] = "!(!x&y|z)|y&z";
	dp[218] = "!x&z|!z&x|x&y";
	dp[219] = "!x&!y|!z&x|y&z";
	dp[220] = "!z&x|y";
	dp[221] = "!z|y";
	dp[222] = "!x&z|!z&x|y";
	dp[223] = "!x|!z|y";
	dp[224] = "(y|z)&x";
	dp[225] = "!(x|y|z)|(y|z)&x";
	dp[226] = "!y&z|x&y";
	dp[227] = "!(!z&x|y)|x&y";
	dp[228] = "!z&y|x&z";
	dp[229] = "!(!y&x|z)|x&z";
	dp[230] = "!y&z|!z&y|x&y";
	dp[231] = "!x&!y|!z&y|x&z";
	dp[232] = "(x|y)&z|x&y";
	dp[233] = "!(x|y|z)|(x|y)&z|x&y";
	dp[234] = "x&y|z";
	dp[235] = "!x&!y|x&y|z";
	dp[236] = "x&z|y";
	dp[237] = "!x&!z|x&z|y";
	dp[238] = "y|z";
	dp[239] = "!x|y|z";
	dp[240] = "x";
	dp[241] = "!y&!z|x";
	dp[242] = "!y&z|x";
	dp[243] = "!y|x";
	dp[244] = "!z&y|x";
	dp[245] = "!z|x";
	dp[246] = "!y&z|!z&y|x";
	dp[247] = "!y|!z|x";
	dp[248] = "x|y&z";
	dp[249] = "!y&!z|x|y&z";
	dp[250] = "x|z";
	dp[251] = "!y|x|z";
	dp[252] = "x|y";
	dp[253] = "!z|x|y";
	dp[254] = "x|y|z";
	dp[255] = "!x|x";


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char tmp[10];
		scanf("%s", tmp);
		reverse(tmp, tmp + 8);
		int v = stoi(tmp, 0, 2);
		puts(dp[v].c_str());
	}
}

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
#ifdef LOCAL
	eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif
}