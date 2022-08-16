#include<stdio.h>
#include<string.h>
#define m 1000000007u
#define lim 101101
typedef unsigned u;
u b[lim],Pl,Tl,D[lim],S[lim];
char P[lim], T[lim];
int main()
{
	scanf("%s%s",T,P);
	Pl=strlen(P);Tl=strlen(T);
	u i=0,j=-1,k,Fx;b[0]=-1;
	while(i<Pl)
	{
		while(j!=-1&&P[j]!=P[i])j=b[j];
		b[++i]=++j;
	}
	i=j=Fx=0;
	while(i<Tl)
	{
		while(j!=-1&&P[j]!=T[i])j=b[j];
		++i;++j;
		if(j==Pl)
		{
			D[i]=i-j+1;
			if(i)
			{
				if((D[i]+=S[i-j])>=m)D[i]-=m;
				Fx=D[i];
				if((D[i]+=D[i-1])>=m)D[i]-=m;
			}
			S[i]=S[i-1]+D[i];
			if(S[i]>=m)S[i]-=m;
			j=b[j];
		}
		else if(i)
		{
			D[i]=D[i-1]+Fx;
			if(D[i]>=m)D[i]-=m;
			S[i]=S[i-1]+D[i];
			if(S[i]>=m)S[i]-=m;
		}
	}
	printf("%u\n",D[Tl]);
	return 0;
}