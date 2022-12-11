#include<bits/stdc++.h>
using namespace std;
const int rating[9]={1200,1400,1600,1900,2100,2300,2400,2600,3000};
int main()
{
	int r;
	scanf("%d",&r);
	printf("%d\n",*upper_bound(rating,rating+9,r));
	return 0;
}