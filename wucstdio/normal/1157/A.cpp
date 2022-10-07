#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans;
bool flag[105];
int main()
{
	scanf("%d",&n);
	while(n>100||!flag[n])
	{
		if(n<=100)flag[n]=1;
		ans++;
		n++;
		while(n%10==0)n/=10;
	}
	printf("%d\n",ans);
	return 0;
}