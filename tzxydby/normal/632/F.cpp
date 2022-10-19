#include<bits/stdc++.h>
using namespace std;
const int N=2505;
int n,a[N][N],f[N];
struct node
{
	int x,y,v;
	node(){}
	node(int _x,int _y,int _v):x(_x),y(_y),v(_v){}
	bool operator<(const node k)const
	{
		return v<k.v;
	}
};
vector<node>p;
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=a[j][i])
			{
				puts("NOT MAGIC");
				return 0;
			}
			if(i==j&&a[i][j])
			{
				puts("NOT MAGIC");
				return 0;
			}
			if(i!=j)
				p.push_back(node(i,j,a[i][j]));
		}
	}
	sort(p.begin(),p.end());
	for(int i=0,j;i<p.size();i=j)
	{
		j=i;
		while(j<p.size()&&p[j].v==p[i].v)
			j++;
		for(int k=i;k<j;k++)
		{
			int x=p[k].x,y=p[k].y;
			if(fa(x)==fa(y))
			{
				puts("NOT MAGIC");
				return 0;
			}
		}
		for(int k=i;k<j;k++)
		{
			int x=p[k].x,y=p[k].y;
			x=fa(x),y=fa(y);
			f[x]=y;
		}
	}
	puts("MAGIC");
	return 0;
}