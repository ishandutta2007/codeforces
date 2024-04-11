#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
int x1[N],x2[N],y1[N],y2[N];
int xl[N],xr[N],yl[N],yr[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&x1[i],&y1[i],&x2[i],&y2[i]);
		xl[i]=x1[i];xr[i]=x2[i];
		yl[i]=y1[i];yr[i]=y2[i];
	}
	sort(yl+1,yl+1+n);reverse(yl+1,yl+1+n);
	sort(yr+1,yr+1+n);
	sort(xl+1,xl+1+n);reverse(xl+1,xl+1+n);
	sort(xr+1,xr+1+n);
	for(i=1;i<=n;i++)
	{
		int a=yl[1],b=yr[1],c=xl[1],d=xr[1];
		if(yl[1]==y1[i]) a=yl[2];
		if(yr[1]==y2[i]) b=yr[2];
		if(xl[1]==x1[i]) c=xl[2];
		if(xr[1]==x2[i]) d=xr[2];
		if(a<=b && c<=d) return printf("%i %i\n",c,a),0;
	}
	return 0;
}