#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int maxx,n,digit[15];
int calc()
{
	int ans=1;
	for(int i=1;i<=digit[0];i++)ans*=digit[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	while(n)
	{
		digit[++digit[0]]=n%10;
		n/=10;
	}
	maxx=max(maxx,calc());
	for(int i=1;i<=digit[0];i++)
	{
		if(digit[i]>1)
		{
			digit[i]--;
			for(int j=1;j<i;j++)digit[j]=9;
			maxx=max(maxx,calc());
		}
	}
	digit[0]--;
	for(int i=1;i<=digit[0];i++)digit[i]=9;
	maxx=max(maxx,calc());
	printf("%d\n",maxx);
	return 0;
}