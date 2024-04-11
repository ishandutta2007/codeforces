#include <stdio.h>
char dat[200005];
int len[200005];
bool visited[200005];
int main()
{
	int n;
	scanf("%d%s", &n, dat);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &len[i]);
	}

	for (int t = 0; visited[t] == false;)
	{
		visited[t] = true;
		t = t + len[t] * (dat[t] == '<' ? -1 : 1);
		if (t < 0 || t >= n)
		{
			printf("FINITE\n");
			return 0;
		}
	}
	printf("INFINITE\n");
}