#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],f[N],n,m,k,h[N];
int cmp(int x,int y)
{
	return a[x]<a[y];
}
int pd(int x)
{
	for (int i=x+1;i<=n;i++)
	 if (a[f[i-x]]+k+1>a[f[i]])return 0;
	return 1; 
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),f[i]=i;
	int l=1,r=n;
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=n;i++)h[f[i]]=i;
	while (l<r)
	 {
	 	int mid=(l+r)/2;
	 	if (!pd(mid))l=mid+1;
	 	else r=mid;
	 }
	printf("%d\n",l);
	for (int i=1;i<=n;i++)printf("%d ",h[i]%l+1);
}