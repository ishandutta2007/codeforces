#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int factor[100100];
bool on[100100];
int exist[100100];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(factor,-1,sizeof(factor));
	for(int i=2;i<=n;i++)
	{
		if(factor[i]==-1)
		{
			for(int j=1;i*j<=n;j++)
			{
				factor[i*j]=i;
			}
		}
	}
	memset(on,false,sizeof(on));
	memset(exist,-1,sizeof(exist));
	for(int i=0;i<m;i++)
	{
		char s[2];
		int t;
		scanf("%s%d",s,&t);
		if(s[0]=='+')
		{
			if(on[t])
			{
				puts("Already on");
				continue;
			}
			bool ok=true;
			vector<int> f;
			int req=t;
			while(t!=1)
			{
				if(exist[factor[t]]!=-1)
				{
					printf("Conflict with %d\n",exist[factor[t]]);
					ok=false;
					break;
				}
				int div=factor[t];
				while(t%div==0) t/=div;
				f.push_back(div);
			}
			if(ok)
			{
				puts("Success");
				on[req]=true;
				for(int j=0;j<f.size();j++)
				{
					exist[f[j]]=req;
				}
			}
		}
		else
		{
			if(!on[t])
			{
				puts("Already off");
				continue;
			}
			int req=t;
			puts("Success");
			on[t]=false;
			while(t!=1)
			{
				int div=factor[t];
				exist[factor[t]]=-1;
				while(t%div==0)
				{
					t/=div;
				}
			}
		}
	}
	return 0;
}