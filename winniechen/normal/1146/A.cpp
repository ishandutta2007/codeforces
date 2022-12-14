#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
char s[105];
int main()
{
	scanf("%s",s+1);int ret=0,n=strlen(s+1);
	for(int i=1;i<=n;i++)ret+=s[i]=='a';
	printf("%d\n",min((ret<<1)-1,n));
}