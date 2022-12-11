#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;

char ch[N];
ll cnt[N];
int id = 0;

ll solve(ll a, ll b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a > b)
	{
		ch[id] = 'A';
		cnt[id++] = a / b;
		a = a % b;
		return solve(a, b);
	}
	else
	{
		ch[id] = 'B';
		cnt[id++] = b / a;
		b = b % a;
		return solve(a, b);
	}
}

int main()
{
	ll a, b;
	cin >> a >> b;
	ll g = solve(a, b);
	if (g != 1)
		puts("Impossible");
	else
	{
		cnt[id - 1]--;
		for (int i = 0; i < id; i++)
			cout << cnt[i] << ch[i];
	}
	return 0;
}