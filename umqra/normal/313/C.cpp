#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)5e6;
const int M = (int)2e3;

struct item
{
	int a, b, c, d;
	item () {}
	item (int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
} st[N];
                  
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	int t;
	for (t = 1;; t *= 2)
		if (t * t == n)
			break;

	for (int i = 0; i < n; i++)    
		scanf("%d", &a[i]);

	sort(a, a + n, greater<int>());

	long long ans = 0;
	int pl = 1;
	int pow2 = 2;   
	int cnt;
	for (int i = 30; i >= 0; i--)
		if (t & (1 << i))
		{
			cnt = i + 1;
			break;
		}
	int last = 0;
	for (int i = 1; i <= n; i *= 4)
	{                
		for (int s = last; s < i; s++)
			ans += (long long)a[s] * (long long)cnt;
		cnt--;                  
		last = i;
	}

	cout << ans;

	return 0;
}