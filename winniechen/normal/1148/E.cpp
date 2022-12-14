#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
int n,s[N],t[N],cnt,ans[N*5][3],a[N],b[N],sa,sb,p[N];
void print(int x,int y,int z){if(s[y]-s[x]<z*2)puts("NO"),exit(0);ans[++cnt][0]=x,ans[cnt][1]=y,ans[cnt][2]=z;}
bool cmp(int x,int y){return s[x]<s[y];}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),p[i]=i;sort(p+1,p+n+1,cmp);sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)if(s[i]<t[i])a[++sa]=i;else if(s[i]>t[i])b[++sb]=i;
	if((sa&&!sb)||(sb&&!sa))return puts("NO"),0;
	for(int i=1,j=1;i<=sa&&j<=sb;)
	{
		int x=t[a[i]]-s[a[i]],y=s[b[j]]-t[b[j]];
		if(x<y)print(a[i],b[j],x),s[b[j]]-=x,i++;else if(x>y)print(a[i],b[j],y),s[a[i]]+=y,j++;
		else print(a[i],b[j],x),i++,j++;
		if(i>sa&&j>sb)break;
		if(i>sa||j>sb)return puts("NO"),0;
	}
	puts("YES");printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d %d\n",p[ans[i][0]],p[ans[i][1]],ans[i][2]);
}