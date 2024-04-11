#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int main()
{
	int a,b,f,k;
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int s=b;
	s-=f;
	int ans=0;
	f=a-f;
	for(k--;k;k--)
	{
		if(s<0)
		{
			printf("-1\n");
			return 0;
		}
		if(2*f>s)
		{
			s=b;
			ans++;
		}
		s-=2*f;
		f=a-f;
	}
	if(s<0)
	{
		printf("-1\n");
		return 0;
	}
	if(f>s)
	{
		s=b;
		ans++;
	}
	s-=f;
	if(s<0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}