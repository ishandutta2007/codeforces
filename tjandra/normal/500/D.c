#include<stdio.h>
#include<stdlib.h>
#define bfr 128
typedef long long unsigned llu;
typedef unsigned u;
typedef double d;
u E[111111][3],X[111111],V[111111];
llu N[111111];
u *G[111111],Gi[111111],Ga[111111];
void add(u i,u j)
{
	if(Gi[j]==Ga[j])
	{
		Ga[j]+=bfr;
		if(Gi[j]==0)G[j]=(u*)calloc(Ga[j],sizeof(u));
		else G[j]=(u*)realloc(G[j],Ga[j]*sizeof(u));
	}
	G[j][Gi[j]++]=i;
	return;
}
u DFS(u n,u deep)
{
	if(V[n])return 0;
	V[n]=deep;
	u r=0,i,j=Gi[n];
	for(i=0;i<j;++i)r+=DFS(G[n][i],deep+1);
	return X[n]=r+1;
}
int main()
{
	u a,b,n,m,i,j,k,l;llu x;d w=0.0,r=0.0;
	scanf("%u",&n);--n;
	for(i=0;i<n;++i)
	{
		scanf("%u%u%u",&j,&k,&l);
		E[i][0]=j;E[i][1]=k;E[i][2]=l;
		add(j,k);add(k,j);
	}
	DFS(1,1);
	for(i=0;i<n;++i)
	{
		j=E[i][0];k=E[i][1];l=E[i][2];
		if(V[j]>V[k]){x=j;j=k;k=x;}
		a=X[k];b=n+1-a;
		x=((a*(llu)(a-1))>>1)*(llu)b;
		x+=((b*(llu)(b-1))>>1)*(llu)a;
		N[i]=x;
		r+=(d)x*(d)l;
	}
	w=(d)(n+1)*(d)(n)*(d)(n-1)/12.0;
	for(scanf("%u",&m);m--;)
	{
		scanf("%u%u",&i,&l);--i;
		r=r+l*(d)N[i]-E[i][2]*(d)N[i];
		E[i][2]=l;
		printf("%lf\n",r/w);
	}
	return 0;
}