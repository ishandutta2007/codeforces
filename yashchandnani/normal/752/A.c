#include <stdio.h>
int main()
{
	long int n,m,k;
	char b[2];
	b[0]='R';
	b[1]='L';
	scanf("%ld%ld%ld",&n,&m,&k);
	printf("%ld %ld %c\n",((k-1)/(2*m) + 1),((k-1)%(2*m) + 2)/2 , b[k%2] );

	
	return 0;
}