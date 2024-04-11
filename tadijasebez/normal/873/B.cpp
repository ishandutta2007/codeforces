#include <stdio.h>
#include <map>
using namespace std;
const int N=100050;
char s[N];
int sum[N];
map<int,int> fir;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	fir[0]=0;
	int sol=0;
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(s[i]=='1'?1:-1);
		if(fir.count(sum[i]))
		{
			sol=max(sol,i-fir[sum[i]]);
			//printf("%i %i %i\n",i,sum[i],fir[sum[i]]);
		}
		else
		{
			fir[sum[i]]=i;
		}
	}
	printf("%i\n",sol);
	return 0;
}