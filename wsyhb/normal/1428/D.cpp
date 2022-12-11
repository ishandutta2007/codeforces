#include<bits/stdc++.h>
using namespace std;
const int buffer_size=1<<20|1;
char buf[buffer_size],*S,*T;
inline char read_char()
{
	if(S==T) T=(S=buf)+fread(buf,1,buffer_size,stdin);
	return S!=T?*(S++):EOF;
}
inline int read_int()
{
	bool flag=false;
	char c=read_char();
	while(c<'0'||c>'9')
	{
		flag=(c=='-'?true:flag);
		c=read_char();
	}
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=x*10+(c^48);
		c=read_char();
	}
	return flag?-x:x;
}
const int max_n=1e5+5;
int a[max_n];
vector<int> ones,twos,threes;
typedef pair<int,int> P;
vector<P> targets;
int main()
{
	int n=read_int();
	for(int i=1;i<=n;++i)
		a[i]=read_int();
	int now=n;
	for(int i=n;i>=1;--i)
	{
		if(a[i]==1)
			ones.push_back(i);
		if(a[i]==2)
		{
			if(ones.size()&&now)
			{
				int k=ones.back();
				ones.pop_back();
				targets.push_back(P(now,i));
				targets.push_back(P(now,k));
				--now;
			}
			else
			{
				printf("-1");
				return 0;
			}
			twos.push_back(i);
		}
		if(a[i]==3)
		{
			if(threes.size()&&now)
			{
				int k=threes.back();
				threes.pop_back();
				targets.push_back(P(now,i));
				targets.push_back(P(now,k));
				--now;
			}
			else if(twos.size()&&now)
			{
				int k=twos.back();
				twos.pop_back();
				targets.push_back(P(now,i));
				targets.push_back(P(now,k));
				--now;
			}
			else if(ones.size()&&now>1)
			{
				int k=ones.back();
				ones.pop_back();
				targets.push_back(P(now-1,i));
				targets.push_back(P(now-1,k));
				targets.push_back(P(now,k));
				now-=2; 
			}
			else
			{
				printf("-1");
				return 0;
			}
			threes.push_back(i);
		}
	}
	while(ones.size())
	{
		if(now)
		{
			targets.push_back(P(now--,ones.back()));
			ones.pop_back();
		}	
		else
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d\n",targets.size());
	for(int i=0;i<targets.size();++i)
		printf("%d %d\n",targets[i].first,targets[i].second);
	return 0;
}