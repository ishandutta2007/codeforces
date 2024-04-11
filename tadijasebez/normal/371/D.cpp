#include <stdio.h>
#include <set>
using namespace std;
const int N=200050;
int a[N],sol[N];
set<int> s;
int main()
{
	int n,q,i,k,x,t;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) s.insert(i);
	scanf("%i",&q);
	set<int>::iterator it;
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&k,&x);
			it=s.lower_bound(k);
			while(it!=s.end() && x>0)
			{
				k=*it;
				if(x>=a[k]-sol[k])
				{
					x-=a[k]-sol[k];
					sol[k]=a[k];
					s.erase(k);
				}
				else
				{
					sol[k]+=x;
					x=0;
				}
				it=s.upper_bound(k);
			}
		}
		if(t==2)
		{
			scanf("%i",&k);
			printf("%i\n",sol[k]);
		}
	}
	return 0;
}