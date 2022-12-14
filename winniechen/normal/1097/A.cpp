#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
char opt[10],s[10];
int main()
{
	scanf("%s",s+1);
	for(int i=1;i<=5;i++)
	{
		scanf("%s",opt+1);
		if(opt[1]==s[1]||opt[2]==s[2])return puts("YES"),0;
	}
	puts("NO");
	return 0;
}