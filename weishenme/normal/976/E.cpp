#include<bits/stdc++.h>
using namespace std;
typedef __int64 ll;
const int N=200005;
ll y[N],x[N],n,a,b,ans,now,f[N];
int cmp(int a,int b)
{
	return x[a]-y[a]>x[b]-y[b];
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++)scanf("%I64d%I64d",&x[i],&y[i]),f[i]=i;
	sort(f+1,f+n+1,cmp);
	if (!b)
	 {
	 	for (int i=1;i<=n;i++)ans+=y[i];
	 	printf("%I64d",ans);
	 	return 0;
	 }
	for (int i=1;i<=b;i++)now+=max(x[f[i]],y[f[i]]);
	for (int i=b+1;i<=n;i++)now+=y[f[i]];
	ans=now;
	for (int i=1;i<=b;i++)
	 {
	 	ll now1=now;
	  	if (x[f[i]]>y[f[i]])now1-=x[f[i]];
	  	else now1-=y[f[i]];
	  	now1+=x[f[i]]*(1<<a);
	  	ans=max(ans,now1);
	 }
	for (int i=b+1;i<=n;i++)
	 {
	 	ll now1=now;
	 	now1-=y[f[i]];
	 	now1+=x[f[i]]*(1<<a);
	 	if (x[f[b]]>y[f[b]])now1-=x[f[b]];
	 	else now1-=y[f[b]];
	 	now1+=y[f[b]];
	 	ans=max(ans,now1);
	 } 
	printf("%I64d",ans); 
}