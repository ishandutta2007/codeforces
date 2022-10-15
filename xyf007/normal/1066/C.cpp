#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,id[2000001];
int main()
{
	scanf("%d\n",&n);
	int l=500000,r=500000;
	for(int i=1;i<=n;i++)
	{
		string s;
		int x;
		cin>>s>>x;
		if(i==1)
		{
			id[x]=500000;
			continue;
		}
		if(s=="L")
		{
			id[x]=--l;
		}
		if(s=="R")
		{
			id[x]=++r;
		}
		if(s=="?")
		{
			printf("%d\n",min(id[x]-l,r-id[x]));
		}
	}
	return 0;
}
//