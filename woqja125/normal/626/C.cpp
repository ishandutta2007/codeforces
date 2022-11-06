#include<stdio.h>
int main()
{
	int n, m, t;
	scanf("%d%d", &n, &m);
	n*=2; m*=3;
	t = n>m?m:n;
	t/=6;
	for(int i=1;i<=t;i++)
	{
		if(n<=m) n+=2;
		else m+=3;
		t = n>m?m:n;
		t/=6;
	}
	printf("%d", n<m?m:n);
	return 0;
}