#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int P=1000003;
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		int ans=1;
		for(int i=1;i<n;i++)
		{
			ans=(ans*3)%P;
		}
		printf("%d\n",ans);
	}
}