#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],last1,last2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)last1=i;
		else last2=i;
	}
	if(last1==0)last1=n;
	if(last2==0)last2=n;
	printf("%d\n",min(last1,last2));
	return 0;
}