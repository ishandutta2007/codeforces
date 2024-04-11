#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
const ldb PI=acos(-1);
int main()
{
	int n,r;
	scanf("%i %i",&n,&r);
	ldb phi=PI/n;
	ldb cp=sin(phi);
	ldb R=(r*cp)/(1-cp);
	cout<<fixed<<setprecision(12)<<R<<"\n";
	return 0;
}