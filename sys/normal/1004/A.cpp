#include <bits/stdc++.h>
using namespace std;
int n,p,x[105],cnt;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	sort(x+1,x+1+n); 
	for(int i=2;i<=n;i++)
	{
		if(x[i]-x[i-1]==2*p) cnt++;
		if(x[i]-x[i-1]>2*p) cnt+=2;
	}
	printf("%d",cnt+2);	
	return 0;
}