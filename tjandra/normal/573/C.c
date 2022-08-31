#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u *G[111111],Gi[111111],Ga[111111],F[111111],Q[111111],Qi;
void add(u i,u j)
{
	if(Gi[i]==Ga[i])
	{
		if(!Ga[i])G[i]=(u*)calloc(Ga[i]=4,sizeof(u));
		else G[i]=(u*)realloc(G[i],(Ga[i]<<=1)*sizeof(u));
	}
	G[i][Gi[i]++]=j;
	return;
}
u D(u n,u p,u dg)
{
	u x=0,i,j;
	for(i=Gi[n];i--;)
	if((j=G[n][i])!=p)x+=D(j,n,dg||Gi[n]>2);
	if(x+dg>2)Q[Qi++]=n;F[n]=x+dg;
	return Gi[n]>2||x>0;
}
int main()
{
	u i,j,n,q,a,b,ok=1,bad;
	scanf("%u",&n);
	for(q=n;--q;)
	{
		scanf("%u%u",&a,&b);
		add(a,b);add(b,a);
	}
	for(i=0;++i<=n;)if(Gi[i]>2)
	{
		D(i,-1,0);ok=0;
		break;
	}
	if(ok||!Qi){printf("Yes\n");return 0;}
	while(Qi--)
	{
		bad=F[q=Q[Qi]];
		for(i=Gi[q];i--;)
		{
			j=G[q][i];
			if(Gi[j]==3&&F[j]==1)--bad;
		}
		if(bad>2)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}