#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n,m;
int l[200010],g[110][110],used[2010],ans[200010];
vector<int> a[200010],con[2010];
vector<pair<int,int> > b[200010];

int gcd(int x,int y)
{return y==0?x:gcd(y,x%y);
}

void insert(int x,int y)
{int p,i;
 
 p=x*41+y;
 for(i=0;i<con[p].size();i++) used[con[p][i]]++;
}

void del(int x,int y)
{int p,i;
 
 p=x*41+y;
 for(i=0;i<con[p].size();i++) used[con[p][i]]--;
}

int main()
{int i,j,i1,j1,p,last,k,now,x,y;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=40;i++)
 	for(j=1;j<=40;j++)
 		g[i][j]=gcd(i,j);
 for(i=1;i<=40;i++)
 	for(j=0;j<i;j++)
 		for(i1=1;i1<=40;i1++)
 			for(j1=0;j1<i1;j1++)
 			{	x=i*41+j;
 				y=i1*41+j1;
 				if(((j1-j+i1)%i1)%g[i][i1]!=0) con[x].push_back(y);
 			}			
 for(i=1;i<=n;i++)
 {	scanf("%d",&l[i]);
 	for(j=1;j<=l[i];j++) 
 	{	scanf("%d",&x);
 		a[i].push_back(x);
 		b[x].push_back(make_pair(i,j-1));
 	}
 }
 for(i=1;i<=m;i++)
 {	for(j=0;j<b[i].size();j=last+1)
 	{	last=j;
 		while(last+1<b[i].size() && b[i][last+1].first==b[i][last].first+1) last++;
 		if(last-j+1>ans[i])
 		{	p=j;
	 		now=p-1;	
		 	for(k=j;k<=last;k++)
	 		{	while(p<=now && used[l[b[i][k].first]*41+b[i][k].second])
 				{	del(l[b[i][p].first],b[i][p].second);
 					p++;
 				}
 				now++;
 				insert(l[b[i][k].first],b[i][k].second);
 				ans[i]=max(ans[i],now-p+1);
 			}
 			while(p<=now)
 			{	del(l[b[i][p].first],b[i][p].second);
	 			p++;
 			}
 		}
 	}
 }
 for(i=1;i<=m;i++)
 	printf("%d\n",ans[i]);
 return 0;
}