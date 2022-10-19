#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,a[N];
void sol()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=n;
	while(l&&a[l]==l)
		l--;
	double ans=1;
	while(m--)
	{
		int x;
		double p;
		scanf("%d%lf",&x,&p);
		if(x>=l)
			ans*=(1-p);
	}
	if(!l)
		ans=0;
	printf("%.9lf\n",1-ans);
}
int main()
{
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}