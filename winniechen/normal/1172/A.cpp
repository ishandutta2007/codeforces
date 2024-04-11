#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int a[N],b[N],n,pos[N],ans;
bool check()
{
	if(!pos[1])return 0;
	for(int i=pos[1];i<n;i++)if(b[i]!=b[i+1]-1)return 0;
	int len=n-pos[1]+1;
	for(int i=len+1;i<=n;i++)if(pos[i]>=i-len)return 0;
	printf("%d\n",pos[1]-1);return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),pos[b[i]]=i;
	if(check())return 0;ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,n+pos[i]-i+1);
	printf("%d\n",ans);
}