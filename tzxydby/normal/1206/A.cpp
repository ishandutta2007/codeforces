#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	printf("%d %d\n",a[n],b[m]); 
	return 0;
}