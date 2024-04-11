#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Data
{
	int val;
	int i,j;
}x[600005];
int a[15],b[100005],pos[100005][6],n;
bool cmp(Data a,Data b)
{
	return a.val<b.val;
}
int main()
{
	for(int i=1;i<=6;i++)scanf("%d",&a[i]);
	sort(a+1,a+7);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=6;j++)
	    x[(i-1)*6+j].val=b[i]-a[j],x[(i-1)*6+j].i=i,x[(i-1)*6+j].j=j;
	sort(x+1,x+6*n+1,cmp);
	for(int i=1;i<=6*n;i++)
		pos[x[i].i][x[i].j]=i;
	int maxv=0;
	for(int i=1;i<=n;i++)maxv=max(maxv,b[i]-a[6]);
	int minv=b[1]-a[6];
	int ans=maxv-minv;
	for(int i=1;i<=6*n;i++)
	{
		if(x[i].j==1)break;
		maxv=max(maxv,b[x[i].i]-a[x[i].j-1]);
		minv=x[i+1].val;
		ans=min(ans,maxv-minv);
	}
	printf("%d\n",ans);
	return 0;
}