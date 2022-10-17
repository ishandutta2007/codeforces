#include<stdio.h>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int n,r[100020],s,e;
typedef pair<int,int>ii;
ii a[100020];
bool cmp(const int &x,const int &y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	s=1e9;
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].X,&a[i].Y),s=min(s,a[i].X),e=max(e,a[i].Y),a[i].Y=-a[i].Y,r[i]=i;
	sort(r,r+n,[](int x,int y){return a[x]<a[y];});
	if(a[*r].X==s&&a[*r].Y==-e)
		printf("%d",*r+1);
	else
		puts("-1");
}