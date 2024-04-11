#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
#define ll long long
int n,now_mx,maxx;char s[10];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x,y;scanf("%s%d%d",s+1,&x,&y);
		if(x<y)swap(x,y);
		if(s[1]=='+')now_mx=max(x,now_mx),maxx=max(y,maxx);
		else puts(x>=now_mx&&y>=maxx?"YES":"NO");
	}
}