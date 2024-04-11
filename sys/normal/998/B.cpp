#include <bits/stdc++.h>
using namespace std;
int ct,ji,ou,n,m,a[105],cut[105],cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(a[i]%2) ji++;
		else ou++;
		if(ji==ou) cut[++cnt]=abs(a[i+1]-a[i]);
	}
	sort(cut+1,cut+1+cnt);
	if(cnt==0){printf("0");return 0;}
	for(int i=1;i<=cnt;i++)
	{
		m-=cut[i];
		if(m<0){printf("%d",ct);return 0;}
		ct++;
	}
	printf("%d",cnt);
	return 0;
}