#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int i=1;
	while(i<n&&a[i]<a[i+1])
		i++;
	if(i==n)
	{
		puts("YES");
		return 0;
	}
	while(i<n&&a[i]>a[i+1])
		i++;
	if(i==n)
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}