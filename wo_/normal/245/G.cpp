#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int m,head[10000],nxt[10000],to[10000];

map<string,int> strs;

int tmp[10000];

int main()
{
	int M;
	cin>>M;
	int n=0;
	memset(head,-1,sizeof(head));
	for(int i=0;i<M;i++)
	{
		string a,b;
		cin>>a>>b;
		int an,bn;
		if(strs.count(a)==0)
		{
			strs[a]=n;
			n++;
		}
		if(strs.count(b)==0)
		{
			strs[b]=n;
			n++;
		}
		an=strs[a],bn=strs[b];
		nxt[m]=head[an];head[an]=m;to[m]=bn;m++;
		nxt[m]=head[bn];head[bn]=m;to[m]=an;m++;
	}
	cout<<n<<"\n";
	map<string,int>::iterator it=strs.begin();
	for(;it!=strs.end();it++)
	{
		int id=(*it).second;
		memset(tmp,0,sizeof(tmp));
		for(int e=head[id];e!=-1;e=nxt[e])
		{
			int v=to[e];
			for(int e2=head[v];e2!=-1;e2=nxt[e2])
			{
				tmp[to[e2]]++;
			}
		}
		for(int e=head[id];e!=-1;e=nxt[e])
		{
			tmp[to[e]]=-1;
		}
		tmp[id]=-1;
		int cnt=0;
		int Ma=0;
		for(int i=0;i<n;i++)
		{
			Ma=max(Ma,tmp[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(tmp[i]==Ma) cnt++;
		}
		cout<<(*it).first<<" "<<cnt<<"\n";
	}
	return 0;
}