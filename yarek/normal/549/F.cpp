#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> pos[1000000];

int query(int a, int b, int k)
{
    return max(0, (int)(upper_bound(pos[k].begin(), pos[k].end(), b) - lower_bound(pos[k].begin(), pos[k].end(), a)));
}

const int offset = 1 << 19;
pair<int, int> mx[offset << 1];

pair<int, int> maxi(int a, int b)
{
    a += offset;
    b += offset;
    pair<int, int> ans(0, 0);
    while(a < b)
    {
	if(a & 1) ans = max(ans, mx[a++]);
	if((b & 1) == 0) ans = max(ans, mx[b--]);
	a >>= 1;
	b >>= 1;
    }
    if(a == b) ans = max(ans, mx[a]);
    return ans;
}

int modulo(int x, int k)
{
    x %= k;
    if(x < 0) x += k;
    return x;
}

int sum[300001];

long long solve(int a, int b, int k)
{
    if(b - a <= 0) return 0;
//     printf("solve(%d %d %d)\n", a, b, k);
    auto p = maxi(a, b);
    int m = p.second;
    long long ans = -1;
    if(m - a < b - m)
	for(int i = a; i <= m; i++)
	    ans += query(m, b, (sum[i-1] + p.first) % k);
    else
	for(int i = m; i <= b; i++)
	    ans += query(a - 1, m - 1, modulo(sum[i] - p.first, k));
    return ans + solve(a, m - 1, k) + solve(m + 1, b, k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    pos[0].push_back(0);
    for(int i = 1; i <= n; i++)
    {
	int a;
	scanf("%d", &a);
	mx[i+offset] = make_pair(a, i);
	sum[i] = (sum[i-1] + a) % k;
	pos[sum[i]].push_back(i);
    }
    for(int i = offset - 1; i > 0; i--)
	mx[i] = max(mx[i*2], mx[i*2+1]);
    printf("%lld\n", solve(1, n, k));
}