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

bool B[1001];
int T[1001], Z[1001];


int main()
{
	int n, m, res=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", T+i);
	for(int i=0; i<m; i++) scanf("%d", Z+i);
	for(int i=0; i<m; i++) Z[i]--;
	for(int i=1; i<m; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(Z[j]==Z[i]) break;
			B[Z[j]]=1;
		}
		for(int j=0; j<n; j++) if(B[j]) res+=T[j];
		for(int j=0; j<n; j++) B[j]=0;
		//printf("%d\n", res);
	}
	printf("%d\n", res);
	return 0;
}