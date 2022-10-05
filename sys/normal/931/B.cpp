#include <bits/stdc++.h>
using namespace std;
int rot,n,a,b;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	a+=(n-1);
	b+=(n-1);
	rot=log2(n);
	for(int i=1;i<rot;i++)
	{
		a/=2;
		b/=2;
		if(a==b){printf("%d",i); return 0;}
	}
	printf("Final!");
	return 0;
}