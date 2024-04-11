#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 4005
using namespace std;
int T, n;
char A[maxn], B[maxn];
int a[maxn], b[maxn]; 
int ans[maxn], tot = 0;
void work(int pos)
{
	if(pos == 0) return;
	ans[++tot] = 2 * pos;
	for (int i = 1; i <= pos / 2; i++) swap(a[i], a[pos - i + 1]);
	for (int i = 1; i <= pos; i++) if(a[i] == 1 || a[i] == 2) a[i] = 3 - a[i];
}
void solve()
{
	scanf("%s%s", A + 1, B + 1);
	n = strlen(A + 1);
	tot = 0;
	n /= 2;
	int cnta[4] = {0, 0, 0, 0};
	int cntb[4] = {0, 0, 0, 0};
	for (int i = 1; i <= n; i ++)
	{
		a[i] = 2 * (A[2 * i - 1] - '0') + A[2 * i] - '0';
		b[i] = 2 * (B[2 * i - 1] - '0') + B[2 * i] - '0';
		cnta[a[i]]++, cntb[b[i]]++;
	}
	if(cnta[0] != cntb[0] || cnta[3] != cntb[3])
	{
		printf("-1\n");
		return;
	}
	int x = cnta[2] - cntb[1];
	int flag = 0, now = 0;
	for (int i = 1; i <= n; i++)
	{
		if(flag) break;
		if(a[i] == 2) now++;
		else if(a[i] == 1) now--;
		if(now == x)
		{
			flag = i;
			work(i);
			break;
		}
	}
	now = 0;
	for (int i = 1; i <= n; i++)
	{
		if(flag) break;
		if(b[i] == 2) now++;
		else if(b[i] == 1) now--;
		if(now == x)
		{
			flag = n + i;
			for (int j = 1; j <= i / 2; j++) swap(b[j], b[i - j + 1]);
			for (int j = 1; j <= i; j++) if(b[j] == 1 || b[j] == 2) b[j] = 3 - b[j];
			break;
		}
	}
//	printf("%d\n", flag);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
//			printf("%d %d %d %d\n", i, j, b[n - i + 1], a[j]);
			if(b[n - i + 1] == 1 || b[n - i + 1] == 2)
			{
				if(a[j] == 3 - b[n - i + 1])
				{
					work(j - 1);
					work(j);
//					printf("%d\n", j);
					break;
				}
			}
			else
			{
				if(a[j] == b[n - i + 1])
				{
					work(j - 1);
					work(j);
//					printf("%d\n", j);
					break;
				}
			}
		}
	} 
	if(flag > n)
	{
		ans[++tot] = 2 * (flag - n);
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}