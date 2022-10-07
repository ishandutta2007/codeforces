#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int calc(int n)
{
	int ans=0;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int n;
int main()
{
	scanf("%d",&n);
	while(calc(n)%4)n++;
	printf("%d\n",n);
	return 0;
}