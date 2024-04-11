#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int nums[1100];

int fro[1100],ba[1100];
int sz[1100];
int head[1100];

int smart;

vector<int> already;
vector<int> created;
vector<int> tmp;

void sweep(int st)
{
	int id=st;
	int total=0;
	while(id!=-1)
	{
		total++;
		sz[id]=total;
		head[id]=st;
		id=fro[id];
	}
}

int main()
{
	for(int i=0;i<1100;i++)
	{
		fro[i]=-1;ba[i]=-1;sz[i]=-1;
	}
	int N;
	scanf("%d%d",&N,&smart);
	smart--;
	for(int i=0;i<N;i++)
	{
		scanf("%d",fro+i);
		fro[i]--;
		if(fro[i]!=-1) ba[fro[i]]=i;
	}
	for(int i=0;i<N;i++)
	{
		if(ba[i]==-1) sweep(i);
	}
	
	int sm_sz=sz[smart];
	int sm_total=0;
	for(int i=0;i<N;i++)
	{
		if(head[i]==head[smart]&&fro[i]==-1)
		{
			sm_total=sz[i];
		}
	}
	int in_group=sm_total-sm_sz+1;
	
	for(int i=0;i<N;i++)
	{
		if(fro[i]==-1)
		{
			nums[sz[i]]++;
		}
	}
	nums[sm_total]--;
	already.push_back(0);
	for(int i=1;i<=N;i++)
	{
		if(nums[i]==0) continue;
		for(int j=0;j<=nums[i];j++)
		{
			created.push_back(i*j);
	//		printf("cr%d\n",i*j);
		}
		for(int j=0;j<already.size();j++) for(int k=0;k<created.size();k++)
		{
			tmp.push_back(already[j]+created[k]);
		}
		sort(tmp.begin(),tmp.end());
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
		created.clear();
		already=tmp;
		tmp.clear();
	//	printf("%d end::",i);
	//	for(int j=0;j<already.size();j++) printf("%d ",already[j]);
	//	printf("\n");
	}
	sort(already.begin(),already.end());
	already.erase(unique(already.begin(),already.end()),already.end());
	for(int i=0;i<already.size();i++)
	{
		printf("%d\n",already[i]+in_group);
	}
//	printf("in%d\n",in_group);
//	for(int i=0;i<=N;i++) printf("%d ",nums[i]);
//	printf("\n");
	return 0;
}