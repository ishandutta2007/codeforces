#include <stdio.h>
const int N=10050;
bool vis[N<<1];
int main()
{
	int n,m,k,i,j,u;
	scanf("%i %i",&n,&m);
	bool sol=false;
	for(i=0;i<m;i++)
	{
		for(j=0;j<N<<1;j++) vis[j]=0;
		bool ok=false;
		scanf("%i",&k);
		for(j=0;j<k;j++)
		{
			scanf("%i",&u);
			vis[u+N]=true;
			if(vis[N-u]) ok=true;
		}
		//for(j=0;j<N;j++)
		//{
		//	if(vis[N-j]!=vis[N+j]) ok=true;
		//}
		if(!ok) sol=true;
	}
	if(sol) printf("YES\n");
	else printf("NO\n");
	return 0;
}