#include <cstdio>
#include <algorithm>
using namespace std;

int nr[200001];
pair<int, int> x[200000];
int left[200000];
int right[200000];
int n;

pair<int, int> findLeft(int a, int k)
{
    int ans = upper_bound(left, left + n, left[a] + k) - left - 1;
    return make_pair(ans, k - (left[ans] - left[a]));
}

pair<int, int> findRight(int a, int k)
{
    a = n - a - 1;
    int ans = upper_bound(right, right + n, right[a] + k) - right - 1;
    return make_pair(n - ans - 1, k - (right[ans] - right[a]));
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
	scanf("%d", &x[i].first);
	x[i].second = i + 1;
	left[i] = x[i].first;
	right[i] = -left[i];
    }
    sort(x, x + n);
    sort(left, left + n);
    sort(right, right + n);
    for(int i = 0; i < n; i++)
	nr[x[i].second] = i;
    while(m--)
    {
	int a, l;
	scanf("%d %d", &a, &l);
	a = nr[a];
	while(true)
	{
	    auto p1 = findLeft(a, l);
	    auto p2 = findRight(p1.first, p1.second);
// 	    printf("%d %d %d\n", a, p1.first, p2.first);
	    if(p2.first == a)
	    {
		if(l == p2.second) break;
		l %= (l - p2.second);
	    }
	    else
	    {
		a = p2.first;
		l = p2.second;
	    }
	}
	printf("%d\n", x[a].second);
    }
}