#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",x>>1);
	}
	return 0;
}