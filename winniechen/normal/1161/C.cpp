#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 55
int n,a[N],mn,cnt;
int main()
{
	scanf("%d",&n);mn=1<<30;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mn=min(mn,a[i]);
	for(int i=1;i<=n;i++)a[i]-=mn,cnt+=(a[i]!=0);
	if(cnt>=n/2)puts("Alice");else puts("Bob");
}