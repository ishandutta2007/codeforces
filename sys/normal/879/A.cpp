#include <bits/stdc++.h>
using namespace std;
int n,d[1005],s[1005],tim;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i],&d[i]);
	tim=s[1];
	for(int i=2;i<=n;i++)
	{
		tim++;
		if(tim<s[i]) tim=s[i];
		else tim=s[i]+d[i]*ceil((tim-s[i])/(double)d[i]);
	}
	printf("%d",tim);
	return 0;
}