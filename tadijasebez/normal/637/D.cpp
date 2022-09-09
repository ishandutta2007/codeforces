#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
int x[N],pre,p[N];
int main()
{
	int n,m,s,d,i;
	scanf("%i %i %i %i",&n,&m,&s,&d);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	sort(x+1,x+1+n);
	pre=n;
	x[0]=-1;
	for(i=n-1;i>=0;i--)
	{
		if(x[i+1]-x[i]>=s+2 && x[pre]-x[i+1]<=d-2)
			p[i]=pre,pre=i;
	}
	if(pre>0) return printf("IMPOSSIBLE\n"),0;
	for(i=0;i<n;i=p[i])
		printf("RUN %i\nJUMP %i\n",x[i+1]-x[i]-2,x[p[i]]-x[i+1]+2);
	if(x[n]+1<m) printf("RUN %i\n",m-x[n]-1);
	return 0;
}