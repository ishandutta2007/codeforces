#include <bits/stdc++.h>
using namespace std;
int n,ans[1005][1005];
void work(int k,int now)
{
	if(!k) return ;
	int tmp=1;
	while((tmp<<1)<=k) tmp<<=1;
	for(int i=1;i<=n;i++)
		for(int j=n-k+1;j<=n-k+1+tmp;j++)
			ans[i][j]=now+(i-1)*tmp+j-(n-k+1);
	work(k-tmp,now+n*tmp);
}
int main()
{
	scanf("%d",&n);
	work(n,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}