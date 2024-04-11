#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,a[Maxn],k=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		k=min(k,a[i]/max(i-1,n-i));
	printf("%d",k);
	return 0;
}