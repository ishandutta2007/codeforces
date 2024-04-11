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

int n, m, t, T[100001], R[20002], A[100001];
char C[10];

int main()
{
	//ios_base:sync_with_stdio(0);
	int curr=0, diff=0, last=0, laste=0, tmp=0;
	bool b=0;
	scanf("%d%d%d", &n, &m, &t);
	for(int i=0; i<n; i++)
	{
		scanf("%s", C);
		int x=0;
		x+=((int)C[7]-(int)'0')+((int)C[6]-(int)'0')*10+((int)C[4]-(int)'0')*60+((int)C[3]-(int)'0')*600+((int)C[1]-(int)'0')*3600+((int)C[0]-(int)'0')*36000;
		A[x]++;
	}
	for(int i=0; i<=86400; i++)
	{
		curr-=T[i];
		vector<int> E;
		while(A[i]>0 && curr<m)
		{
			diff++;
			curr++;
			R[tmp]=diff;
			T[i+t]++;
			tmp++;
			last=diff;
			laste=i+t;
			A[i]--;
		}
		if(A[i]>0)
		{
			T[laste]--;
			T[i+t]++;
			laste=i+t;
		}
		while(A[i]>0)
		{
			R[tmp]=last;
			tmp++;
			A[i]--;
		}
		if(curr==m) b=1;
	}
	if(b)
	{
		printf("%d\n", diff);
		for(int i=0; i<n; i++) printf("%d\n", R[i]);
	}
	else printf("No solution\n");
	return 0;
}