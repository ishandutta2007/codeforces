#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		if(l*2>=r+1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}