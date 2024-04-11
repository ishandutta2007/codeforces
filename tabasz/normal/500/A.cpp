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
#define PII pair<int, int>

int T[100005];
bool B[100005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n-1; i++) scanf("%d", T+i);
	int i=0;
	while(i<n-1)
	{
		B[i]=1;
		i+=T[i];
		//printf("%d\n", n);
	}
	B[n-1]=1;
	if(B[m-1]) printf("YES\n");
	else printf("NO\n");
	return 0;
}