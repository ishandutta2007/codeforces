#include<stdio.h>
int d[4][5001];
int min(int a, int b){return a>b?b:a;}
int min(int a, int b, int c){return min(a, min(b, c));}
int main()
{
	int n, i, t;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &t);
		d[t][++d[t][0]] = i;
	}
	printf("%d\n", t=min(d[1][0], d[2][0], d[3][0]));
	for(i=1; i<=t; i++)printf("%d %d %d\n", d[1][i], d[2][i], d[3][i]);
	return 0;
}