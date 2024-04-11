#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, a, x1, x2, y11, y2, x3, y3, x4, y4;
int A[4][2], B[4][2];

void findx1()
{
	int st=1, en=n, mid=(st+en)/2, r=1;
	while(st<=en)
	{
		printf("? %d 1 %d %d\n", mid, n, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a==2)
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	A[0][0]=r;
	st=1;
	en=n;
	mid=(st+en)/2;
	r=1;
	while(st<=en)
	{
		printf("? %d 1 %d %d\n", mid, n, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a>0)
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	A[0][1]=r;
}

void findx2()
{
	int st=1, en=n, mid=(st+en)/2, r=n;
	while(st<=en)
	{
		printf("? 1 1 %d %d\n", mid, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a==2)
		{
			r=min(r, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	A[1][0]=r;
	st=1;
	en=n;
	mid=(st+en)/2;
	r=n;
	while(st<=en)
	{
		printf("? 1 1 %d %d\n", mid, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a>0)
		{
			r=min(r, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	A[1][1]=r;
}

void findy1()
{
	int st=1, en=n, mid=(st+en)/2, r=1;
	while(st<=en)
	{
		printf("? 1 %d %d %d\n", mid, n, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a==2)
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	A[2][0]=r;
	st=1;
	en=n;
	mid=(st+en)/2;
	r=1;
	while(st<=en)
	{
		printf("? 1 %d %d %d\n", mid, n, n);
		fflush(stdout);
		scanf("%d", &a);
		if(a>0)
		{
			r=max(r, mid);
			st=mid+1;
		}
		else
			en=mid-1;
		mid=(st+en)/2;
	}
	A[2][1]=r;
}

void findy2()
{
	int st=1, en=n, mid=(st+en)/2, r=n;
	while(st<=en)
	{
		printf("? 1 1 %d %d\n", n, mid);
		fflush(stdout);
		scanf("%d", &a);
		if(a==2)
		{
			r=min(r, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	A[3][0]=r;
	st=1;
	en=n;
	mid=(st+en)/2;
	r=n;
	while(st<=en)
	{
		printf("? 1 1 %d %d\n", n, mid);
		fflush(stdout);
		scanf("%d", &a);
		if(a>0)
		{
			r=min(r, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	A[3][1]=r;
}

int main()
{
	scanf("%d", &n);
	findx1();
	findx2();
	findy1();
	findy2();
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<4; j++)
		{
			B[j][0]=A[j][(i>>j)%2];
			B[j][1]=A[j][1-(i>>j)%2];
		}
		int a, b;
		if(B[0][0]>B[1][0] || B[2][0]>B[3][0])
			continue;
		if(B[0][1]>B[1][1] || B[2][1]>B[3][1])
			continue;
		printf("? %d %d %d %d\n", B[0][0], B[2][0], B[1][0], B[3][0]);
		fflush(stdout);
		scanf("%d", &a);
		printf("? %d %d %d %d\n", B[0][1], B[2][1], B[1][1], B[3][1]);
		fflush(stdout);
		scanf("%d", &b);
		if(a==1 && b==1)
		{
			printf("! %d %d %d %d %d %d %d %d\n", B[0][0], B[2][0], B[1][0], B[3][0], B[0][1], B[2][1], B[1][1], B[3][1]);
			return 0;
		}
	}
	return 0;
}