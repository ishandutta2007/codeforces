#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

LL T[100005], dp[100005];

int main()
{
	int n, maxi=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		maxi=max(maxi, a);
		T[a-1]+=a;
	}
	dp[0]=T[0];
	dp[1]=max(T[0], T[1]);
	for(int i=2; i<maxi; i++) dp[i]=max(dp[i-1], dp[i-2]+T[i]);
	cout<< dp[maxi-1] << '\n';
	return 0;
}