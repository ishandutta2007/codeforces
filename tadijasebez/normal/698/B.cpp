#include <stdio.h>
const int N=200050;
int time,pa[N],a[N],sol,root;
void Find(int x)
{
	pa[x]=++time;
	while(!pa[a[x]]) x=a[x],pa[x]=time;
	if(pa[a[x]]==time)
	{
		if(root==0) root=x;
		if(a[x]!=root) a[x]=root,sol++;
	}
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) if(a[i]==i) root=i;
	for(i=1;i<=n;i++) if(!pa[i]) Find(i);
	printf("%i\n",sol);
	for(i=1;i<=n;i++) printf("%i ",a[i]);
}