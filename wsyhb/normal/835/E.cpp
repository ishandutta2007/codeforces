#include<bits/stdc++.h>
using namespace std;
int n,x,y,tot;
inline int query(const vector<int> &p)
{
	assert(++tot<=19);
	int c=p.size();
	assert(c>=1&&c<=n);
	printf("? %d",c);
	for(int i=0;i<c;++i)
		printf(" %d",p[i]);
	putchar('\n');
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	assert(ans!=-1);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	int highbit=0;
	while(n>=(1<<(highbit+1)))
		++highbit;
	int xor_val=0,key=-1;
	for(int k=0;k<=highbit;++k)
	{
		vector<int> p;
		for(int i=1;i<=n;++i)
		{
			if(i>>k&1)
				p.push_back(i);
		}
		int ans=query(p);
		if(ans==y||ans==(x^y))
		{
			xor_val|=1<<k;
			key=k;
		}
	}
	assert(key!=-1);
	vector<int> now;
	for(int i=1;i<=n;++i)
	{
		if(i>>key&1)
			now.push_back(i);
	}
	for(int k=0;k<=highbit;++k)
	{
		if(k==key)
			continue;
		vector<int> p,q;
		for(int i=0;i<int(now.size());++i)
		{
			int j=now[i];
			if(j>>k&1)
				p.push_back(j);
			else
				q.push_back(j);
		}
		if(p.empty()||q.empty())
			continue;
		int ans=query(p);
		if(ans==y||ans==(x^y))
			now=p;
		else
			now=q;
	}
	assert((int)now.size()==1);
	int p1=now[0],p2=p1^xor_val;
	if(p1>p2)
		swap(p1,p2);
	printf("! %d %d\n",p1,p2);
	fflush(stdout);
	return 0;
}