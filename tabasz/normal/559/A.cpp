#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int T[10];

int main()
{
	for(int i=0; i<6; i++)
		scanf("%d", T+i);
	printf("%d\n", (T[0]+T[1]+T[5])*(T[0]+T[1]+T[5])-T[1]*T[1]-T[3]*T[3]-T[5]*T[5]);
	return 0;
}