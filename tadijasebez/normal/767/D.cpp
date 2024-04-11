#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1000050;
int a[N],n,m,k;
pair<int,int> b[N];
vector<int> c;
bool Check(int mid)
{
	c.clear();
	int i=1,j=mid;
	while(j<=m || i<=n)
	{
		if(i<=n && ((j<=m && a[i]<=b[j].first) || (j>m))) c.push_back(a[i++]);
		if(j<=m && ((i<=n && b[j].first<=a[i]) || (i>n))) c.push_back(b[j++].first);
	}
	for(i=0;i<c.size();i++) if(c[i]<i/k) return false;
	return true;
}
int main()
{
	int i;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=m;i++) scanf("%i",&b[i].first),b[i].second=i;
	sort(b+1,b+1+m);
	int top=m+1,bot=1,sol=-1,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) sol=mid,top=mid-1;
		else bot=mid+1;
	}
	if(sol==-1) printf("-1\n");
	else
	{
		printf("%i\n",m+1-sol);
		for(i=sol;i<=m;i++) printf("%i ",b[i].second);
	}
	return 0;
}