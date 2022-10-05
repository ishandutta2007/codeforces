#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, a[Maxn];
int work(int lt, int rt, int pos)
{
	if (pos == -1) return 0;
	int tmpans = 0;
	for (int i = lt; i < rt; i++)
	{
		if ((((a[i] >> pos) & 1) == 0) && (a[i + 1] >> pos) & 1)
		{ 
			tmpans = (1 << pos) + min(work(lt, i, pos - 1), work(i + 1, rt, pos - 1));
			break;
		}
	}
	if (!tmpans) tmpans = work(lt, rt, pos - 1);
	return tmpans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	printf("%d", work(1, n, 30));
	return 0;
}