#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
int bit[35],ans[35]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
	for(int i=0;i<=30;i++)bit[i]=(1<<i)-1;
	int T;scanf("%d",&T);
	while(T--)
	{
		int x;scanf("%d",&x);
		int p=lower_bound(bit,bit+30,x)-bit;
		if(bit[p]!=x)printf("%d\n",bit[p]);
		else printf("%d\n",ans[p]);
	}
}