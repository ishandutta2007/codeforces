#include<cstdio>
#include<algorithm>

using namespace std;

int a[4040];
int N;

int main()
{
	scanf("%d",&N);
	int sum=0,cnt=0;
	for(int i=0;i<N*2;i++)
	{
		int x,y;
		scanf("%d.%d",&x,&y);
		a[i]=y;
		sum+=a[i];
		if(y==0) cnt++;
	}
	int ans=1<<29;
	for(int i=max(0,N-cnt);i<=N;i++)
	{
		int tmp=sum-1000*i;
		if(tmp<0) tmp*=-1;
		ans=min(ans,tmp);
	}
	printf("%.3f\n",(double)ans/1000);
	return 0;
}