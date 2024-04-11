#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,num[15];
char c[15];
bool flag[15];
int main()
{
	scanf("%d",&n);
	memset(num,0x7f,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		scanf("%s",c);
		if(strlen(c)==1)
		{
			if(c[0]=='A')num[1]=min(num[1],v);
			if(c[0]=='B')num[2]=min(num[2],v);
			if(c[0]=='C')num[3]=min(num[3],v);
		}
		else if(strlen(c)==2)
		{
			flag[1]=flag[2]=flag[3]=0;
			flag[c[0]-'A'+1]=1;
			flag[c[1]-'A'+1]=1;
			if(flag[1]&&flag[2])num[4]=min(num[4],v);
			if(flag[1]&&flag[3])num[5]=min(num[5],v);
			if(flag[2]&&flag[3])num[6]=min(num[6],v);
		}
		else if(strlen(c)==3)num[7]=min(num[7],v);
	}
	ll ans=1000000000000;
	ans=min(ans,(ll)num[1]+num[2]+min(min(num[3],num[5]),min(num[6],num[7])));
	ans=min(ans,(ll)num[1]+num[3]+min(min(num[2],num[4]),min(num[6],num[7])));
	ans=min(ans,(ll)num[2]+num[3]+min(min(num[1],num[4]),min(num[5],num[7])));
	ans=min(ans,(ll)num[7]);
	ans=min(ans,(ll)num[1]+num[6]);
	ans=min(ans,(ll)num[2]+num[5]);
	ans=min(ans,(ll)num[3]+num[4]);
	ans=min(ans,(ll)num[4]+num[5]);
	ans=min(ans,(ll)num[4]+num[6]);
	ans=min(ans,(ll)num[5]+num[6]);
	if(ans>10000000)printf("-1\n");
	else printf("%I64d\n",ans);
	return 0;
}