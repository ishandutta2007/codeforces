#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

int T[10], res=1000000000;

int main()
{
	for(int i=1; i<10; i++) scanf("%d", T+i);
	T[2]=min(T[2], T[6]+T[4]);
	T[3]=min(T[3], T[5]);
	for(int i=max(T[2], T[6]+1); i<=T[6]+T[4]; i++)
	{
		for(int j=T[3]; j<=T[5]; j++)
		{
			int x=T[4]/(i-T[6]);
			if(T[4]%(i-T[6])!=0) x++;
			int y=x*(T[5]-j);
			int hp=max(0, y-T[1]+1);
			int r=hp*T[7]+(i-T[2])*T[8]+(j-T[3])*T[9];
			res=min(res, r);
		}
	}
	printf("%d\n", res);
	return 0;
}