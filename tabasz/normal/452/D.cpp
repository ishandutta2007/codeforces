#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

short int T[3][30000003];

int main()
{
	ios_base::sync_with_stdio(0);
	int k, n1, n2, n3, t1, t2, t3;
	scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	
	int t=0;
	while(k>0)
	{
		n1+=T[0][t];
		n2+=T[1][t];
		n3+=T[2][t];
		int x=min(n1, min(n2, n3));
		n1-=x;
		n2-=x;
		n3-=x;
		k-=x;
		T[0][t+t1]+=x;
		T[1][t+t2]+=x;
		T[2][t+t3]+=x;
		//printf("%d %d\n", t, x);
		t++;
	}
	t+=t1+t2+t3-1;
	printf("%d\n", t);
	return 0;
}