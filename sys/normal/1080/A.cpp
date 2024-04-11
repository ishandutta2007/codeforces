#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d",(int)(ceil(2.0*n/k)+ceil(5.0*n/k)+ceil(8.0*n/k)));
	return 0;
}