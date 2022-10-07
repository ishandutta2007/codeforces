#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num0,num1;
char s[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')num0++;
		else num1++;
	}
	if(num1!=num0)
	{
		printf("1\n");
		printf("%s\n",s+1);
		return 0;
	}
	printf("2\n");
	putchar(s[1]);
	putchar(' ');
	printf("%s\n",s+2);
	return 0;
}