#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
bool pos1[1005],pos2[1005];
int main()
{
	scanf("%d%d",&n,&m);
	memset(pos1,1,sizeof(pos1));
	memset(pos2,1,sizeof(pos2));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		pos1[x]=0;
		pos2[y]=0;
	}
	for(int i=2;i*2<=n;i++)
	  ans+=pos1[i]+pos1[n-i+1]+pos2[i]+pos2[n-i+1];
	if(n&1)ans+=pos1[n+1>>1]|pos2[n+1>>1];
	printf("%d\n",ans);
	return 0;
}