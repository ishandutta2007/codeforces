#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct answer
{
    unsigned key: 20;
    unsigned value: 20;
    answer(unsigned Key = 0, unsigned Value = 0) : key(Key), value(Value) { }
};

inline bool operator<(answer a, answer b)
{
    return a.key < b.key;
}

const int offset = 1 << 18;
vector<answer> tree[offset << 1];
int *sum;
pair<int, int> *best;
int *items[offset << 1];
char size[offset << 1];
int n, m;

int pa, pb, pq;

void _insert(int v, int a, int b)
{
    if(a >= pb || b <= pa) return;
    if(a >= pa && b <= pb)
    {
	sum[v]++;
	best[v].first++;
    }
    else
    {
	int prev = best[v].second;
	_insert(v * 2, a, (a + b) / 2);
	_insert(v * 2 + 1, (a + b) / 2, b);
	best[v] = min(best[v * 2], best[v * 2 + 1]);
	best[v].first += sum[v];
	if(prev != best[v].second)
	    tree[v].push_back(answer(pq, best[v].second));
    }
}

void insert(int a, int b, int q)
{
    pa = a; pb = b + 1; pq = q;
    _insert(1, 0, offset);
}

int count_sum(int a, int b, int q)
{
    a += offset;
    b += offset;
    int ans = 0;
    while(a < b)
    {
	if(a & 1)
	{
	    ans += lower_bound(items[a], items[a] + (1 << size[a]), q) - items[a];
	    a++;
	}
	if((b & 1) == 0)
	{
	    ans += lower_bound(items[b], items[b] + (1 << size[b]), q) - items[b];
	    b--;
	}
	a >>= 1;
	b >>= 1;
    }
    if(a == b) ans += lower_bound(items[a], items[a] + (1 << size[a]), q) - items[a];
    return ans;
}

int solve(int a, int b, int q, int pq)
{
    int ans = 1000000;
    a += offset;
    b += offset;
    while(a < b)
    {
	if(a & 1)
	{
	    auto it = upper_bound(tree[a].begin(), tree[a].end(), answer(pq));
	    int v = (--it)->value;
	    ans = min(ans, count_sum(v, v + m - 1, q));
	    a++;
	}
	if((b & 1) == 0)
	{
	    auto it = upper_bound(tree[b].begin(), tree[b].end(), answer(pq));
	    int v = (--it)->value;
	    ans = min(ans, count_sum(v, v + m - 1, q));
	    b--;
	}
	a >>= 1;
	b >>= 1;
    }
    if(a == b)
    {
	auto it = upper_bound(tree[a].begin(), tree[a].end(), answer(pq));
	int v = (--it)->value;
	ans = min(ans, count_sum(v, v + m - 1, q));
    }
    return ans;
}

pair<int, int> a[200000];
int nr[200001];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
	scanf("%d", &a[i].first);
	a[i].second = i;
    }
    sort(a, a + n);
    sum = new int[offset << 1];
    best = new pair<int, int>[offset << 1];
    for(int i = offset; i < offset * 2; i++)
    {
	best[i].second = i - offset;
	tree[i].push_back(answer(0, best[i].second));
    }
    for(int i = offset - 1; i > 0; i--)
    {
	best[i].second = best[i * 2].second;
	tree[i].push_back(answer(0, best[i].second));
    }
    nr[0] = 1;
    for(int i = 0; i < n; i++)
    {
	if(i > 0)
	{
	    nr[i] = nr[i-1];
	    if(a[i].first != a[i-1].first) nr[i]++;
	}
	insert(max(0, a[i].second - m + 1), a[i].second, nr[i]);
    }
    nr[n] = nr[n-1] + 1;
    delete[] sum;
    delete[] best;
    for(int i = offset; i < offset * 2; i++)
	items[i] = new int[1];
    for(int i = 0; i < n; i++)
	items[a[i].second + offset][0] = a[i].first;
    for(int i = offset - 1; i > 0; i--)
    {
	size[i] = size[i * 2] + 1;
	int s = 1 << size[i * 2];
	items[i] = new int[s * 2];
	merge(items[i * 2], items[i * 2] + s, items[i * 2 + 1], items[i * 2 + 1] + s, items[i]);
    }
    int s, ans = 0;
    scanf("%d", &s);
    while(s--)
    {
	int l, r, x;
	scanf("%d %d %d", &l, &r, &x);
	x ^= ans;
	l--; r--;
	int px = nr[lower_bound(a, a + n, make_pair(x, 0)) - a] - 1;
	ans = solve(l, r, x, px);
	printf("%d\n", ans);
    }
}