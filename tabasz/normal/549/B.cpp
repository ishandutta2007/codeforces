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

int n, res;
int A[101], B[101], T[101][101];
char C[101][101];
bool boo[101];
queue<int> Q;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s", C[i]);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(C[i][j]=='1') T[i][j]=1;
		}
	}
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		A[i]=a;
		if(a==0)
		{
			Q.push(i);
			boo[i]=1;
			res++;
		}
	}
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<n; i++)
		{
			if(T[v][i]==1)
			{
				B[i]++;
				if(B[i]==A[i])
				{
					Q.push(i);
					boo[i]=1;
					res++;
				}
			}
		}
	}
	printf("%d\n", res);
	for(int i=0; i<n; i++)
		if(boo[i]) printf("%d ", i+1);
	printf("\n");
	return 0;
}