#include <cstdio>
#include <algorithm>

using namespace std;

long long int l1,r1,l2,r2,k;

bool bet(long long int a, long long int b, long long int c){return (a<=b)&&(b<=c);}

int main()
{
	scanf("%lli %lli %lli %lli %lli",&l1,&r1,&l2,&r2,&k);
	long long int l=l1,r=r1;
	if(l2>r1 || r2<l1) {printf("0");return 0;}
	if(l2>l1)l=l2;
	if(r2<r1)r=r2;
	printf("%lli",r-l+1-(bet(l,k,r)?1:0));
}