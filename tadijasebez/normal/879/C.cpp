#include <stdio.h>
int bit[2][11];
int main()
{
	char t;
	int n,x,i;
	scanf("%i",&n);
	for(i=0;i<11;i++) bit[1][i]=1;
	while(n --> 0)
	{
		scanf("\n%c %i",&t,&x);
		if(t=='&') for(i=0;i<11;i++) bit[0][i]&=(x>>i)&1,bit[1][i]&=(x>>i)&1;
		if(t=='|') for(i=0;i<11;i++) bit[0][i]|=(x>>i)&1,bit[1][i]|=(x>>i)&1;
		if(t=='^') for(i=0;i<11;i++) bit[0][i]^=(x>>i)&1,bit[1][i]^=(x>>i)&1;
	}
	int Xor=0,And=1023,Or=0;
	for(i=0;i<10;i++)
	{
		if(bit[0][i]==0 && bit[1][i]==0) And-=1<<i;
		if(bit[0][i]==1 && bit[1][i]==1) Or+=1<<i; 
		if(bit[0][i]==1 && bit[1][i]==0) Xor+=1<<i;
	}
	//printf("%i",1<<10);
	printf("3\n");
	printf("& %i\n",And);
	printf("| %i\n",Or);
	printf("^ %i\n",Xor);
	return 0;
}