#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
Sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
Sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
Sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 1024 * 1024;

struct st
{
	int s1, s2, dw, p1, p2;
};

int dp[4][4][2][202][202];

void go(st x)
{
	VPII V;
	
	while (x.s1 > 0 || x.s2 > 0)
	{
		PII s = MP(0, 0);
		
		debug(x.s1, x.s2, x.dw, x.p1, x.p2);
		
		while (dp[x.s1][x.s2][x.dw][x.p1][x.p2] == inf)
		{
			x.p1--;
			x.p2--;
			s.f++;
			s.s++;
		}
		int r = dp[x.s1][x.s2][x.dw][x.p1][x.p2];
		int mxi = 25;
		if (x.s1 + x.s2 == 5)
		{
			mxi = 15;
		}
		if (r > 0)
		{
			s.f += mxi;
			s.s += mxi - r;
			x.p1 -= mxi;
			x.p2 -= mxi - r;
			x.s1--;
		}
		else
		{
			s.f += mxi + r;
			s.s += mxi;
			x.p1 -= mxi + r;
			x.p2 -= mxi;
			x.s2--;
		}
		if (dp[x.s1][x.s2][1][x.p1][x.p2] == 0)
		{
			x.dw = 0;
		}
		
		V.PB(s);
	}
	
	reverse(ALL(V));
	for (auto p : V)
	{
		printf("%d:%d ", p.f, p.s);
	}
	printf("\n");
}

void solve()
{
	int a, b;
	scanf("%d%d", &a, &b);
	
	for (int i = 3; i >= -3; i--)
	{
		if (i == 0)
		{
			continue;
		}
		int x, y;
		if (i > 0)
		{
			x = 3;
			y = x - i;
		}
		else
		{
			y = 3;
			x = y + i;
		}
		
		if (dp[x][y][0][a][b])
		{
			printf("%d:%d\n", x, y);
			go({x, y, 0, a, b});
			return;
		}
		if (dp[x][y][1][a][b])
		{
			printf("%d:%d\n", x, y);
			go({x, y, 1, a, b});
			return;
		}
	}
	printf("Impossible\n");
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	queue<st> Q;
	Q.push({0, 0, 0, 0, 0});
	while (!Q.empty())
	{
		st x = Q.front();
		Q.pop();
		if (max(x.s1, x.s2) >= 3)
		{
			continue;
		}
		int mxi;
		if (x.s1 == 2 && x.s2 == 2)
		{
			mxi = 15;
		}
		else
		{
			mxi = 25;
		}
		for (int i = 2; i <= mxi; i++)
		{
			st xx = {x.s1 + 1, x.s2, x.dw || i == 2, x.p1 + mxi, x.p2 + mxi - i};
			if (xx.p1 <= 200 && xx.p2 <= 200 && dp[xx.s1][xx.s2][xx.dw][xx.p1][xx.p2] == 0)
			{
				dp[xx.s1][xx.s2][xx.dw][xx.p1][xx.p2] = i;
				Q.push(xx);
			}
			
			xx = {x.s1, x.s2 + 1, x.dw || i == 2, x.p1 + mxi - i, x.p2 + mxi};
			
			if (xx.p1 <= 200 && xx.p2 <= 200 && dp[xx.s1][xx.s2][xx.dw][xx.p1][xx.p2] == 0)
			{
				dp[xx.s1][xx.s2][xx.dw][xx.p1][xx.p2] = -i;
				Q.push(xx);
			}
		}
		if (abs(dp[x.s1][x.s2][x.dw][x.p1][x.p2]) == 2)
		{
			while (x.p1 < 200 && x.p2 < 200)
			{
				x.p1++;
				x.p2++;
				//st xx = {x.s1, x.s2, x.dw, x.p1 + 1, x.p2 + 1};
				if (dp[x.s1][x.s2][x.dw][x.p1][x.p2] == 0)
				{
					Q.push(x);
				}
				dp[x.s1][x.s2][x.dw][x.p1][x.p2] = inf;
			}
		}
	}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}


/*
3:0
25:0 25:0 25:0 
3:1
A.cpp:92:20: runtime error: index -1 out of bounds for type 'int [4][2][202][202]'
A.cpp:63:23: runtime error: index -1 out of bounds for type 'int [4][2][202][202]'
A.cpp:70:24: runtime error: index -1 out of bounds for type 'int [4][2][202][202]'
A.cpp:92:29: runtime error: index 205 out of bounds for type 'int [202][202]'
A.cpp:92:35: runtime error: index 219 out of bounds for type 'int [202]'
A.cpp:63:35: runtime error: index 205 out of bounds for type 'int [202][202]'
A.cpp:63:41: runtime error: index 219 out of bounds for type 'int [202]'
A.cpp:70:36: runtime error: index 205 out of bounds for type 'int [202][202]'
A.cpp:70:42: runtime error: index 219 out of bounds for type 'int [202]'
ASAN:SIGSEGV
=================================================================
==8786==ERROR: AddressSanitizer: SEGV on unknown address 0x00000061b200 (pc 0x0000004031ec bp 0x7ffcb60a9770 sp 0x7ffcb60a95e0 T0)
    #0 0x4031eb in go(first) (/home/tabasz/Documents/cpp/MIM/14.03/A+0x4031eb)
    #1 0x403904 in solve() (/home/tabasz/Documents/cpp/MIM/14.03/A+0x403904)
    #2 0x405221 in main (/home/tabasz/Documents/cpp/MIM/14.03/A+0x405221)
    #3 0x7fcb9424382f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2082f)
    #4 0x4020a8 in _start (/home/tabasz/Documents/cpp/MIM/14.03/A+0x4020a8)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV ??:0 go(first)
==8786==ABORTING

real	0m0.144s
user	0m0.132s
sys	0m0.008s

*/