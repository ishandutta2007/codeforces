#include <bits/stdc++.h>
using namespace std;
int a[5],d; 
int main()
{
	scanf("%d%d%d%d",&a[1],&a[2],&a[3],&d);
	sort(a+1,a+1+3);
	printf("%d",max(0,d-a[2]+a[1])+max(0,d+a[2]-a[3]));
	return 0;
}