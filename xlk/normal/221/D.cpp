#include<stdio.h>
#include<map>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<int,int>g;
int n,m;
int x[100020],y[100020],z[100020],a[100020],s[100020];
int main()
{
	scanf("%d %d",&n,&m);
	fo(i,n)
		scanf("%d",a+i),g[a[i]]++;
	fr(i,m)
		scanf("%d %d",x+i,y+i);
	fe(i,g)
	{
		if(i->X>i->Y)
			continue;
		fo(j,n)
			if(a[j]==i->X)
				s[j]=s[j-1]+1;
			else
				s[j]=s[j-1];
		fr(j,m)
			if(s[y[j]]-s[x[j]-1]==i->X)
				z[j]++;
	}
	fr(i,m)
		printf("%d\n",z[i]);
	return 0;
}