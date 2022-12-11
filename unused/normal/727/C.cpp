#include "bits/stdc++.h"
using namespace std;

int dat[5005];

int main()
{
	int n;
	scanf("%d",&n);

	int aa, bb, cc;
	printf("? 1 2\n"); fflush(stdout); scanf("%d", &aa);
	printf("? 1 3\n"); fflush(stdout); scanf("%d", &bb);
	printf("? 2 3\n"); fflush(stdout); scanf("%d", &cc);

	dat[0] = (aa + bb + cc) / 2 - cc;
	dat[1] = (aa + bb + cc) / 2 - bb;
	dat[2] = (aa + bb + cc) / 2 - aa;

	for (int i = 3; i < n; i++)
	{
		printf("? 1 %d\n", i + 1);
		fflush(stdout);
		scanf("%d",&dat[i]);
		dat[i] -= dat[0];
	}
	printf("!");
	for (int i = 0; i < n; i++) printf(" %d", dat[i]);
	printf("\n");
	fflush(stdout);

	while (getchar() != -1)
		;
}