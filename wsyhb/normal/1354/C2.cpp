#include<bits/stdc++.h>
using namespace std;
const double Pi=3.1415926535897932384626433832795;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%.10lf\n",cos(Pi/(n<<2))/sin(Pi/(n<<1)));
	} 
	return 0;
}