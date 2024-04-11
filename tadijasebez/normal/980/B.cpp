#include <stdio.h>
const int N=105;
bool sol[4][N];
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(j=1;j<=2;j++) for(i=2;i<=n/2 && k>=2;i++) k-=2,sol[j][i]=sol[j][n-i+1]=1;
	for(j=1;j<=2 && k>=1;j++) sol[j][n/2+1]=1,k--;
	printf("YES\n");
	for(j=0;j<4;j++) for(i=1;i<=n;i++) printf("%c",sol[j][i]?'#':'.'),i==n?printf("\n"):0;
	return 0;
}