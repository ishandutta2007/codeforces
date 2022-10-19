#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a;
int b[N],p[N];
bool check(int x)
{
	int aa=a;
	for(int i=1;i<=x;i++)
	{
		if(b[i]<p[x-i+1])
			aa-=p[x-i+1]-b[i];	
		if(aa<0)
			break;
	}
	if(aa<0)
		return false;
	else
		return true;
}
int main()
{
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	sort(p+1,p+m+1);
	int lb=-1,ub=min(n,m)+1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(check(mid))
			lb=mid;
		else
			ub=mid;
	}
	ub--;
	int sum=0;
	for(int i=1;i<=ub;i++)	
		sum+=p[i];
	printf("%d %d\n",ub,max(sum-a,0));
	return 0;
}