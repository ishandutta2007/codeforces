#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
multiset<int>se;
int a[200005];
int main()
{
	int t,n,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		se.clear();
		for(int i=1;i<=n;i++)a[i]=read(),se.insert(a[i]);
		for(int i=1;i<=n;i++)
		{
			multiset<int>::iterator it=se.upper_bound(a[i]);
			if(it==se.end())it=se.begin();
			printf("%d ",(*it));
			se.erase(it);
		}
		printf("\n");
	}
	return 0;
}