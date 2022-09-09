#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
struct Tree
{
	int value;
	vector<int> child;
} d[100000];
int blue[10000005],red[10000005];
bool marked[100000];
int xor=0,cnt=0;
void dfs(int cur)
{
	
	vector<int>::iterator it;
	for(it=d[cur].child.begin();it!=d[cur].child.end();it++)
	{
		dfs(*it);
	}
	if(d[cur].child.size()==0 || !marked[d[cur].child[0]])
		marked[cur]=true;
	if(marked[cur])
	{
		xor^=d[cur].value;
		blue[d[cur].value]++;
		cnt++;
	}
	else red[d[cur].value]++;
}
int main()
{
	int n,i,v,maxV=0,j;
	//scanf("%i",&n);
	cin >> n;
	for(i=0;i<n;i++)
	{
		//scanf("%i",&d[i].value);
		cin >> d[i].value;
		if(maxV<d[i].value) maxV=d[i].value;
	}
	for(i=1;i<n;i++)
	{
		//scanf("%i",&v);
		cin >> v;
		v--;
		d[v].child.push_back(i);
	}
	dfs(0);
	long long solution=0;
	if(xor==0)
	{
		for(i=0;i<=maxV;i++)
		{
			solution+=1ll*blue[i]*red[i];
		}
		long long x=cnt, y=n-cnt;
		solution+=1ll*x*(x-1)/2+1ll*(y)*(y-1)/2;
		//printf("1\n");
	}
	else
	{
		//for(i=0;i<=maxV;i++) printf("%i ",blue[i]);
		//printf("\n");
		//for(i=0;i<=maxV;i++) printf("%i ",red[i]);
		//printf("\n");
		for(i=0;i<=maxV;i++)
		{
			j=xor^i;
			if(j<=maxV)
			{
				solution+=1ll*blue[i]*red[j];
			}
		}
		//printf("2\n");
	}
	//printf("%lld",solution);
	cout << solution;
	return 0;
}