#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

string a, b;

bool cmp(int p1, int k1, int p2, int k2)
{
	for(int i=0; i<k1-p1+1; i++)
	{
		if(a[i+p1]!=b[i+p2])
			return false;
	}
	return true;
}

bool solve(int p1, int k1, int p2, int k2)
{
	if((k1-p1)%2==0)
		return cmp(p1, k1, p2, k2);
	int mid1=(p1+k1)/2, mid2=(p2+k2)/2;
	if(solve(p1, mid1, p2, mid2))
		return solve(mid1+1, k1, mid2+1, k2);
	if(solve(p1, mid1, mid2+1, k2))
		return solve(mid1+1, k1, p2, mid2);
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> a >> b;
	if(a==b)
	{
		printf("YES\n");
		return 0;
	}
	if(a.size()%2)
	{
		printf("NO\n");
		return 0;
	}
	int n=(int)a.size();
	if(solve(0, n-1, 0, n-1))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}