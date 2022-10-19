#include<bits/stdc++.h>
using namespace std;
int a[]={1200,1400,1600,1900,2100,2300,2400,2600,3000};
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",*upper_bound(a,a+9,x));
	return 0;
}