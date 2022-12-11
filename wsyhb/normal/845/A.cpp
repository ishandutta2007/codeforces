#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",a+i);
	sort(a+1,a+2*n+1);
	printf(a[n]!=a[n+1]?"YES":"NO");
	return 0;
}