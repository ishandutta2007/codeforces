#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[100050];
vector<int> index;
int FindIndex(int x)
{
	int top=index.size()-1;
	int bot=0;
	int mid;
	while(top>bot)
	{
		mid=(top+bot)>>1;
		if(index[mid]<x) bot=mid+1;
		else top=mid;
	}
	return top;
}
int FenwickTree[100050];
void Set(int x, int n)
{
	for(x;x<=n;x+=(x&-x))
		FenwickTree[x]++;
}
int Get(int x)
{
	int res=0;
	for(x;x>0;x-=(x&-x))
		res+=FenwickTree[x];
	return res;
}
int b[100050];
bool ok[100050];
vector<int> ret[100050];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]),index.push_back(a[i]);
	sort(index.begin(),index.end());
	for(i=0;i<n;i++) a[i]=FindIndex(a[i])+1,b[a[i]]=i+1;
	int sol=0;
	for(i=0;i<n;i++)
	{
		if(!ok[i+1])
		{
			int tmp=a[i];
			while(!ok[tmp])
			{
				ok[tmp]=true;
				ret[sol].push_back(tmp);
				tmp=b[tmp];
			}
			sol++;
		}
		//Set(a[i],n);
		//if(Get(i+1)==i+1) sol++;
	}
	printf("%i\n",sol);
	for(i=0;i<sol;i++)
	{
		printf("%i ",ret[i].size());
		for(j=0;j<ret[i].size();j++)
		{
			printf("%i ",b[ret[i][j]]);
		}
		printf("\n");
	}
	return 0;
}