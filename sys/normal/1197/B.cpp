#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,a[Maxn];
bool tag;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		if(a[i]<a[i+1]&&tag)
		{
			printf("No");
			return 0;
		}
		else if(a[i]>a[i+1])
			tag=true;
	printf("Yes");
	return 0;
}