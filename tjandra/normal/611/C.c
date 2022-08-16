#include<stdio.h>
typedef unsigned u;
char M[555][555];
u H[555][555],V[555][555];
u F(u(*P)[555],u a,u b,u c,u d)
{return P[c][d]-P[c][b?b-1:0]-P[a?a-1:0][d]+P[a?a-1:0][b?b-1:0];}
int main()
{
	u x,y,i,j,q,a,b,c,d;
	scanf("%u%u",&x,&y);
	for(i=0;++i<=x;)scanf("%s",M[i]+1);
	for(i=0;++i<=x;)for(j=0;++j<=y;)
	{
		H[i][j]=H[i][j-1]+H[i-1][j]-H[i-1][j-1]+(M[i][j]=='.'&&M[i][j+1]=='.');
		V[i][j]=V[i][j-1]+V[i-1][j]-V[i-1][j-1]+(M[i][j]=='.'&&M[i+1][j]=='.');
	}
	for(scanf("%u",&q);q--;)
	{
		scanf("%u%u%u%u",&a,&b,&c,&d);
		printf("%u\n",F(H,a,b,c,d-1)+F(V,a,b,c-1,d));
	}
	return 0;
}