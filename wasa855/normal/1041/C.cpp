#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	int id;
	bool operator < (const Node &x) const
	{
		return data<x.data;
	}
};
set<Node> s;
int a[200005];
int ans[200005];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	Node x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x.data);
		x.id=i;
		s.insert(x);
	}
	int cnt=1;
	int now=(*s.begin()).data;
	ans[(*s.begin()).id]=1;
	s.erase(*s.begin());
	for(int i=2;i<=n;i++)
	{
		Node x;
		x.data=now+k+1;
		if(s.lower_bound(x)==s.end())
		{
			cnt++;
			now=(*s.begin()).data;
			ans[(*s.begin()).id]=cnt;
			s.erase(*s.begin());
		}
		else
		{
			now=(*s.lower_bound(x)).data;
			ans[(*s.lower_bound(x)).id]=cnt;
			s.erase(s.lower_bound(x));
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}