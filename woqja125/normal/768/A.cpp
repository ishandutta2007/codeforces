#include<stdio.h>
#include<algorithm>
int a[100001];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", a+i);
	std::sort(a+1, a+1+n);
	int i, j;
	for(i=1; i<=n && a[i] == a[1]; i++);
	for(j=n; j>=1 && a[j] == a[n]; j--);
	int ans = j-i+1;
	printf("%d", ans>0?ans:0);
	return 0;
}