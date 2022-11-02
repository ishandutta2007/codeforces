#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef __int64 LL;
int tw[120];
int i,n,te,ct;
char out[10][20]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int main()
{
	tw[0]=1;
	for(i=1;i<70;i++)tw[i]=tw[i-1]*2;
	while(~scanf("%d",&n))
	{
		te=0;
		while(n>5*tw[te])
		{
			n-=5*tw[te];
			te++;
		}
		ct=0;
		while(n>tw[te])
		{
			n-=tw[te];ct++;
		}
		printf("%s\n",out[ct]);
	}
}