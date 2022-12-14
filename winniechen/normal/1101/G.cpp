#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
#define ll long long
int a[32],now;
void insert(int x)
{
	for(int i=30;~i;i--)if((x>>i)&1)
		if(a[i])x^=a[i];
		else {a[i]=x;return ;}
}
int main()
{
	int n,x;
	scanf("%d",&n);
	while(n--)scanf("%d",&x),insert(x),now^=x;
	if(!now)return puts("-1"),0;
	x=0;
	for(int i=30;~i;i--)if(a[i])x++;
	printf("%d\n",x);
}