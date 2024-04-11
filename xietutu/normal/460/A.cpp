#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int ans;
	for(ans=1;n>0;ans++)
	{
		n--;
		if( (ans%m) ==0)
			n++;
	}
	printf("%d\n",ans-1);
	return 0;
}