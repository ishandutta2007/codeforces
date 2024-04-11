#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		if(a)ans++,a--;
		if(b)ans++,b--;
		if(c)ans++,c--;
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a>b)swap(a,b);
		if(a==0)
		{
			if(b&&c)ans++;
		}
		else if(a==1&&b==1)
		{
			if(c>=2)ans+=2;
			else if(c==1)ans++;
		}
		else if(a==1)ans+=2;
		else if(a==2)ans+=3;
		else ans+=4;
		printf("%d\n",ans);
	}
	return 0;
}