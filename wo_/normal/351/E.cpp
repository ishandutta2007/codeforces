#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int p[2020];
int vals[2020];
int vln;
int cp[2020];

int ma[2020];
int sum[2020];

vector<int> vec;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",p+i);
		if(p[i]<0) p[i]*=-1;
		vals[i]=p[i];
	}
	sort(vals,vals+N);
	vln=unique(vals,vals+N)-vals;
	for(int i=0;i<N;i++) cp[i]=lower_bound(vals,vals+vln,p[i])-vals;
	int ans=0;
	for(int v=vln-1;v>=0;v--)
	{
		for(int i=0;i<2020;i++)
		{
			ma[i]=0;
			sum[i]=0;
		}
		vec.clear();
		int all=0;
		for(int i=0;i<N;i++)
		{
			if(cp[i]==v) vec.push_back(i);
			else if(cp[i]<v)
			{
				ma[i]=1;
				all++;
			}
		}
		sum[0]=ma[0];
		for(int i=1;i<N;i++) sum[i]=sum[i-1]+ma[i];
		for(int i=0;i<vec.size();i++)
		{
			int tmp=sum[vec[i]];
			if(tmp>all-tmp) tmp=all-tmp;
			ans+=tmp;
		}
	}
	printf("%d\n",ans);
	return 0;
}