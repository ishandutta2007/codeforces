#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define gprintf(...) //fprintf(stderr, __VA_ARGS__)
const int MAXN = 101010, MAXNUM = 131072, MAXL = 50;
const long long oo = 1010101010101010ll;
int n, b, q;
char input[8080808];
char *izz;
template<class T> void inputnum(T &p)
{
	p = 0;
	while(*izz < '0' || *izz > '9')
		izz++;
	while(*izz >= '0' && *izz <= '9')
		p = p * 10 + *izz++ - '0';
}
class Arrow
{
public:
	int stx, sty, edx, edy, id, next;
	void read(int id_)
	{
		inputnum(stx);
		inputnum(sty);
		inputnum(edx);
		inputnum(edy);
		id = id_;
	}
	bool operator <(const Arrow &b) const
	{
		return id < b.id;
	}
};
Arrow a[MAXN];
class Query
{
public:
	int x, y, id, next;
	long long t;
};
Query qu[MAXN], qd[MAXN], ql[MAXN], qr[MAXN];
int qun = 0, qdn = 0, qln = 0, qrn = 0;
void prepare()
{
	fread(input, 1, 8080800, stdin);
	izz = input;
	inputnum(n);
	inputnum(b);
	for(int i = 1; i <= n; i++)
		a[i].read(i);
	inputnum(q);
	for(int i = 1; i <= q; i++)
	{
		Query now;
		inputnum(now.x);
		inputnum(now.y);
		now.id = i;
		char ch = *izz++;
		while(ch != 'U' && ch != 'D' && ch != 'L' && ch != 'R')
			ch = *izz++;
		inputnum(now.t);
		if(ch == 'U')
			qu[++qun] = now;
		else if(ch == 'D')
			qd[++qdn] = now;
		else if(ch == 'L')
			ql[++qln] = now;
		else if(ch == 'R')
			qr[++qrn] = now;
	}
	a[0].id = a[0].next = 0;
}
int f[MAXN + MAXNUM];
void cover(int l, int r, int v)
{
	if(l > r)
		swap(l, r);
	gprintf("cover [%d,%d] %d\n", l, r, v);
	for(l += MAXNUM, r += MAXNUM + 2; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if(~l & 1)
			f[l ^ 1] = v;
		if(r & 1)
			f[r ^ 1] = v;
	}
}
int querymax(int x)
{
	gprintf("querymax %d: ", x);
	int ret = 0;
	for(x += MAXNUM + 1; x; x >>= 1)
		if(ret < f[x])
			ret = f[x];
	gprintf("%d\n", ret);
	return ret;
}
int nexts[MAXL][MAXN];
long long nextt[MAXL][MAXN];
class Answer
{
public:
	int x, y;
}ans[MAXN];
void getans(const Query &u)
{
	if(u.t < 0)
		return;//calculated
	gprintf("getans %d -> point %d, time %I64d\n", u.id, u.next, u.t);
	int i = 0;
	int now = u.next;
	long long t = u.t;
	while(i < MAXL && nexts[i][now] != 0 && nextt[i][now] < t)
		i++;
	for(i--; i >= 0; i--)
		if(nexts[i][now] != 0 && nextt[i][now] < t)
		{
			t -= nextt[i][now];
			now = nexts[i][now];
		}
	gprintf("%d %I64d\n", now, t);
	if(a[now].next)
	{
		int tmp;
		if(a[now].sty == a[now].edy)
		{
			if(a[now].edx > a[now].stx)
				tmp = a[a[now].next].edx - a[now].edx;
			else
				tmp = a[now].edx - a[a[now].next].edx;
			ans[u.id].x = a[a[now].next].edx;
			ans[u.id].y = a[now].edy;
		}
		else
		{
			if(a[now].edy > a[now].sty)
				tmp = a[a[now].next].edy - a[now].edy;
			else
				tmp = a[now].edy - a[a[now].next].edy;
			ans[u.id].x = a[now].edx;
			ans[u.id].y = a[a[now].next].edy;
		}
		if(t > tmp)
		{
			t -= tmp;
			if(a[a[now].next].edy == ans[u.id].y)
				ans[u.id].x += (a[a[now].next].edx > ans[u.id].x ? 1 : -1) * t;
			else
				ans[u.id].y += (a[a[now].next].edy > ans[u.id].y ? 1 : -1) * t;
			return;
		}
	}
	if(a[now].sty == a[now].edy)
	{
		ans[u.id].y = a[now].edy;
		if(a[now].edx > a[now].stx)
			ans[u.id].x = min(a[now].edx + t, (long long)b);
		else
			ans[u.id].x = max(a[now].edx - t, 0ll);
	}
	else
	{
		ans[u.id].x = a[now].edx;
		if(a[now].edy > a[now].sty)
			ans[u.id].y = min(a[now].edy + t, (long long)b);
		else
			ans[u.id].y = max(a[now].edy - t, 0ll);
	}
}
class Cmpa
{
public:
	int Arrow::*stx;
	int Arrow::*edx;
	const int &(*mn)(const int &, const int &);
	int mul;
	Cmpa(int Arrow::*stx, int Arrow::*edx, const int &(*mn)(const int &, const int &), int mul): stx(stx), edx(edx), mn(mn), mul(mul) {}
	inline bool operator()(const Arrow &a, const Arrow &b) const
	{
		return (mn(b.*stx, b.*edx) - mn(a.*stx, a.*edx)) * mul > 0;
	}
};
class Cmpq
{
public:
	int Query::*x;
	int mul;
	Cmpq(int Query::*x, int mul): x(x), mul(mul) {}
	inline bool operator()(const Query &a, const Query &b) const
	{
		return (b.*x - a.*x) * mul > 0;
	}
};
void getnext(Query *ql, int qln, int Arrow::*stx, int Arrow::*edx, int Arrow::*sty, int Arrow::*edy, int Query::*x, int Query::*y, 
	int Answer::*xx, int Answer::*yy, int mul, const int &(*mn)(const int &, const int &))
{
	gprintf("getnext q%c\n", ql == ::ql ? 'l' : ql == ::qr ? 'r' : ql == ::qu ? 'u' : ql == ::qd ? 'd' : '?');
	sort(a + 1, a + n + 1, Cmpa(stx, edx, mn, mul));
	sort(ql + 1, ql + qln + 1, Cmpq(x, mul));
	memset(f, 0, sizeof(f));
	int qz = 1;
	for(int i = 0; i <= n; i++)
	{
		if(i)
		{
			gprintf("arrow %d: %d %d %d %d\n", i, a[i].stx, a[i].edx, a[i].sty, a[i].edy);
			if((a[i].*stx - a[i].*edx) * mul > 0)
				a[i].next = a[querymax(a[i].*edy)].id;
			cover(a[i].*sty, a[i].*edy, i);
		}
		while(qz <= qln && (i == n || (mn(a[i + 1].*stx, a[i + 1].*edx) - ql[qz].*x) * mul > 0))
		{
			int now = querymax(ql[qz].*y), len;
			ql[qz].next = a[now].id;
			if(!now || ql[qz].t <= (len = abs(ql[qz].*x - a[now].*edx)))
			{
				long long tmp = ql[qz].*x + (now ? (a[now].*edx > ql[qz].*x ? 1 : -1) : -mul) * ql[qz].t;
				if(tmp < 0)
					tmp = 0;
				if(tmp > b)
					tmp = b;
				ans[ql[qz].id].*xx = tmp;
				ans[ql[qz].id].*yy = ql[qz].*y;
				ql[qz].t = -1;
				gprintf("%d a: %d %d\n", ql[qz].id, ans[ql[qz].id].x, ans[ql[qz].id].y);
			}
			else
			{
				ql[qz].t -= len;
				len = abs(a[now].*edy - ql[qz].*y);
				if(ql[qz].t <= len)
				{
					ans[ql[qz].id].*xx = a[now].*edx;
					ans[ql[qz].id].*yy = ql[qz].*y + (a[now].*edy > ql[qz].*y ? 1 : -1) * ql[qz].t;
					ql[qz].t = -1;
					gprintf("%d b: %d %d\n", ql[qz].id, ans[ql[qz].id].x, ans[ql[qz].id].y);
				}
				else
					ql[qz].t -= len;
			}
			qz++;
		}
	}
}


