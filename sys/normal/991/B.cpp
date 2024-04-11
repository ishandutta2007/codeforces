#include <bits/stdc++.h>
using namespace std;
int all,n,sc[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sc[i]);
		all+=sc[i];
	}
	if(all>=n*4.5) {printf("0");return 0;}
	sort(sc+1,sc+1+n);
	for(int i=1;i<=n;i++)
	{
		all+=(5-sc[i]);
		if(all>=n*4.5){printf("%d",i);break;}
	}
	return 0;
}