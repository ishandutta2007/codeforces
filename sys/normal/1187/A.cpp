#include <bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",max(a-b+1,a-c+1));
	}
	return 0;
}