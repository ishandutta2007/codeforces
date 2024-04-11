#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int a[100100];

int exi[25][100100];
int m[25];

bool ok[1048576];

P tmp[25];

int main()
{
	int N;
	scanf("%d",&N);
	memset(m,0,sizeof(m));
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		for(int j=0;j<25;j++)
		{
			if((a[i]>>j)%2==1)
			{
				exi[j][m[j]]=i;
				m[j]++;
			}
		}
	}
	memset(ok,false,sizeof(ok));
	for(int st=0;st<N;st++)
	{
		for(int j=0;j<25;j++)
		{
			int l=lower_bound(exi[j],exi[j]+m[j],st)-exi[j];
			if(l==m[j]) tmp[j]=P(1<<30,j);
			else tmp[j]=P(exi[j][l],j);
		}
		sort(tmp,tmp+25);
		ok[a[st]]=true;
		int val=a[st];
		for(int i=0;i<25;i++)
		{
			if(tmp[i].first==st) continue;
			if(tmp[i].first==1<<30) break;
			val|=(1<<tmp[i].second);
			if(i!=24&&tmp[i].first==tmp[i+1].first) continue;
			ok[val]=true;
		}
	}
	int ans=0;
	for(int i=0;i<1048576;i++) if(ok[i]) ans++;
	printf("%d\n",ans);
	return 0;
}