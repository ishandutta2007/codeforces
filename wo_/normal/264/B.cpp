#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int factor[100100];

int best[100100];

int a[100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	memset(factor,-1,sizeof(factor));
	for(int d=2;d<=100050;d++)
	{
		if(factor[d]!=-1) continue;
		factor[d]=d;
		for(int i=2;d*i<=100050;i++)
		{
			factor[d*i]=d;
		}
	}
	memset(best,0,sizeof(best));
	for(int i=0;i<N;i++)
	{
		if(a[i]==1) continue;
		vector<int> tmp;
		int aa=a[i];
		while(aa!=1)
		{
			int pr=factor[aa];
			tmp.push_back(pr);
			while(aa%pr==0)
			{
				aa/=pr;
			}
		}
		int prev=0;
		for(int j=0;j<tmp.size();j++)
		{
			prev=max(prev,best[tmp[j]]);
		}
		for(int j=0;j<tmp.size();j++)
		{
			best[tmp[j]]=prev+1;
		}
	}
	int ans=1;
	for(int i=0;i<100050;i++)
	{
		ans=max(ans,best[i]);
	}
	printf("%d\n",ans);
	return 0;
}