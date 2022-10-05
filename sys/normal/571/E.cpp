// C++17  CE 
#include <bits/stdc++.h>
using namespace std;

typedef pair <__int128, __int128> pll;
const int Maxn = 1005, p = 1e9 + 7;
int n;
pll ans;
vector <int> Ve1, Ve2;
template <class T>
T Abs(T x)
{
	return max(x, -x);
}
struct equ
{
	__int128 x, y, v;
} E[Maxn];
void quit(void)
{
	puts("-1"), exit(0);
}
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void get_factor(int x, vector <int> & V)
{
	int maxi = sqrt(x);
	for (int i = 2; i <= maxi; i++)
		if (x % i == 0)
		{
			V.push_back(i);
			while (x % i == 0) x /= i;
		}
	if (x != 1) V.push_back(x);
}
pll exgcd(long long x, long long y)
{
	if (!x) return make_pair(0, y < 0 ? -1 : 1);
	else
	{
		pll tmp = exgcd(y % x, x);
		return make_pair(tmp.second - y / x * tmp.first, tmp.first);
	}
}
void merge_array(pll A, pll B)
{
	int ct = 0;
	__int128 x = -0x3f3f3f3f, y = -0x3f3f3f3f;
	Ve1.clear(), Ve2.clear();
	get_factor(A.first, Ve1), get_factor(A.second, Ve1);
	sort(Ve1.begin(), Ve1.end());
	Ve1.resize(unique(Ve1.begin(), Ve1.end()) - Ve1.begin());
	get_factor(B.first, Ve2), get_factor(B.second, Ve2);
	sort(Ve2.begin(), Ve2.end());
	Ve2.resize(unique(Ve2.begin(), Ve2.end()) - Ve2.begin());
	if (Ve1 != Ve2)
	{
		ans.second = 0;
		if (A.first < B.first)
		{
			while (A.first < B.first) A.first *= A.second, ans.first++;
			if (A.first != B.first) quit();
		}
		else
		{
			while (A.first > B.first) B.first *= B.second;
			if (A.first != B.first) quit();
		}
		return ;
	}
	for (auto now : Ve1)
	{
		__int128 a = 0, b = 0, c = 0, d = 0;
		pll tmp_A = A, tmp_B = B;
		while (tmp_A.first % now == 0) tmp_A.first /= now, a++;
		while (tmp_A.second % now == 0) tmp_A.second /= now, b++;
		while (tmp_B.first % now == 0) tmp_B.first /= now, c++;
		while (tmp_B.second % now == 0) tmp_B.second /= now, d++;
		a += b * ans.first, b *= ans.second;
		if (!b && !d)
		{
			if (a != c) quit();
		}
		else
		{
			if (!b)
			{
				if (c > a || (a - c) % d) quit();
				if (y == -0x3f3f3f3f) y = (a - c) / d;
				else if ((a - c) / d != y) quit();
			}
			else if (!d)
			{
				if (c < a || (c - a) % b) quit();
				if (x == -0x3f3f3f3f) x = (c - a) / b;
				else if ((c - a) / b != x) quit();
			}
			else
			{
				__int128 g = __gcd(b, d);
				if ((c - a) % g) quit();
				if (c - a < 0) g *= -1;
				E[++ct] = (equ){b / g, -d / g, (c - a) / g};
			}
		}	
	}
	int las = 0;
	for (int i = 1; i <= ct; i++)
	{
		if (x != -0x3f3f3f3f && y != -0x3f3f3f3f)
		{
			if (E[i].x * x + E[i].y * y != E[i].v) quit();
		}
		else if (x != -0x3f3f3f3f)
		{
			if (!E[i].y) continue;
			if ((E[i].v - E[i].x * x) % E[i].y) quit();
			y = (E[i].v - E[i].x * x) / E[i].y;
		}
		else if (y != -0x3f3f3f3f)
		{
			if (!E[i].x) continue;
			if ((E[i].v - E[i].y * y) % E[i].x) quit();
			x = (E[i].v - E[i].y * y) / E[i].x;
		}
		else if (!las) las = i;
		else
		{
			if (make_pair(E[i].x, E[i].y) == make_pair(E[las].x, E[las].y))
			{
				if (E[i].v != E[las].v) quit();
				continue;
			}
			int l = E[i].x * E[las].x / __gcd(E[i].x, E[las].x);
			E[i].v *= l / E[i].x, E[i].y *= l / E[i].x, E[i].x = l;
			E[las].v *= l / E[las].x, E[las].y *= l / E[las].x, E[las].x = l;
			y = (E[i].v - E[las].v) / (E[i].y - E[las].y);
			if ((E[i].v - E[i].y * y) % E[i].x) quit();
			x = (E[i].v - E[i].y * y) / E[i].x;
		}
	}
	if (x != -0x3f3f3f3f)
		return (void) (ans.first += x * ans.second, ans.second = 0);
	if (y != -0x3f3f3f3f)
		return (void) (ans.second = 0);
	pll tmp = exgcd(E[las].x, E[las].y);
	tmp.first *= E[las].v, tmp.second *= E[las].v;
	if (tmp.first < 0)
	{
		__int128 d = -tmp.first / (__int128) Abs(E[las].y) + 1;
		tmp.first += d * Abs(E[las].y), tmp.second += d * Abs(E[las].x);
	}
	if (tmp.second < 0)
	{
		__int128 d = -tmp.second / (__int128) Abs(E[las].x) + 1;
		tmp.first += d * Abs(E[las].y), tmp.second += d * Abs(E[las].x);
	}
	int d = min(tmp.first / (__int128) Abs(E[las].y), tmp.second / (__int128) Abs(E[las].x));
	tmp.first -= d * Abs(E[las].y), tmp.second -= d * Abs(E[las].x);
	ans.first += ans.second * tmp.first;
	ans.second *= Abs(E[las].y);
}
long long x[Maxn], y[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
		if (i == 1) ans = make_pair(0, 1);
		else merge_array(make_pair(x[1], y[1]), make_pair(x[i], y[i]));
	}
	printf("%lld", x[1] * fast_pow(y[1], ans.first) % p);
	return 0;
}