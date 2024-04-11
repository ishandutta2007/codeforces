#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

const int offset = 1 << 18;
int ans[offset << 1];
int l[offset << 1];
int r[offset << 1];

void insert(int k)
{
    k += offset;
    l[k] = r[k] = ans[k] = 1;
    int size = 1;
    while(k > 1)
    {
	k >>= 1;
	l[k] = l[k * 2];
	r[k] = r[k * 2 + 1];
	if(l[k] == size) l[k] += l[k * 2 + 1];
	if(r[k] == size) r[k] += r[k * 2];
	ans[k] = max(ans[k * 2], max(ans[k * 2 + 1], r[k * 2] + l[k * 2 + 1]));
	size *= 2;
    }
}

int res[200001];
pair<int, int> a[200001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
	scanf("%d", &a[i].first);
	a[i].second = i;
    }
    sort(a, a + n);
    int k = 0;
    for(int i = n - 1; i >= 0; i--)
    {
	insert(a[i].second);
	for(int j = k + 1; j <= ans[1]; j++)
	    res[j] = a[i].first;
	k = ans[1];
    }
    for(int i = 1; i <= n; i++)
	printf("%d ", res[i]);
    puts("");
}