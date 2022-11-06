#include<stdio.h>
int main()
{
	int n, m = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d", &t);
		if(t>m) m = t;
	}
	m -= 25;
	printf("%d\n", m>0?m:0);
	return 0;
}