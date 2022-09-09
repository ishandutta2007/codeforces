#include <stdio.h>
#define ll long long
ll m;
ll Find(ll a, ll b, ll x, ll y, ll d=0)
{
	if(d>m) return -d*2;
	if(a==b) return 0;
	return Find(((ll)a*x%m+y)%m,b,x,y,d+1)+1;
}
int main()
{
	ll h1,a1,h2,a2,x1,x2,y1,y2;
	scanf("%lld",&m);
	scanf("%lld %lld",&h1,&a1);
	scanf("%lld %lld",&x1,&y1);
	scanf("%lld %lld",&h2,&a2);
	scanf("%lld %lld",&x2,&y2);
	ll t1,t2,f1,f2;
	t1=Find(((ll)a1*x1%m+y1)%m,a1,x1,y1)+1;
	f1=Find(h1,a1,x1,y1);
	t2=Find(((ll)a2*x2%m+y2)%m,a2,x2,y2)+1;
	f2=Find(h2,a2,x2,y2);
	//printf("%lld %lld %lld %lld\n",t1,f1,t2,f2);
	if(f1<0 || f2<0) return printf("-1\n"),0;
	if(f1==f2) return printf("%lld\n",f1),0;
	//if(t1<0 || t2<0) return printf("-1\n"),0;
	for(int i=0;i<m;i++)
	{
		if(f1<f2 && t1>=0) f1+=t1;
		if(f2<f1 && t2>=0) f2+=t2;
		if(f1==f2) return printf("%lld\n",f1),0;
	}
	printf("-1\n");
	return 0;
}