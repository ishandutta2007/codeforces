#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const double PI = acos(-1);
double CircleArea(int r)
{
	double rr=(double) r;
	return rr*rr*PI;
}
vector<int> R;
bool compare(int a, int b)
{
	return a>b; 
}
double sol;
int main()
{
	int n,i,r;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&r);
		R.push_back(r);
	}
	R.push_back(0);
	sort(R.begin(),R.end(),compare);
	for(i=0;i<n;i+=2)
	{
		sol+=CircleArea(R[i]);
		sol-=CircleArea(R[i+1]);
	}
	printf("%.12llf\n",sol);
	return 0;
}