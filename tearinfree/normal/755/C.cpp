#include <stdio.h>

int n;
int pa[10001], size[10001];
bool vis[10001];

int Find(int node)
{
	if(pa[node]==node) return pa[node];
	else return pa[node]=Find(pa[node]);
}

void Merge(int u, int v)
{
	int pu=Find(u), pv=Find(v);
	size[pu]+=size[pv];
	pa[pv]=pu;
}

int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++) {
		pa[i]=i;
		size[i]=1;
	}

	int num;
	for(int i=1;i<=n;i++) {
		scanf("%d",&num);
		if(Find(i) != Find(num)) {
			Merge(i, num);
		}
	}

	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(!vis[Find(i)]) {
			vis[Find(i)]=true;
			cnt++;
		}
	}
	printf("%d\n",cnt);


	return 0;
}