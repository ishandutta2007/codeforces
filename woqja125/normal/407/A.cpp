#include<stdio.h>
int root[1000001];
int main()
{
	int a, b, i, t;
	for(i=1; i<=1000; i++) root[i*i] = i;
	scanf("%d%d", &a, &b);
	for(i=1; i*i<a*a; i++)
	{
		if(root[a*a - i*i] != 0)
		{
			t = root[a*a - i*i];
			if(t*b%a != 0 || i*b%a != 0) continue;
			else
			{
				if(t == i*b/a) continue;
				printf("YES\n");
				printf("0 0\n");
				printf("%d %d\n", i, t);
				printf("%d %d\n", -t*b/a, i*b/a);
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}