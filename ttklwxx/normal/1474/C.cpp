#include<cstdio>
#include<algorithm>
#include<vector>
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
int t,n;
int a[114514];
int main()
{
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=2*n;i++)a[i]=read();
		sort(a+1,a+2*n+1);
		bool fn=false;
		for(int i=1;i<2*n;i++)
		{
			multiset<int>se(a+1,a+2*n+1);
			vector<pair<int,int> >ans;
			ans.reserve(n);
			int t=a[2*n]+a[i];
			int sth=t;
			while(!se.empty())
			{
				auto it=se.end();
				it--;
				int x=*it;
				se.erase(it);
				int y=t-x;
				it=se.find(y);
				if(it==se.end())break;
				se.erase(it);
				ans.push_back(make_pair(y,x));
				t=x;
			}
			if(se.empty())
			{
				printf("YES\n");
				printf("%d\n",sth);
				for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
				fn=true;
				break;
			}
		}
		if(!fn)printf("NO\n");
	}
}