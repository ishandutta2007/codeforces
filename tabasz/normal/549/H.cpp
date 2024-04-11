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
const double eps=0.000000000001;

double A[4], res=1000000001.0;
pair<double, double> T[4], X[2];

int main()
{
	//ios_base::sync_with_stdio(0);
	for(int i=0; i<4; i++)
		scanf("%lf", A+i);
	double p=0, k=max(max(abs(A[0]), abs(A[1])), max(abs(A[2]), abs(A[3]))), mid=(p+k)/2;
	res=k;
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<4; j++)
		{
			T[j].F=min(A[j]-mid, mid+A[j]);
			T[j].S=max(A[j]-mid, mid+A[j]);
		}
		X[0].F=min(min(T[0].F*T[3].F, T[0].S*T[3].S), min(T[0].F*T[3].S, T[0].S*T[3].F));
		X[0].S=max(max(T[0].F*T[3].F, T[0].S*T[3].S), max(T[0].F*T[3].S, T[0].S*T[3].F));
		X[1].F=min(min(T[1].F*T[2].F, T[1].S*T[2].S), min(T[1].F*T[2].S, T[1].S*T[2].F));
		X[1].S=max(max(T[1].F*T[2].F, T[1].S*T[2].S), max(T[1].F*T[2].S, T[1].S*T[2].F));
		double pp=max(X[0].F, X[1].F), kk=min(X[0].S, X[1].S);
		if(pp<=kk)
		{
			res=min(res, mid);
			k=mid;
		}
		else p=mid;
		mid=(p+k)/2;
	}
	printf("%.9lf\n", res);
	return 0;
}