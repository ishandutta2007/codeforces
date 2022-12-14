#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <bitset>
using namespace std;
int x;
int main()
{
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
		for(int j=i;j<=x;j+=i)
			if(i*j>x)return printf("%d %d\n",j,i),0;
	puts("-1");
}