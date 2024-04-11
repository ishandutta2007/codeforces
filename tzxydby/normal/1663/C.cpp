#include<bits/stdc++.h>
using namespace std;
int n,s,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s+=x;
	}
	printf("%d\n",s);
	return 0;
}