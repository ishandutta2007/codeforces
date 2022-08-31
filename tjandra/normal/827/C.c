#include <stdio.h>
typedef unsigned u;
u B[4][11][11][111111];
u F[111],n;
char S[111111];
void upd(u*P,u id,u val)
{
	for(;id<=n+5;id+=id&-id)P[id]+=val;
	return;
}
u que(u*P,u id)
{
	u r=0;
	for(;id;id&=id-1)r+=P[id];
	return r;
}
char P[11];
int main()
{
	F['A']=0;F['T']=1;F['G']=2;F['C']=3;
	for(scanf("%s",S+1);S[++n];);
	u i,j,k,l,x,y,q,t,r;
	for(i=0;++i<=n;)
		for(j=0;++j<11;)
			upd(B[F[(u)S[i]]][j][i%j],1+i/j,1);
	for(scanf("%u",&q);q--;)
	{
		scanf("%u",&t);
		if(t==1)
		{
			scanf("%u%s",&i,P);
			for(j=0;++j<11;)
				upd(B[F[(u)S[i]]][j][i%j],1+i/j,-1);
			S[i]=*P;
			for(j=0;++j<11;)
				upd(B[F[(u)S[i]]][j][i%j],1+i/j,1);
		}
		if(t==2)
		{
			scanf("%u%u%s",&i,&j,P);r=0;
			for(l=0;P[++l];);
			for(k=-1;++k<l;)
			{
				x=i+k;
				if(x>j)break;
				y=i+k+l*((j-i-k)/l);
				r-=que(B[F[(u)P[k]]][l][x%l],x/l);
				r+=que(B[F[(u)P[k]]][l][y%l],1+y/l);
			}
			printf("%u\n",r);
		}
	}
}