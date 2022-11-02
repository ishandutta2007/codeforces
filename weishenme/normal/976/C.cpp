#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,f[N],a[N],g1[N],g2[N],b[N];
int cmp(int x,int y)
{
	return a[x]<a[y]||(a[x]==a[y]&&b[x]>b[y]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),f[i]=i;
	sort(f+1,f+n+1,cmp);
	g1[n]=b[f[n]];g2[n]=n;
	for (int i=n-1;i;i--)
	 {
	 	if (b[f[i]]>=g1[i+1])
	 	 {
	 	 	printf("%d %d",f[g2[i+1]],f[i]);
	 	 	return 0;
	 	 }
	 	g1[i]=b[f[i]];g2[i]=i; 
	 }
	puts("-1 -1"); 
}