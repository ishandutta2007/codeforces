#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n,nq,m,mt,tot,ans;
int a[300010],head[300010];
vector<int> b[300010];

int main()
{int i,j,x,k,opt;
 
 scanf("%d%d",&n,&nq);
 for(i=1;i<=nq;i++)
 {	scanf("%d",&opt);
 	if(opt==1)
 	{	scanf("%d",&x);
	 	a[++tot]=x;
	 	b[x].push_back(tot);
	 	ans++;
	}
	else if(opt==2)
	{	scanf("%d",&x);
		ans-=b[x].size()-1-head[x]+1;
		head[x]=b[x].size();
	}
	else if(opt==3)
	{	scanf("%d",&m);
		if(m>mt)
		{	while(mt<m)
			{	mt++;
				k=a[mt];
				if(head[k]<b[k].size() && b[k][head[k]]==mt)
				{	head[k]++;
					ans--;
				}
			}
		}
	}
	printf("%d\n",ans);
 }
 return 0;
}