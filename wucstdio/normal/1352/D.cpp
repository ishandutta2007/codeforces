#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sl=0,sr=0,lastl=0,lastr=0;
		int l=1,r=n;
		int cnt=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		while(l<=r)
		{
			cnt++;
			lastl=0;
			while(l<=r&&lastl<=lastr)lastl+=a[l],sl+=a[l++];
			if(l>r)break;
			cnt++;
			lastr=0;
			while(l<=r&&lastr<=lastl)lastr+=a[r],sr+=a[r--];
		}
		printf("%d %d %d\n",cnt,sl,sr);
	}
	return 0;
}