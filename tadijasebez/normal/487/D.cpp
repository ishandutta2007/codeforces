#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int H=2*N;
const int M=12;
char base[N][M];
int n,m;
struct Layer
{
	int t[M],x[M],y[M];
	Layer(){}
	void Build(int id)
	{
		for(int i=1;i<=m;i++)
		{
			vector<bool> was(M,0);
			int j=i;t[i]=0;
			while(!was[j])
			{
				was[j]=1;
				if(base[id][j]=='^')
				{
					t[i]=1;
					x[i]=j;
					break;
				}
				if(base[id][j]=='<') j--;
				else j++;
				if(j==0 || j==m+1)
				{
					t[i]=2;
					x[i]=id;y[i]=j;
					break;
				}
			}
		}
	}
};
Layer operator + (Layer a, Layer b)
{
	Layer ans;
	for(int i=1;i<=m;i++)
	{
		if(a.t[i]==1)
		{
			ans.t[i]=b.t[a.x[i]];
			ans.x[i]=b.x[a.x[i]];
			ans.y[i]=b.y[a.x[i]];
		}
		else
		{
			ans.t[i]=a.t[i];
			ans.x[i]=a.x[i];
			ans.y[i]=a.y[i];
		}
	}
	return ans;
}
Layer node[H];
int ls[H],rs[H],root,tsz;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c].Build(ss);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Set(int c, int ss, int se, int qi)
{
	if(ss==se){ node[c].Build(ss);return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
	node[c]=node[ls[c]]+node[rs[c]];
}
Layer Get(int c, int ss, int se, int qs, int qe)
{
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	if(qe<=mid) return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid) return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int q,i,j,x,y;char t,v;
	scanf("%i %i %i",&n,&m,&q);
	for(i=n;i>=1;i--) scanf("%s",base[i]+1);
	Build(root,1,n);
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='A')
		{
			scanf("%i %i",&x,&y);
			x=n-x+1;
			Layer tmp=Get(root,1,n,x,n);
			if(tmp.t[y]==0) printf("-1 -1\n");
			else if(tmp.t[y]==1) printf("%i %i\n",0,tmp.x[y]);
			else printf("%i %i\n",n-tmp.x[y]+1,tmp.y[y]);
		}
		else
		{
			scanf("%i %i %c",&x,&y,&v);
			base[n-x+1][y]=v;
			Set(root,1,n,n-x+1);
		}
	}
	return 0;
}