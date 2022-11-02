#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
const int M=1000000;

bool T[1000001], A[1000001];
vector<int> V;

int main()
{
	int n, li=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		a--;
		T[a]=1;
		A[a]=1;
	}
	for(int i=0; i<M; i++)
	{
		if(T[i] && T[M-i-1])
		{
			li++;
			T[i]=0;
			T[M-i-1]=0;
		}
		else
		{
			if(T[i] && !T[M-i-1])
			{
				V.PB(M-i-1);
				T[i]=0;
				A[M-i-1]=1;
			}
		}
	}
	int ind=0;
	while(li)
	{
		if(!A[ind])
		{
			li--;
			V.PB(ind);
			V.PB(M-ind-1);
		}
		ind++;
	}
	printf("%d\n", (int)V.size());
	for(int i=0; i<V.size(); i++) printf("%d ", V[i]+1);
	return 0;
}