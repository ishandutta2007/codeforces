#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int n,num;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='n')num++;
	}
	for(int i=1;i<=num;i++)printf("1 ");
	n-=num*3;
	for(int i=1;i*4<=n;i++)printf("0 ");
	printf("\n");
	return 0;
}