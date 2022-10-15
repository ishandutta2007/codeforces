#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t,L,v,l,r; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&L,&v,&l,&r);
		printf("%d\n",L/v+(l-1)/v-r/v);
	}
	return 0;
}
//