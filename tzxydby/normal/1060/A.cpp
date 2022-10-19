#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,s8=0;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
		if(getchar()-'0'==8)
			s8++;
	printf("%d\n",min(s8,n/11));
	return 0;
}