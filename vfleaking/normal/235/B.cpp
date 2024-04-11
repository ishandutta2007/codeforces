#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	cin >> n;
	
	double res = 0.0, add = 0.0;
	for (int i = 0; i < n; i++)
	{
		double p;
		scanf("%lf", &p);
		
		res += p * (1 + add * 2);
		add = p * add + p;
	}
	printf("%.7lf\n", res);
	
	return 0;
}