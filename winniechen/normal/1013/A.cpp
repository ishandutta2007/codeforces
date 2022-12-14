#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 55
int n;
int main()
{
	scanf("%d",&n);int sum=0;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),sum+=x;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),sum-=x;
	if(sum>=0)puts("Yes");
	else puts("No");
}