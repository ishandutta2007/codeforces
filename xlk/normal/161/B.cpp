#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int x,y,i,j;
int ac,bc;
ii a[100020];
ii b[100020];
double ans;
int n,m;
vector<ii>pack[1020];
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if(y==1)
			a[ac++]=ii(x,i+1);
		else
			b[bc++]=ii(x,i+1);
	}
	sort(a,a+ac,greater<ii>());
	sort(b,b+bc,greater<ii>());
	if(ac>=m)
	{
		for(i=0;i<m-1;i++)
		{
			ans+=a[i].X/2.0;
			pack[i].push_back(a[i]);
		}
		for(i=m-1;i<ac;i++)
			b[bc++]=a[i];
		sort(b,b+bc);
		ans+=b[0].X/2.0;
		pack[m-1].push_back(b[0]);
		for(i=1;i<bc;i++)
		{
			ans+=b[i].X;
			pack[m-1].push_back(b[i]);
		}
	}
	else
	{
		for(i=0;i<ac;i++)
		{	
			ans+=a[i].X/2.0;
			pack[i].push_back(a[i]);
		}
		for(i=0;i<bc;i++)
		{
			pack[min(ac+i,m-1)].push_back(b[i]);
			ans+=b[i].X;
		}
	}
	printf("%.1lf\n",ans);
	for(i=0;i<m;i++)
	{
		printf("%d ",pack[i].size());
		for(j=0;j<pack[i].size();j++)
			printf("%d ",pack[i][j].Y);
		puts("");
	}
	return 0;
}