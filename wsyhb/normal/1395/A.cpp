#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a%2+b%2+c%2+d%2<=1||(a>0&&b>0&&c>0&&(a-1)%2+(b-1)%2+(c-1)%2+(d+3)%2<=1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}