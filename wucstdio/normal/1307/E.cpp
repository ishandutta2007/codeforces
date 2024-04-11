#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m,type[5005],cnt1[5005],cnt2[5005];
vector<int>h[5005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&type[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		h[x].push_back(y);
	}
	for(int i=1;i<=n;i++)sort(h[i].begin(),h[i].end());
	ll ans=0;
	int maxx=0;
	for(int i=0;i<=n;i++)
	{
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int x=1;x<=i;x++)cnt1[type[x]]++;
		for(int y=i+1;y<=n;y++)cnt2[type[y]]++;
		bool flag=0;
		for(auto x:h[type[i]])
		{
			if(x==cnt1[type[i]])
			{
				flag=1;
				break;
			}
		}
		if(i==0)flag=1;
		if(!flag)continue;
		ll sum=1;
		int cc=i==0?0:1;
		for(int c=1;c<=n;c++)
		{
			int num=(int)h[c].size();
			int x=0,y=0;
			while(x<num&&h[c][x]<=cnt1[c])x++;
			while(y<num&&h[c][y]<=cnt2[c])y++;
			if(c==type[i])
			{
				x=0;
				if(cnt2[c]>=cnt1[c])y--;
			}
			if(x>y)swap(x,y);
			if(x==0&&y==0)continue;
			else if(x==0)sum=sum*y%MOD,cc++;
			else if(y!=1)sum=sum*x*(y-1)%MOD,cc+=2;
			else sum=sum*2%MOD,cc++;
		}
//		printf("p=%d,%lld,%d\n",i,sum,cc);
		if(cc>maxx)maxx=cc,ans=sum;
		else if(cc==maxx)ans=(ans+sum)%MOD;
	}
	printf("%d %lld\n",maxx,ans);
	return 0;
}