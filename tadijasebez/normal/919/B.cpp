#include <stdio.h>
bool Check(int n)
{
	int sum=0;
	while(n) sum+=n%10,n/=10;
	return sum==10;
}
int main()
{
	int k,i,n=18;
	scanf("%i",&k);
	while(k)
	{
		n++;
		if(Check(n)) k--;
	}
	printf("%i\n",n);
	return 0;
}