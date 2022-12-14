#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
using namespace std;
#define N 100005
int a[N],n,b[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	if(a[1]!=b[1]&&a[n]!=b[n])return puts("No"),0;
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];sort(a+1,a+n);
	for(int i=1;i<n;i++)b[i]=b[i+1]-b[i];sort(b+1,b+n);
	for(int i=1;i<n;i++)if(a[i]!=b[i])return puts("No"),0;
	puts("Yes");
}