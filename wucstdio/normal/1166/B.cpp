#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const char s[6]="aeiou";
int k;
void fill(int n,int m)
{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
		putchar(s[(i+j)%5]);
	putchar('\n');
}
int main()
{
	scanf("%d",&k);
	for(int i=5;i*i<=k;i++)
	{
		if(k%i)continue;
		fill(i,k/i);
		return 0;
	}
	printf("-1\n");
	return 0;
}