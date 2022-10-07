#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,n;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	a=min(a,n),b=min(b,n);
	int ans=0;
	for(int i=n-a;i<=b;i++)ans++;
	printf("%d\n",ans);
	return 0;
}