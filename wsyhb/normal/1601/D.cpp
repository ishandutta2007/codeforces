#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
struct Pair
{
	int s,a;
}p[max_n];
inline bool operator < (const Pair &x,const Pair &y)
{
	int p=max(x.s,x.a),q=max(y.s,y.a);
	if(p!=q)
		return p<q;
	return x.s!=y.s?x.s<y.s:x.a<y.a; 
}
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].s,&p[i].a);
	sort(p+1,p+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(d<=p[i].s)
		{
			++ans;
			d=max(d,p[i].a);
		}
	}
	printf("%d\n",ans);
	return 0;
}