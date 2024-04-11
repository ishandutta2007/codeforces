#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
struct N
{
	int x;
	int y;
	bool operator<(const N& b)const
	{
		return y<b.y;
	}
};
N a[111];
ull p[111];
int main()
{
	int n;
	scanf("%d",&n);
	ull allx=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		allx+=a[i].x;
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		scanf("%I64d",&p[i]);
	p[t]=allx;
	t++;
	sort(a,a+n);
	int f=1;
	ull ans=0;
	ull dec=0;
	int ps=0;
	for(int i=0;i<n;i++)
	{
		while(a[i].x)
		{
			int mn=min((ull)a[i].x,p[ps]-dec);
			dec+=mn;
			ans+=(long long)mn*f*a[i].y;
			a[i].x-=mn;
			if(dec==p[ps])
			{
				ps++;
				f++;
			}
		}
	}
	printf("%I64u\n",ans);
	return 0;
}