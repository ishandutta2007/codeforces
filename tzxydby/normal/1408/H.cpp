#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],l[N],r[N],p[N],v[N],t,m,k,ans;
struct node
{
	int x,y;
	node(){}
	node(int _x,int _y):x(_x),y(_y){}
	bool operator<(const node k)const
	{
		return x==k.x?y<k.y:x<k.x;
	}
};
set<node>s;
void sol()
{
	scanf("%d",&n);
	t=ans=k=0;
	s.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=v[i]=0;
		if(!a[i])
		{
			t++;
			p[t]=i;
		}
	}
	m=p[(t+1)/2];
	for(int i=1;i<m;i++)
		if(a[i]>0)
			l[a[i]]=i;
	for(int i=m+1;i<=n;i++)
	{
		if(!a[i])
		{
			if(s.size())
			{
				v[s.begin()->y]=1;
				ans++;
				s.erase(s.begin());
			}
		}
		else
		{
			if(!v[a[i]])
				s.insert({l[a[i]],a[i]});
		}
	}
	for(int i=m-1;i>=1;i--)
	{
		if(!a[i])
		{
			if(k)
				k--,ans++;
		}
		else
		{	
			if(!v[a[i]])
				k++,v[a[i]]=1;
		}
	}
	printf("%d\n",min(ans,t/2));
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		sol();
	return 0;
}