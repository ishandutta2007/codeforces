#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int eat[7]={1,2,3,1,3,2,1};
int a,b,c,ans;
int num[4];
int calc(int st)
{
	num[1]=a,num[2]=b,num[3]=c;
	for(int i=0;i<7;i++)
	{
		if(num[eat[(st+i)%7]]==0)return i;
		else num[eat[(st+i)%7]]--;
	}
	return 7;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	ans=min(min(a/3,b/2),c/2);
	a-=ans*3;
	b-=ans*2;
	c-=ans*2;
	ans=ans*7;
	int maxx=0;
	for(int st=0;st<7;st++)
	  maxx=max(maxx,calc(st));
	printf("%d\n",ans+maxx);
	return 0;
}