#include<bits/stdc++.h>
using namespace std;

int n,q,pos[110];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i <=50; i++) pos[i]=-1;
	int x;
	for (int i=1; i<=n; i++) 
	{
	scanf("%d",&x);
	if (pos[x]==-1) pos[x]=i;}
	while (q--)
	{
		scanf("%d",&x);
		printf("%d ",pos[x]);
		for (int i=1; i<=50; i++) if (pos[i]<pos[x]) pos[i]++;
		pos[x]=1;
	} 
	return 0;
}