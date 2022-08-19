#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

struct tans
{
	int rows, cols;
	vector<string> a;
	
	tans(int rows_, int cols_)
	{
		rows = rows_;
		cols = cols_;
		a.resize(rows, string(cols, ' '));
	}
};

void place(tans &big, tans &small, int x, int y)
{
	assert(x + small.rows <= big.rows);
	assert(y + small.cols <= big.cols);
	for (int i = 0; i < small.rows; i++)
	{
		for (int j = 0; j < small.cols; j++) big.a[i + x][j + y] = small.a[i][j];
	}
}

void drawrect(tans &a, int x1, int y1, int x2, int y2, char c)
{
	assert(x1 >= 0 && x1 <= x2 && x2 < a.rows);
	assert(y1 >= 0 && y1 <= y2 && y2 < a.cols);
	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++) a.a[i][j] = c;
	}
}

void drawvbord(tans &a, int x1, int y1, int x2, int y2)
{
	drawrect(a, x1, y1, x2, y2, '+');
	if (x1 + 1 <= x2 - 1) drawrect(a, x1 + 1, y1, x2 - 1, y2, '|');
}

void drawarr(tans &a, int x1, int y1, int x2, int y2)
{
	drawrect(a, x1, y1, x2, y2, '-');
	a.a[x1][y2] = '>';
}

tans simple(string s)
{
	tans ans(3, 4 + s.size());
	drawrect(ans, 0, 1, 0, ans.cols - 2, '-');
	drawrect(ans, 2, 1, 2, ans.cols - 2, '-');
	drawrect(ans, 0, 0, ans.rows - 1, 0, '+');
	drawrect(ans, 0, ans.cols - 1, ans.rows - 1, ans.cols - 1, '+');
	for (int i = 0; i < (int)s.size(); i++) ans.a[1][2 + i] = s[i];
	return ans;
}

char s[105];
int curpos;

tans readexpr();
tans readterm();

tans readatom()
{
	string curtoken = "";
	while (isalpha(s[curpos]))
	{
		curtoken += s[curpos];
		curpos++;
	}
	if (s[curpos] == '*' || s[curpos] == '+' || s[curpos] == '?')
	{
		curtoken.pop_back();
		curpos--;
	}
	if (!curtoken.empty())
	{
		return simple(curtoken);
	}
	tans ans(1, 1);
	if (s[curpos] == '(')
	{
		curpos++;
		ans = readexpr();
		assert(s[curpos] == ')');
		curpos++;
	} else
	{
		ans = simple(string(1, s[curpos]));
		curpos++;
	}
	while (s[curpos] == '*' || s[curpos] == '+' || s[curpos] == '?')
	{
		if (s[curpos] == '*')
		{
			tans me(ans.rows + 5, ans.cols + 6);
			place(me, ans, 3, 3);
			drawrect(me, 1, 1, 1, me.cols - 3, '-');
			me.a[1][me.cols - 2] = '>';
			drawrect(me, me.rows - 1, 2, me.rows - 1, me.cols - 2, '-');
			me.a[me.rows - 1][1] = '<';
			drawvbord(me, 1, 0, 4, 0);
			drawvbord(me, 4, 0, me.rows - 1, 0);
			drawvbord(me, 1, me.cols - 1, 4, me.cols - 1);
			drawvbord(me, 4, me.cols - 1, me.rows - 1, me.cols - 1);
			drawarr(me, 4, 1, 4, 2);
			drawarr(me, 4, me.cols - 3, 4, me.cols - 2);
			ans = me;
		} else if (s[curpos] == '+')
		{
			tans me(ans.rows + 2, ans.cols + 6);
			place(me, ans, 0, 3);
			drawrect(me, me.rows - 1, 2, me.rows - 1, me.cols - 2, '-');
			me.a[me.rows - 1][1] = '<';
			drawvbord(me, 1, 0, me.rows - 1, 0);
			drawvbord(me, 1, me.cols - 1, me.rows - 1, me.cols - 1);
			drawarr(me, 1, 1, 1, 2);
			drawarr(me, 1, me.cols - 3, 1, me.cols - 2);
			ans = me;
		} else if (s[curpos] == '?')
		{
			tans me(ans.rows + 3, ans.cols + 6);
			place(me, ans, 3, 3);
			drawrect(me, 1, 1, 1, me.cols - 3, '-');
			me.a[1][me.cols - 2] = '>';
			drawvbord(me, 1, 0, 4, 0);
			drawvbord(me, 1, me.cols - 1, 4, me.cols - 1);
			drawarr(me, 4, 1, 4, 2);
			drawarr(me, 4, me.cols - 3, 4, me.cols - 2);
			ans = me;
		}
		curpos++;
	}
	return ans;
}

tans readterm()
{
	tans ans(1, 1);
	while (s[curpos] != '|' && s[curpos] != ')' && s[curpos] != '\0')
	{
		auto res = readatom();
		if (ans.rows == 1) ans = res;
		else
		{
			tans me(max(ans.rows, res.rows), ans.cols + res.cols + 2);
			place(me, ans, 0, 0);
			place(me, res, 0, ans.cols + 2);
			drawarr(me, 1, ans.cols, 1, ans.cols + 1);
			ans = me;
		}
	}
	return ans;
}

tans readexpr()
{
	vector<tans> terms;
	while (s[curpos] != ')' && s[curpos] != '\0')
	{
		auto res = readterm();
		terms.pb(res);
		if (s[curpos] != '|') break;
		assert(s[curpos] == '|');
		curpos++;
	}
	if ((int)terms.size() == 1) return terms[0];
	int width = 0;
	int height = 0;
	for (auto &t : terms)
	{
		width = max(width, t.cols);
		height += t.rows + 1;
	}
	height -= 1;
	width += 6;
	
	tans me(height, width);
	int cury = 0;
	int last = -1;
	for (auto &t : terms)
	{
		place(me, t, cury, 3);
		drawarr(me, cury + 1, 1, cury + 1, 2);
		drawarr(me, cury + 1, 3 + t.cols, cury + 1, me.cols - 2);
		if (last != -1)
		{
			drawvbord(me, last, 0, cury + 1, 0);
			drawvbord(me, last, me.cols - 1, cury + 1, me.cols - 1);
		}
		last = cury + 1;
		cury += t.rows + 1;
	}
	return me;
}

tans readfinal()
{
	curpos = 0;
	auto ans = readexpr();
	tans me(ans.rows, ans.cols + 6);
	place(me, ans, 0, 3);
	drawarr(me, 1, 1, 1, 2);
	drawarr(me, 1, me.cols - 3, 1, me.cols - 2);
	me.a[1][0] = 'S';
	me.a[1][me.cols - 1] = 'F';
	return me;
}

int main()
{
	scanf("%s", s);
	tans ans = readfinal();
	printf("%d %d\n", ans.rows, ans.cols);
	for (auto &t : ans.a) printf("%s\n", t.c_str());
    return 0;
}