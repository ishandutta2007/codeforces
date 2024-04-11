#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k,x,y,c,w;
vector<int>a[1020],s;
double q[1020];
double f[1020][1020];
double z;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			scanf("%d",&y);
			a[i].push_back(-y);
			s.push_back(-y);
		}
	}
	sort(s.begin(),s.end());
	w=s[n-1];
	z=1;
	for(int i=0;i<m;i++)
	{
		sort(a[i].begin(),a[i].end());
		int t=lower_bound(a[i].begin(),a[i].end(),w)-a[i].begin();
		if(t<a[i].size()&&a[i][t]==w)
			q[c++]=(double)(t+1)/(a[i].size()-t);
		for(int j=0;j<t;j++)
			z=z*(j+1)/(a[i].size()-j);
		n-=t;
	}
	sort(q,q+c);
	f[0][0]=1;
	for(int i=0;i<c;i++)
		for(int j=0;j<=n;j++)
		{
			f[i+1][j]+=f[i][j];
			f[i+1][j+1]+=f[i][j]*q[i];
		}
	z*=f[c][n];
	for(int i=0;i<n;i++)
		z=z*(i+1)/(c-i);
	printf("%.15lf\n",z);
	return 0;
}