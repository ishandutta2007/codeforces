#include<cstdio>
#include<algorithm>

using namespace std;

int memory[33],data[33];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=0;j<=30;j++)
		{
			if(((a>>j)&1)==1)
			{
				memory[j]++;
			}
		}
	}
	for(int i=0;i<M;i++)
	{
		int a;
		scanf("%d",&a);
		data[a]++;
	}
	int ans=0;
	for(int i=0;i<=30;i++)
	{
		for(int j=i;j<=30;j++)
		{
			int can_in=min((long long)data[i],(long long)memory[j]*(1<<(j-i)));
			ans+=can_in;
			data[i]-=can_in;
			int tmp=can_in/(1<<(j-i));
			memory[j]-=tmp;
			int x=can_in-(1<<(j-i))*tmp;
			int rem=(1<<j)-x*(1<<i);
			memory[j]--;
			for(int k=0;k<=30;k++) if(((rem>>k)&1)==1) memory[k]++;
			if(data[i]==0) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}