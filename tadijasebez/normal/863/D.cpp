#include <stdio.h>
#include <vector>
const int N=200050;
int a[N],l[N],r[N],t[N];
std::vector<int> out;
int main()
{
	int n,q,m,i,x;
	scanf("%i %i %i",&n,&q,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=q;i++) scanf("%i %i %i",&t[i],&l[i],&r[i]);
	while(m--)
	{
		scanf("%i",&x);
		for(i=q;i;i--) if(x>=l[i] && x<=r[i])
		{
			if(t[i]==2) x=l[i]+r[i]-x;
			else x=x==l[i]?r[i]:x-1;
		}
		out.push_back(x);
	}
	for(i=0;i<out.size();i++) printf("%i ",a[out[i]]);
	printf("\n");
	return 0;
}