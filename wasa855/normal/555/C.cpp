#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int l,r;
	int x,y;
	bool operator < (const Node &x) const
	{
		if(l==x.l)
		{
			return r<x.r;
		}
		return l<x.l;
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	char opt;
	set<Node> s;
	s.insert((Node){0,0,1,1});
	s.insert((Node){1,n,1,1});
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %c",&x,&y,&opt);
		Node t=*(--s.lower_bound((Node){x,n+1,0,0}));
		if(t.l<=x&&x<=t.r)
		{
			s.erase(t);
			if(opt=='L')
			{
				printf("%d\n",x-t.x+1);
				s.insert((Node){t.l,x-1,t.x,y+1});
				s.insert((Node){x+1,t.r,t.x,t.y});
			}
			else
			{
				printf("%d\n",y-t.y+1);
				s.insert((Node){t.l,x-1,t.x,t.y});
				s.insert((Node){x+1,t.r,x+1,t.y});
			}
		}
		else
		{
			cout<<"0\n";
			continue;
		}
	}
	return 0;
}