#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num[20],ans;
inline int read()
{
	char c=getchar();
	while(c!='X'&&c!='S'&&c!='M'&&c!='L')c=getchar();
	if(c=='S')return 1;
	if(c=='M')return 2;
	if(c=='L')return 3;
	c=getchar();
	if(c=='S')return 4;
	if(c=='L')return 5;
	c=getchar();
	if(c=='S')return 6;
	if(c=='L')return 7;
	c=getchar();
	if(c=='S')return 8;
	if(c=='L')return 9;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  num[read()]++;
	for(int i=1;i<=n;i++)
	  num[read()]--;
	for(int i=1;i<=9;i++)
	  if(num[i]>0)ans+=num[i];
	printf("%d\n",ans);
	return 0;
}