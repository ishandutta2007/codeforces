#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
struct P{ll x,y;};
inline ll xm(P o, P a, P b)
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
int N,M,K;
int cnt;
P a[100010];
int main()
{
	scanf("%d",&N);
	for(int i=N;i;i--)
	scanf("%I64d%I64d",&a[i].x,&a[i].y);
	scanf("%d",&M);
	for(int i=1;i<=M;i++)
	{
		P p;
		int l=2,r=N;
		scanf("%I64d%I64d",&p.x,&p.y);
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(xm(a[1],a[mid],p)<=0ll)
				r=mid;
			else
				l=mid+1;
		}
		if(l==2||xm(a[1],a[N],p)>=0ll)
			continue;
		if(xm(a[l],a[l-1],p)<0ll)
			cnt++;
	}
	if(cnt==M)
		printf("YES\n");
	else
		printf("NO\n");
	return 0 ;
}