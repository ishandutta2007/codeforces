#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
char s[N];
int ans,n;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)if(s[i]-'0'==8)ans++;
	printf("%d\n",min(n/11,ans));
}