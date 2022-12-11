#include<bits/stdc++.h>
using namespace std;
int n,m;
double a[1000005],s[1000005];
struct Node
{
	int l,r;
	double x; 
	Node(int L=0,int R=0){l=L;r=R;x=(s[r]-s[l-1])/(r-l+1);}
	void maintain(){x=(s[r]-s[l-1])/(r-l+1);}
};
Node q[1000005];
int main()
{
	scanf("%d",&n);
	for(int x,i=1;i<=n;++i)
	{
		scanf("%d",&x);
		a[i]=x;
		s[i]=s[i-1]+x;
	}
	for(int i=1;i<=n;++i)
	{
		q[++m]=Node(i,i);
		while(m>1&&q[m].x<q[m-1].x)
		{
			q[m-1].r=q[m].r;
			m--;
			q[m].maintain();
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=q[i].l;j<=q[i].r;++j)printf("%.10f\n",q[i].x);
	}
}