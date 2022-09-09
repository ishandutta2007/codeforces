#include <bits/stdc++.h>
using namespace std;
#define ldb long double
int main()
{
	int a,b,c,d;
	ldb p,q;
	scanf("%i %i %i %i",&a,&b,&c,&d);
	p=(ldb)a/b;
	q=(1-(ldb)a/b)*(1-(ldb)c/d);
	cout<<fixed<<setprecision(20)<<p/(1-q)<<"\n";
	return 0;
}