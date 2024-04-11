#include <cstdio>
#include <vector>
using namespace std;

const int offset = 1 << 18, mod = 1000000007;
int tree[offset << 1];
int last[1000001];
int a[200001];
int ans[200001];
int div[1000001];
vector<pair<int, int> > vec[200001];

void insert(int p, int x)
{
    p += offset;
    tree[p] = x;
    while(p > 1)
    {
	p >>= 1;
	tree[p] = 1LL * tree[p*2] * tree[p*2+1] % mod;
    }
}

int product(int a, int b)
{
    a += offset; b += offset;
    long long ans = 1;
    while(a < b)
    {
	if(a & 1) ans = ans * tree[a++] % mod;
	if((b & 1) == 0) ans = ans * tree[b--] % mod;
	a >>= 1;
	b >>= 1;
    }
    if(a == b) ans = ans * tree[a] % mod;
    return ans;
}

int main()
{
    for(int i = 2; i <= 1000000; i++)
	if(div[i] == 0)
	{
	    div[i] = i;
	    if(i <= 1000)
		for(int j = i * i; j <= 1000000; j += i)
		    div[j] = i;
	}
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
	scanf("%d", a + i);
    int q; 
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
	int l, r;
	scanf("%d %d", &l, &r);
	vec[r].emplace_back(l, i);
    }
    for(int i = 1; i <= n; i++)
    {
	int k = a[i], x = k;
	while(x > 1)
	{
	    int d = div[x];
	    x /= d;
	    if(last[d] != i)
	    {
		k = k / d * (d - 1);
		insert(last[d], tree[offset+last[d]] / (d - 1) * d);
		last[d] = i;
	    }
	}
	insert(i, k);
	for(auto p: vec[i])
	    ans[p.second] = product(p.first, i);
    }
    for(int i = 0; i < q; i++)
	printf("%d\n", ans[i]);
}