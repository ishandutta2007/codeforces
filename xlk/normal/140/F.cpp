#include<stdio.h>
#include<algorithm>
#include<set>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
set<ii>s,z,v;
ii a[200020];
int n,l,c;
int main()
{
	scanf("%d %d",&n,&l);
	if(n<=l)
		return puts("-1"),0;
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].X,&a[i].Y),s.insert(a[i]);
	sort(a,a+n);
	for(int i=0;i<=l;i++)
		for(int j=0;i+j<=l;j++)
		{
			ii u(a[i].X+a[n-1-j].X,a[i].Y+a[n-1-j].Y);
			if(v.insert(u).Y)
			{
				for(int k=c=0;k<n&&c<=l;k++)
					c+=!s.count(ii(u.X-a[k].X,u.Y-a[k].Y));
				if(c<=l)
					z.insert(u);
			}
		}
	printf("%d\n",z.size());
	fe(i,z)
		printf("%.1f %.1f\n",i->X*.5,i->Y*.5);
	return 0;
}