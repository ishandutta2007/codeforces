#include<bits/stdc++.h>
using namespace std;
inline int query(int i,int j,int k)
{
	printf("? %d %d %d\n",i,j,k);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	if(res==-1)
		exit(0);
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		queue<int> q;
		for(int i=1;i<=n;++i)
			q.push(i);
		while((int)q.size()>=4)
		{
			int a=q.front();
			q.pop();
			int b=q.front();
			q.pop();
			int c=q.front();
			q.pop();
			int d=q.front();
			q.pop();
			int x=query(b,c,d);
			int y=query(a,c,d);
			int z=query(a,b,d);
			int w=query(a,b,c);
			int mx=max(max(x,y),max(z,w));
			if(mx!=x)
				q.push(a);
			if(mx!=y)
				q.push(b);
			if(mx!=z)
				q.push(c);
			if(mx!=w)
				q.push(d);
		}
		if((int)q.size()==3)
		{
			int a=q.front();
			q.pop();
			int b=q.front();
			q.pop();
			int c=q.front();
			q.pop();
			int d=1;
			while(d==a||d==b||d==c)
				++d;
			int x=query(b,c,d);
			int y=query(a,c,d);
			int z=query(a,b,d);
			int w=query(a,b,c);
			int mx=max(max(x,y),max(z,w));
			if(mx!=x)
				q.push(a);
			if(mx!=y)
				q.push(b);
			if(mx!=z)
				q.push(c);
			if(mx!=w)
				q.push(d);
		}
		if((int)q.size()==1)
			q.push(q.front());
		assert((int)q.size()==2);
		int a=q.front();
		q.pop();
		int b=q.front();
		q.pop();
		printf("! %d %d\n",a,b);
		fflush(stdout);
	}
	return 0;
}