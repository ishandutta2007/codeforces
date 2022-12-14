#include<cstdio>
#include<vector>

using namespace std;

int a[1010][1010];

bool exi[1010][1010];

vector<int> js[1010];

int H,W;

bool check(int x)
{
	for(int i=0;i<H;i++) js[i].clear();
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++) if(a[i][j]>=x) js[i].push_back(j);
	}
	for(int i=0;i<W;i++) for(int j=0;j<W;j++) exi[i][j]=false;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<js[i].size();j++) for(int k=j+1;k<js[i].size();k++)
		{
			int l=js[i][j],r=js[i][k];
			if(exi[l][r]==true) return true;
			exi[l][r]=true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&H,&W);
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++) scanf("%d",&a[i][j]);
	}
	int lb=0,ub=1100100100;
	while(ub-lb>1)
	{
		int mid=(ub+lb)/2;
		if(check(mid)==true) lb=mid;
		else ub=mid;
	}
	printf("%d\n",lb);
	return 0;
}