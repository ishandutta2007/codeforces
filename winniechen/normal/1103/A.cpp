#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
char s[N];int n;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1,now1=0,now2=0;i<=n;i++)
	{
		if(s[i]=='1')
		{
			if(now1)printf("1 3\n");
			else printf("1 1\n");
			now1^=1;
		}else
		{
			printf("%d %d\n",3,now2+1);
			now2++;now2%=4;
		}
	}
}