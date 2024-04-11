#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,type[100005],a[100005],to[100005],len[100005],ans,city[100005],top;
bool flag[100005];
int dfs(int x)
{
	if(x==0)return 0;
	if(len[x])return len[x];
	if(a[x]==0)return len[x]=1;
	if(type[a[x]]==1||flag[a[x]]==1)return len[x]=1;
	return len[x]=dfs(a[x])+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&type[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(to[a[i]])flag[a[i]]=1,to[a[i]]=0;
		if(flag[a[i]])a[i]=0;
		if(a[i]==0)continue;
		to[a[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//	  printf("%d ",a[i]);
//	printf("\n");
	for(int i=1;i<=n;i++)
	  if(type[i]&&dfs(i)>len[ans])
	    ans=i;
	printf("%d\n",len[ans]);
	city[++top]=ans;
	while(a[ans]&&type[a[ans]]==0&&flag[a[ans]]==0)
	  city[++top]=ans=a[ans];
	for(int i=top;i>=1;i--)printf("%d ",city[i]);
	printf("\n");
	return 0;
}