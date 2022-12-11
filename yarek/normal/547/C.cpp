#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int divv[500001];
int a[200000];
int num[500001];
bool b[200000];

vector<int> fac(int x)
{
    vector<int> vec;
    while(x > 1)
    {
	int k = divv[x];
	vec.push_back(k);
	while(x % k == 0) x /= k;
    }
    return vec;
}

int main()
{
    for(int i = 2; i <= 500000; i++)
	if(divv[i] == 0)
	{
	    divv[i] = i;
	    if(i < 1000)
		for(int j = i * i; j <= 500000; j += i)
		    divv[j] = i;
	}
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
	scanf("%d", a + i);
    long long ans = 0;
    int k = 0;
    while(q--)
    {
	int t;
	scanf("%d", &t);
	t--;
	if(b[t])
	{
	    b[t] = false;
	    k--;
	    vector<int> vec = fac(a[t]);
	    int l = 0;
	    for(int i = 1; i < (1 << vec.size()); i++)
	    {
		int p = 1;
		for(int j = 0; j < vec.size(); j++)
		    if(i & (1 << j)) p *= vec[j];
// 		printf("%d: %d\n", a[t], pro[i]);
		num[p]--;
		l += num[p] * (__builtin_popcount(i) % 2 ? 1 : -1);
	    }
	    ans -= k - l;
	    printf("%lld\n", ans);
	}
	else
	{
	    b[t] = true;
	    vector<int> vec = fac(a[t]);
	    int l = 0;
	    for(int i = 1; i < (1 << vec.size()); i++)
	    {
		int p = 1;
		for(int j = 0; j < vec.size(); j++)
		    if(i & (1 << j)) p *= vec[j];
// 		printf("%d: %d\n", a[t], pro[i]);
		l += num[p] * (__builtin_popcount(i) % 2 ? 1 : -1);
		num[p]++;
	    }
// 	    printf("l = %d\n", l);
	    ans += k - l;
	    k++;
	    printf("%lld\n", ans);
	}
    }
}