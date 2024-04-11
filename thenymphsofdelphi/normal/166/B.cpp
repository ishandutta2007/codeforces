#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 1LL<<62;

struct sp
{
	LL x, y;
	sp() {}
	sp(LL a, LL b): x(a), y(b) {}
	void read() {cin>>x>>y;}
	bool operator<(const sp &rhs) const
	{
		if (y==rhs.y) return x>rhs.x;
		return y>rhs.y;
	}
};

inline sp operator- (const sp &u, const sp &v)
{return sp(u.x-v.x, u.y-v.y);}

LL det(const sp &u, const sp &v)
{return u.x*v.y - v.x*u.y;}

LL dir(const sp &p, const sp &u, const sp &v)
{return det(u-p, v-p);}

int N, M;
sp p[100010], homura;

bool inside(int N, sp c[], sp p)
{
	int l=1, r=N-1, m;
	while (l < r)
	{
		m = l+r>>1;
		if (dir(c[0], c[m], p) <= 0)
			r = m;
		else
			l = m+1;
	}
	if (r==1 || dir(c[0], c[N-1], p)>=0 || dir(c[r], c[r-1], p) >= 0) return 0;
	return 1;
}

int main()
{
	int i, j, k;
	cin>>N;
	for (i = N-1; i >= 0; --i)
		p[i].read();
	cin>>M;
	for (i = 0; i < M; ++i)
	{
		homura.read();
		if (!inside(N, p, homura))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}