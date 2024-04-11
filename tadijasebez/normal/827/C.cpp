#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int M=400*N;
int x[M],ls[M],rs[M],clock,root[4][11][10];
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> ReadString()
{
	vector<int> ret;
	char c;
	c=getchar();
	while(c<'A' || c>'Z') c=getchar();
	while(c>='A' && c<='Z')
	{
		if(c=='A') ret.push_back(0);
		if(c=='T') ret.push_back(1);
		if(c=='G') ret.push_back(2);
		if(c=='C') ret.push_back(3);
		c=getchar();
	}
	return ret;
}
int main()
{
	vector<int> a=ReadString();
	int n=a.size(),i,q,l,r,t,j,u,w;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=10;j++)
		{
			Set(root[a[i-1]][j][i%j],1,N,i,1);
		}
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			char c;
			scanf("%i %c",&u,&c);
			w=a[u-1];
			for(j=1;j<=10;j++)
			{
				Set(root[w][j][u%j],1,N,u,-1);
			}
			if(c=='A') w=0;
			if(c=='T') w=1;
			if(c=='G') w=2;
			if(c=='C') w=3;
			a[u-1]=w;
			for(j=1;j<=10;j++)
			{
				Set(root[w][j][u%j],1,N,u,1);
			}
		}
		else
		{
			scanf("%i %i",&l,&r);
			vector<int> tmp=ReadString();
			j=tmp.size();
			int ans=0;
			for(i=0;i<tmp.size();i++)
			{
				ans+=Get(root[tmp[i]][j][(l+i)%j],1,N,l,r);
			}
			printf("%i\n",ans);
		}
	}
	return 0;
}