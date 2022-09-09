#include <stdio.h>
int main()
{
	int l,t1,t2,v1,v2;
	scanf("%i%i%i%i%i",&l,&v1,&v2,&t1,&t2);
	int first=l*v1+2*t1;
	int second=l*v2+2*t2;
	if(first<second) printf("First\n");
	if(first>second) printf("Second\n");
	if(first==second) printf("Friendship\n");
	return 0;
}