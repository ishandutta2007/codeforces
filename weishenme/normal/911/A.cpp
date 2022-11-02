#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],b[N],f[N],n;
int cmp(int x,int y)
{
	return a[x]<a[y]||(a[x]==a[y]&&b[x]<b[y]); 
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=f[i]=i;
	sort(f+1,f+n+1,cmp);
	int M=2e9,ans=2e9,k=2e9;
	for (int i=1;i<n;i++)M=min(abs(a[f[i]]-a[f[i+1]]),M);
	for (int i=1;i<n;i++)
	 if (abs(a[f[i]]-a[f[i+1]])==M&&a[f[i]]==a[f[1]])
	  {ans=min(ans,abs(b[f[i]]-b[f[i+1]]));k=a[f[i]];}
	printf("%d\n",ans);
}