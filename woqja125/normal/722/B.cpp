#include<stdio.h>
int p[101];
char in[1001];
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", p+i);
	fgets(in, 1000, stdin);
	for(i=1; i<=n; i++)
	{
		fgets(in, 1000, stdin);
		for(int j=0; in[j]; j++) if(in[j] == 'a' || in[j] == 'e' || in[j] == 'o' || in[j] == 'u'  || in[j] == 'i'  || in[j] == 'y') p[i]--;
		if(p[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}