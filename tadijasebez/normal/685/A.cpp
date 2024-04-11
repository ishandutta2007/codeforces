#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
int sol,a,b,n,m;
vector<int> dig;
void Add()
{
	int i,tmp1,tmp2;
	do
	{
		tmp1=tmp2=0;
		for(i=0;i<a;i++) tmp1*=7,tmp1+=dig[i];
		for(i=a;i<a+b;i++) tmp2*=7,tmp2+=dig[i];
		if(tmp1<n && tmp2<m)
		{
			sol++;
			//printf("tmp1:%i tmp2:%i ",tmp1,tmp2);
			//for(i=0;i<dig.size();i++) printf("%i ",dig[i]);printf("\n");
		}
	}while(next_permutation(dig.begin(),dig.end()));
}
int main()
{
	int i,j;
	scanf("%i %i",&n,&m);
	int tmp;
	tmp=max(n-1,1);while(tmp) a++,tmp/=7;
	tmp=max(m-1,1);while(tmp) b++,tmp/=7;
	if(a+b>7) return printf("0\n"),0;
	//printf("%i %i\n",a,b);
	for(i=0;i<(1<<7);i++)
	{
		dig.clear();
		for(j=0;j<7;j++) if((i>>j)&1) dig.pb(j);
		if(dig.size()==a+b) Add();
	}
	printf("%i\n",sol);
	return 0;
}