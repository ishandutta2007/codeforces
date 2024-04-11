#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 
const double eps=10e-12;

int n;
int A[200005];
double B[200005];

double solve(double x)
{
	double r=0;
	for(int i=0; i<n; i++)
		B[i]=(double)A[i]-x;
	double mini=0, maxi=0, tmp=0;
	for(int i=0; i<n; i++)
	{
		tmp+=B[i];
		r=max(r, maxi-tmp);
		r=max(r, tmp-mini);
		maxi=max(maxi, tmp);
		mini=min(mini, tmp);
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", A+i);
	double p=-1000000000.0, k=1000000000.0;
	int qwe=200;
	while(qwe--)
	{
		double m1=p+(k-p)/3.0, m2=k-(k-p)/3.0;
		double r1=solve(m1), r2=solve(m2);
		if(r1>r2)
			p=m1;
		else
			k=m2;
	}
	printf("%.10lf\n", solve(p));
	return 0;
}