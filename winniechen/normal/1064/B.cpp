#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		int x;scanf("%d",&x);
		int ret=0;
		while(x){ret++;x&=x-1;}
		printf("%d\n",1<<ret);
	}
}