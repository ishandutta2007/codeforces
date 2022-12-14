#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 1005
char s[N];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
		{
			cnt++;
		}
	}
	if(!cnt)
	{
		puts("YES");
		return 0;
	}
	if((n-cnt)%(cnt))
	{
		puts("NO");
	}else
	{
		puts("YES");
	}
	return 0;
}