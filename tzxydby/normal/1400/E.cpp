#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
int dfs(int l,int r,int s)
{
	if(l>r)
		return 0;
	int m=l;
	for(int i=l;i<=r;i++)
		if(a[i]<a[m])
			m=i;
	return min(dfs(l,m-1,a[m])+dfs(m+1,r,a[m])+a[m]-s,r-l+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",dfs(1,n,0));
	return 0;
}