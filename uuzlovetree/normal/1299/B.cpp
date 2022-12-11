#include<bits/stdc++.h>
using namespace std;
int n;
struct Point
{
	int x,y;
}a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	if(n&1)
	{
		puts("NO");
		return 0;
	}
	int X=a[1].x+a[n/2+1].x;
	int Y=a[1].y+a[n/2+1].y;
	bool yes=1;
	for(int i=1;i<=n/2;++i)if(a[i].x+a[i+n/2].x!=X||a[i].y+a[i+n/2].y!=Y)yes=0;
	if(yes)puts("YES");
	else puts("NO");
}