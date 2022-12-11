#include<bits/stdc++.h>
using namespace std;
const int max_n=1<<16|5;
int a[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	int xor_12,xor_23,xor_31,and_12,and_23,and_31;
	puts("XOR 1 2");
	fflush(stdout);
	scanf("%d",&xor_12);
	puts("XOR 2 3");
	fflush(stdout);
	scanf("%d",&xor_23);
	xor_31=xor_12^xor_23;
	puts("AND 1 2");
	fflush(stdout);
	scanf("%d",&and_12);
	puts("AND 2 3");
	fflush(stdout);
	scanf("%d",&and_23);
	puts("AND 3 1");
	fflush(stdout);
	scanf("%d",&and_31);
	int sum_12=xor_12+(and_12<<1);
	int sum_23=xor_23+(and_23<<1);
	int sum_31=xor_31+(and_31<<1);
	int sum_123=(sum_12+sum_23+sum_31)>>1;
	a[1]=sum_123-sum_23;
	a[2]=sum_123-sum_31;
	a[3]=sum_123-sum_12;
	for(int i=4;i<=n;++i)
	{
		int xor_1i;
		printf("XOR 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&xor_1i);
		a[i]=a[1]^xor_1i;
	}
	printf("!");
	for(int i=1;i<=n;++i)
		printf(" %d",a[i]);
	puts("");
	fflush(stdout);
	return 0;
}