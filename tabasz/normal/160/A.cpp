#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<map>
#include<ctime>
#include<queue>
//#include<>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

int T[1001];

int main()
{
	int n, sum=0, x=0, res=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", T+i);
		sum+=T[i];
	}
	sort(T, T+n);
	sum/=2;
	for(int i=n-1; i>=0; i--)
	{
		x+=T[i];
		res++;
		if(x>sum) break;
	}
	printf("%d\n", res);
	return 0;
}