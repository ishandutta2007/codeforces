#include <iostream>
#include <cstdio>
#include <map>
#define maxn 100005
#define uint unsigned int
using namespace std;
int n, p;
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= 2000; i++)
	{
		int x = n - p * i, cnt = 0;
		if(x < 0) break;
		if(x < i) continue;
		for (int j = 0; j <= 30; j++) cnt += ((x >> j) & 1);
		if(cnt <= i) 
		{
			printf("%d", i);
			return 0;	
		}
	}
	printf("-1");
	return 0;
}