#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,k;
int a[maxn],id[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[a[i]]=i;
	int ans=0;
	for(int i=1;i<=100;++i)if(id[i])ans++;
	if(ans<k){puts("NO");return 0;}
	puts("YES");
	ans=k;
	for(int i=1;i<=100;++i)if(id[i]&&ans)ans--,printf("%d ",id[i]);
	return 0;
}