int main()
{
	prepare();
	
	getnext(ql, qln, &Arrow::stx, &Arrow::edx, &Arrow::sty, &Arrow::edy, &Query::x, &Query::y, &Answer::x, &Answer::y, 1, min);
	getnext(qr, qrn, &Arrow::stx, &Arrow::edx, &Arrow::sty, &Arrow::edy, &Query::x, &Query::y, &Answer::x, &Answer::y, -1, max);
	getnext(qd, qdn, &Arrow::sty, &Arrow::edy, &Arrow::stx, &Arrow::edx, &Query::y, &Query::x, &Answer::y, &Answer::x, 1, min);
	getnext(qu, qun, &Arrow::sty, &Arrow::edy, &Arrow::stx, &Arrow::edx, &Query::y, &Query::x, &Answer::y, &Answer::x, -1, max);
	
	sort(a + 1, a + n + 1);
	for(int i = 0; i < MAXL; i++)
		nexts[i][0] = 0, nextt[i][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		nexts[0][i] = a[i].next;
		nextt[0][i] = abs(a[a[i].next].edx - a[i].edx) + abs(a[a[i].next].edy - a[i].edy);
	}
	for(int i = 1; i < MAXL; i++)
		for(int j = 1; j <= n; j++)
		{
			nexts[i][j] = nexts[i - 1][nexts[i - 1][j]];
			if((nextt[i][j] = nextt[i - 1][j] + nextt[i - 1][nexts[i - 1][j]]) > oo)
				nextt[i][j] = oo;
		}
	
	for(int i = 1; i <= qun; i++)
		getans(qu[i]);
	for(int i = 1; i <= qdn; i++)
		getans(qd[i]);
	for(int i = 1; i <= qln; i++)
		getans(ql[i]);
	for(int i = 1; i <= qrn; i++)
		getans(qr[i]);
	
	for(int i = 1; i <= q; i++)
		printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}