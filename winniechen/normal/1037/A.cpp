#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=0;(1<<i)<n;i++)ans++,n-=(1<<i);if(n)ans++;
	printf("%d\n",ans);
}