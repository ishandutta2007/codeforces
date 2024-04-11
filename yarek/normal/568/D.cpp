#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 26;
bool u[M][M];
int dp[1 << (M-1)];
short pre[1 << (M-1)];

struct line
{
    long long a, b, c;
    line(int A = 0, int B = 0, int C = 0) : a(A), b(B), c(C) { }
};

struct point
{
    long long xp, xq, yp, yq;
    point(long long Xp = 0, long long Xq = 0, long long Yp = 0, long long Yq = 0) : xp(Xp), xq(Xq), yp(Yp), yq(Yq) { }
};

bool operator==(point a, point b)
{
    return a.xp * b.xq == a.xq * b.xp && a.yp * b.yq == a.yq * b.yp;
}

bool parallel(line l1, line l2)
{
    return l1.a * l2.b == l1.b * l2.a;
}

point intersection(line l1, line l2)
{
    return point((l2.c * l1.b - l1.c * l2.b), (l1.a * l2.b - l1.b * l2.a),
		 (l2.c * l1.a - l1.c * l2.a), (l1.b * l2.a - l1.a * l2.b));
}

vector<pair<int, int> > ans;
line l[100000];

bool solve(vector<int> v, int k)
{
    if(v.empty()) return true;
    if(k == 0) return false;
    int n = v.size();
    if(n < M)
    {
	v.push_back(-2);
	vector<int> msk;
	vector<pair<int, int> > t;
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++)
		if(!u[i][j] && !parallel(l[v[i]], l[v[j]]))
		{
		    point p = intersection(l[v[i]], l[v[j]]);
		    t.push_back(make_pair(i, j));
		    vector<int> vec;
		    vec.push_back(i);
		    for(int k = 0; k < n; k++)
			if(!u[i][k] && !parallel(l[v[k]], l[v[i]]) && p == intersection(l[v[i]], l[v[k]]))
			    vec.push_back(k);
		    for(int x: vec)
			for(int y: vec)
			    u[x][y] = true;
		    int mask = 0;
		    for(int x: vec)
			mask |= 1 << x;
		    msk.push_back(mask);
		}
	for(int i = 0; i < n; i++)
	{
	    msk.push_back(1 << i);
	    t.push_back(make_pair(i, n));
	}
	int m = 1 << n;
	for(int i = 1; i < m; i++)
	    dp[i] = k + 1;
	for(int i = 0; i < msk.size(); i++)
	{
	    int x = msk[i];
	    for(int j = 0; j < m; j++)
		if(dp[j | x] > dp[j] + 1)
		{
		    dp[j | x] = dp[j] + 1;
		    pre[j | x] = i;
		}
	}
	for(int i = m - 1; i >= 0; i--)
	    for(int j = 0; j < n; j++)
		if(dp[i] > dp[i | (1 << j)])
		{
		    dp[i] = dp[i | (1 << j)];
		    pre[i] = pre[i | (1 << j)];
		}
	if(dp[m-1] > k) return false;
	for(int i = m - 1; i != 0; i &= ~msk[pre[i]])
	    ans.push_back(make_pair(v[t[pre[i]].first], v[t[pre[i]].second]));
	return true;
    }
    int rands = k * 100;
    for(int i = 0; i < rands; i++)
    {
	int a = v[rand() % n], b = v[rand() % n];
	if(parallel(l[a], l[b])) continue;
	point p = intersection(l[a], l[b]);
	vector<int> nv;
	int inter = 1;
	for(int x: v)
	    if(!parallel(l[a], l[x]) && intersection(l[a], l[x]) == p)
		inter++;
	    else if(x != a) nv.push_back(x);
	if(inter > k)
	{
	    ans.push_back(make_pair(a, b));
	    return solve(nv, k - 1);
	}
    }
    return false;
}

int main()
{
    srand(100);
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
	scanf("%lld %lld %lld", &l[i].a, &l[i].b, &l[i].c);
    vector<int> vec;
    for(int i = 0; i < n; i++)
	vec.push_back(i);
    if(solve(vec, k))
    {
	puts("YES");
	printf("%d\n", ans.size());
	for(auto p: ans)
	    printf("%d %d\n", p.first + 1, p.second + 1);
    }
    else puts("NO");
}