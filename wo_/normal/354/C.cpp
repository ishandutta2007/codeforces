#include<cstdio>
#include<functional>
#include<algorithm>

using namespace std;

int a[300300];
int N,K;
int mi=1100100;

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		mi=min(mi,a[i]);
	}
	sort(a,a+N);
	reverse(a,a+N);
	int ans=1;
	for(int x=2;x<=mi;x++)
	{
		int ma=0;
		for(int i=1;(i-1)*x<=1100100;i++)
		{
			int num=i*x;
			int id=upper_bound(a,a+N,num,greater<int>())-a;
			if(id==N) continue;
			if(a[id]<num-x) continue;
			ma=max(ma,a[id]-(num-x));
		}
		if(ma<=K) ans=x;
	}
	printf("%d\n",ans);
	return 0;
}