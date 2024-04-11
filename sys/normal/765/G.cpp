#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005, p = 1e9 + 7;
int n, m, ct, cntS, mini, maxi, maxi23, tmp_d[Maxn], d[Maxn], Popcnt[1 << 21 | 5];
long long s, ans = 1, f2[45], g2[45];
string str;
struct quad
{
	unsigned s1, s2, c1, c2;
	quad (int _s1, int _s2, int _c1, int _c2)
	{
		s1 = _s1, s2 = _s2, c1 = _c1, c2 = _c2;
	}
};
unsigned get_hash(unsigned _s1, unsigned _s2, unsigned _c1, unsigned _c2)
{
	return (_s1 << 21) | (_s2 << 10) | (_c1 << 5) | _c2;
}
quad trans(unsigned x)
{
	return quad(x >> 21, (x & ((1 << 21) - 1)) >> 10, (x & ((1 << 10) - 1)) >> 5, x & ((1 << 5) - 1));
}
const int Maxh = 30000005;
struct Hashtable
{
	int cnt, head[Maxh], value[7000005], pre[7000005];
	unsigned key[7000005];
	Hashtable()
	{
		cnt = 0;
		memset(pre, -1, sizeof(pre));
		memset(head, -1, sizeof(head));
	}
	void add(unsigned now, int y)
	{
		int pos = now % 30000001;
		for (int i = head[pos]; ~i; i = pre[i])
			if (key[i] == now)
			{
				(value[i] += y) %= p;
				return ;
			}
		pre[++cnt] = head[pos];
		value[cnt] = y;
		key[cnt] = now;
		head[pos] = cnt;
	}
	void clear(void)
	{
		cnt = 0;
		memset(pre, -1, sizeof(pre));
		memset(head, -1, sizeof(head));
		memset(value, 0, sizeof(value));
	}
	void swap(Hashtable &y)
	{
		std::swap(head, y.head);
		std::swap(value, y.value);
		std::swap(pre, y.pre);
		std::swap(key, y.key);
		std::swap(cnt, y.cnt);
	}
} f1, g1;
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
int popcnt(long long x)
{
	return Popcnt[x >> 21] + Popcnt[x & ((1 << 21) - 1)];
}
vector <pair <long long, long long> > S1, Stmp;
map <long long, long long> Ma;
void work1(int x)
{
	if (x == maxi23)
	{
		for (vector <pair <long long, long long> > :: iterator it = S1.begin(); it != S1.end(); it++)
			for (int i = 0; i < x; i++)
			{
				long long tmp = it -> first;
				for (int j = i; j < m; j += x)
					tmp |= 1LL << j;
				if ((tmp & s) != tmp) continue;
				pair <long long, long long> now = make_pair(tmp, it -> second);
				long long mid_now = (now.first & ((1LL << mini) - 1)) ^ (now.first & maxi), mid_goal = (s & ((1LL << mini) - 1)) ^ (s & maxi);
				long long lt_now = now.first & maxi, rt_now = now.first >> mini;
				long long lt_goal = s & maxi, rt_goal = s >> mini;
				f1.add(get_hash((int)(lt_now & lt_goal), (int)(rt_now & rt_goal), popcnt(mid_now), popcnt(mid_now ^ mid_goal)), now.second);
			}
	}
	else
	{
		for (vector <pair <long long, long long> > :: iterator it = S1.begin(); it != S1.end(); it++)
			for (int i = 0; i < x; i++)
			{
				long long tmp = it -> first;
				for (int j = i; j < m; j += x)
					tmp |= 1LL << j;
				if ((tmp & s) != tmp) continue;
				if (x != 19) (Ma[tmp] += it -> second) %= p;
				else Stmp.push_back(make_pair(tmp, it -> second));
			}
		for (map <long long, long long> :: iterator it = Ma.begin(); it != Ma.end(); it++)
			Stmp.push_back(*it);
		Ma.clear();
	}
	S1.swap(Stmp);
	Stmp.clear();
}
void trans(int x, int y)
{
	for (int i = 0; i <= f1.cnt; i++)
		if (f1.value[i])
		{
			quad now = trans(f1.key[i]);
			int tmp1 = now.s1 & ((1 << x) - 1), tmp2 = now.s2 >> (y - x);
			int delta1 = tmp1 ^ now.s1, delta2 = now.s2 ^ (tmp2 << (y - x));
			int done1 = ((s & ((1 << y) - 1)) ^ (s & ((1 << x) - 1))) ^ delta1, done2 = ((s >> (m - y)) & ((1 << (y - x)) - 1)) ^ delta2;
			g1.add(get_hash(tmp1, tmp2, now.c1 + popcnt(delta1) + popcnt(delta2), now.c2 + popcnt(done1) + popcnt(done2)), f1.value[i]);
		}
	f1.swap(g1);
	g1.clear();
}
void work2(int x)
{
	for (int i = 0; i <= f1.cnt; i++)
		if (f1.value[i])
		{
			quad now = trans(f1.key[i]);
			for (int q = mini - x; q < m - mini; q++)
			{
				if (q >= 0 && q + x < m && str[q] == '0' && str[q + x] == '0')
				{
					long long tmp = ((now.s2 | (1LL << (q + x - mini))) << mini) + (now.s1 | (1 << q));
					if ((tmp & s) == tmp)
						g1.add(get_hash(now.s1 | (1 << q), now.s2 | (1 << (q + x - mini)), now.c1, now.c2), f1.value[i]);
				}
				if (q + x >= m && str[q] == '0')
				{
					long long tmp = ((long long) now.s2 << mini) + (now.s1 | (1 << q));
					if ((tmp & s) == tmp)
						g1.add(get_hash(now.s1 | (1 << q), now.s2, now.c1, now.c2), f1.value[i]);
				}
				if (q < 0 && str[q + x] == '0')
				{
					long long tmp = ((now.s2 | (1LL << (q + x - mini))) << mini) + now.s1;
					if ((tmp & s) == tmp)
						g1.add(get_hash(now.s1, now.s2 | (1 << (q + x - mini)), now.c1, now.c2), f1.value[i]);
				}
			}
			if (now.c1) g1.add(get_hash(now.s1, now.s2, now.c1, now.c2), now.c1 * (long long) f1.value[i] % p);
			if (now.c2) g1.add(get_hash(now.s1, now.s2, now.c1 + 1, now.c2 - 1), now.c2 * (long long) f1.value[i] % p);
		}
	f1.swap(g1);
	g1.clear();
}
void work3(int x)
{
	for (int i = 0; i <= m; i++)
		g2[i] = f2[i] * (x - m) % p;
	for (int i = 0; i <= m; i++)
	{
		(g2[i] += i * f2[i]) %= p;
		(g2[i + 1] += (cntS - i) * f2[i]) %= p;
	}
	memcpy(f2, g2, sizeof(g2));
}
int main()
{
	for (int i = 0; i < (1 << 21); i++)
		Popcnt[i] = Popcnt[i >> 1] + (i & 1);
	ios::sync_with_stdio(false);
	cin >> str >> n;
	m = str.size();
	for (int i = 0; i < m; i++)
		if (str[i] == '0') s |= 1LL << i;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> d[i] >> x;
		(ans *= fast_pow(d[i], x - 1)) %= p;
	}
	sort(d + 1, d + 1 + n);
	mini = min(m, 31);
	S1.push_back(make_pair(0, 1));
	for (int i = 1; i <= n; i++)
		if (d[i] <= 23) maxi23 = max(maxi23, d[i]);
		else mini = min(mini, d[i]);
	maxi = (1 << (m - mini)) - 1;
	for (int i = 1; i <= n; i++)
		if (d[i] <= 23) work1(d[i]);
	if (!maxi23)
	{
		long long mid_goal = (s & ((1LL << mini) - 1)) ^ (s & maxi);
		f1.add(get_hash(0, 0, 0, popcnt(mid_goal)), 1);
	}
	int las = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] > 23 && d[i] < m)
		{
			if (las && d[i] != 37) trans(m - d[i], m - las), mini = d[i], maxi = (1 << (m - mini)) - 1;
			work2(d[i]);
			las = d[i];
		}
	for (int i = 0; i <= f1.cnt; i++)
		if (f1.value[i])
		{
			quad now = trans(f1.key[i]);
			(f2[popcnt(now.s1) + popcnt(now.s2) + now.c1] += f1.value[i]) %= p;
		}
	cntS = popcnt(s);
	for (int i = 1; i <= n; i++)
		if (d[i] >= m && d[i] > 23) work3(d[i]);
	cout << f2[cntS] * ans % p << endl;
	return 0;
}