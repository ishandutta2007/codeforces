#include <stdio.h>
#include <functional>
#include <algorithm>
using namespace std;

int dat[100005];

int main()
{
	int n, n1, n2;
	scanf("%d%d%d", &n, &n1, &n2);
	if (n1 > n2) swap(n1, n2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}
	sort(dat, dat + n, greater<int>());
	long long s1 = 0, s2 = 0;
	for (int i = 0; i < n1; i++) s1 += dat[i];
	for (int i = n1; i < n1 + n2; i++) s2 += dat[i];
	printf("%.9f", (n1?s1/(double)n1:0) + (n2?s2/(double)n2:0));
}