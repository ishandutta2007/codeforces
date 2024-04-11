#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y;
int b[100020],c[100020];
vector<int>a[100020];
set<int>s,z;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=1;i<=n;i++)
		if(b[i]==c[i])
			s.insert(i);
	while(s.size())
	{
		int u=*s.begin();
		z.insert(u);
		s.erase(u);
		fe(i,a[u])
		{
			c[*i]++;
			if(b[*i]==c[*i])
				s.insert(*i);
			if(b[*i]!=c[*i])
				s.erase(*i);
		}
	}
	cout<<z.size()<<endl;
	fe(i,z)
		cout<<*i<<' ';
	return 0;
}