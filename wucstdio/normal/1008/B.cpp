#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],b[100005];
bool f[100005][2];
int main()
{
	scanf("%d",&n);
	f[0][0]=f[0][1]=1;
	a[0]=b[0]=2147483647;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<=a[i-1]&&f[i-1][0]==1)f[i][0]=1;
		if(a[i]<=b[i-1]&&f[i-1][1]==1)f[i][0]=1;
		if(b[i]<=a[i-1]&&f[i-1][0]==1)f[i][1]=1;
		if(b[i]<=b[i-1]&&f[i-1][1]==1)f[i][1]=1;
	}
	if(f[n][0]||f[n][1])printf("YES\n");
	else printf("NO\n");
	return 0;
}