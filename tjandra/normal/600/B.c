#include<stdio.h>
#include<stdlib.h>
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
int A[222222],p;
int main()
{
	int i,q,lo,hi,mi;
	scanf("%i%i",&p,&q);
	for(i=p;i--;)scanf("%i",A+i);
	for(qsort(A,p,sizeof(int),F);q--;printf("%i%c",hi,q?' ':'\n'))
	{
		scanf("%i",&i);
		if(i<*A){hi=0;continue;}
		lo=0;hi=p;
		while((mi=(lo+hi)>>1)>lo)
		{
			if(A[mi]>i)hi=mi;
			else lo=mi;
		}
	}
	return 0;
}