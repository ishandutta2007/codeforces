#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
int n, k, ans, pos1, val1, pos2, val2, tmp_val, tmp_pos, Q[Maxn], ct;
int main()
{
	scanf("%d%d", &n, &k);
	printf("? ");
	for (int i = 1; i <= k; i++)
		printf("%d ", i);
	printf("\n");
	fflush(stdout);
	scanf("%d%d", &pos1, &val1);
	printf("? ");
	for (int i = 1; i <= k + 1; i++)
		if (i != pos1) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	scanf("%d%d", &pos2, &val2);
	if (val1 > val2) swap(val1, val2), swap(pos1, pos2);
	for (int i = 1; i <= k + 1; i++)
		if (i != pos1) Q[++ct] = i;
	for (int i = 1; i <= k; i++)
	{
		if (Q[i] == pos2) continue;
		int now = Q[i];
		Q[i] = pos1;
		printf("? ");
		for (int j = 1; j <= k; j++)
			printf("%d ", Q[j]);
		printf("\n");
		fflush(stdout);
		scanf("%d%d", &tmp_pos, &tmp_val);
		if (tmp_val == val2) ans++;
		Q[i] = now;
	}
	printf("! %d\n", ans + 1);
	fflush(stdout);
	return 0;
}