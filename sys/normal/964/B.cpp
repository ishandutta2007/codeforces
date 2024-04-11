#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,t,tim[1005],ans;
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",tim+i);
	if(b>=c){printf("%d",n*a);return 0;}
	if(b<c)
		for(int i=1;i<=n;i++)
			ans+=a-(b-c)*(t-tim[i]);
	printf("%d",ans);
	return 0;
}