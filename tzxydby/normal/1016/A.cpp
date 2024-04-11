#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,pjy,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pjy);
		cnt+=pjy;
		printf("%d ",cnt/m);
		cnt%=m;
	}
	return 0;
}