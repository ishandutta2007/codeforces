#include <stdio.h>
int dat[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
	for (int i = 0; i < n; i++) printf("%d ", dat[i] + dat[i+1]);
}