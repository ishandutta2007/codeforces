#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",min(a[n-1]-a[1],a[n]-a[2]));
	return 0;
}