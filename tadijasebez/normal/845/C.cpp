#include <stdio.h>
#include <algorithm>
using namespace std;
struct Show
{
	int l,r;
	inline bool operator < (const Show &b) const
	{
		if(l==b.l) return r<b.r;
		return l<b.l;
	}
} Shows[200050];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i %i",&Shows[i].l,&Shows[i].r);
	sort(Shows,Shows+n);
	int first=-1,second=-1;
	bool ok=true;
	for(i=0;i<n;i++)
	{
		if(Shows[i].l>first)
		{
			first=Shows[i].r;
		}
		else if(Shows[i].l>second)
		{
			second=Shows[i].r;
		}
		else ok=false;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}