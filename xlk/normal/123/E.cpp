#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int n,sx,sy;
int x[100020];
int y[100020];
int s[100020];
double z;
int F(int w,int v)
{
	s[w]=1;
	fe(i,a[w])
		if(*i!=v)
		{
			F(*i,w);
			z+=(double)y[w]*x[*i]*s[*i];
			x[w]+=x[*i];
			s[w]+=s[*i];
		}
	z+=(double)y[w]*(sx-x[w])*(n-s[w]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d %d",x+i,y+i),sx+=x[i],sy+=y[i];
	F(1,0);
	printf("%.20f",z/sx/sy);
	return 0;
}