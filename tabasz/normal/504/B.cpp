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
const int M=262144;

int D[3][2*M], T[2][M];
int A[M];

void add(int ind, int v, int w)
{
	v+=M;
	D[ind][v]=w;
	while(v>1)
	{
		v/=2;
		D[ind][v]=D[ind][2*v]+D[ind][2*v+1];
	}
}

int sum(int ind, int p, int k)
{
	if(p>k) return 0;
	p+=M;
	k+=M;
	int res=D[ind][p];
	if(k!=p) res+=D[ind][k];
	while(p/2!=k/2)
	{
		if(p%2==0) res+=D[ind][p+1];
		if(k%2==1) res+=D[ind][k-1];
		p/=2;
		k/=2;
	}
	return res;
}

int kth(int x, int v)
{
	if(v>=M) return v-M;
	if(D[2][2*v]<=x) return kth(x-D[2][2*v], 2*v+1);
	return kth(x, 2*v);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	for(int qwe=0; qwe<3; qwe++)
	{
		for(int i=0; i<n; i++) D[qwe][i+M]=1;
		for(int i=M-1; i>0; i--) D[qwe][i]=D[qwe][2*i]+D[qwe][2*i+1];
		if(qwe<2)
		{
			for(int i=0; i<n; i++)
			{
				int a;
				scanf("%d", &a);
				T[qwe][i]=a;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int qwe=0; qwe<2; qwe++)
		{
			int s=sum(qwe, 0, T[qwe][i]-1);
			A[i]+=s;
			add(qwe, T[qwe][i], 0);
		}
	}
	int tmp=1;
	for(int i=n-1; i>=0; i--)
	{
		while(A[i]>=tmp)
		{
			A[i]-=tmp;
			if(i-1>=0) A[i-1]++;
		}
		tmp++;
	}
	for(int i=0; i<n; i++)
	{
		//printf("%d ", A[i]);
		int x=kth(A[i], 1);
		printf("%d ", x);
		add(2, x, 0);
	}
	printf("\n");
	return 0;
}