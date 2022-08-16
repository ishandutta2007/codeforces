#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u N[200000],Tv[19][200000];
llu T[19][200000];
int main()
{
	u n,k,i,j,M,m,ansX,ansY;
	llu s,val,Mval;
	scanf("%u%u",&n,&k);
	for(i=0;i<n;scanf("%u",N+i++));
	for(s=i=0;i<k;s+=N[i++]);
	for(T[0][j=0]=s;i<n;T[0][j]=s,Tv[0][j]=j){s+=N[i++];s-=N[j++];}
	for(n=++j,i=1;i<19;i++)
	{
		M=1u<<i;m=M>>1;
		for(j=M;j<=n;j++)
		{
			if(T[i-1][j-m]>T[i-1][j-M])
			{
				T[i][j-M]=T[i-1][j-m];
				Tv[i][j-M]=Tv[i-1][j-m];
			}
			else
			{
				T[i][j-M]=T[i-1][j-M];
				Tv[i][j-M]=Tv[i-1][j-M];
			}
		}
	}
	m=0;M=1;Mval=0;
	while(M<=n-k){M<<=1;m++;}
	M>>=1;m--;
	for(i=k;i<n;i++)
	{
		if(M>n-i){M>>=1;m--;}
		val=T[0][i-k];
		if(T[m][n-M]>T[m][i])
		{
			val+=T[m][n-M];
			if(val>Mval)
			{
				Mval=val;
				ansX=i-k;ansY=Tv[m][n-M];
			}
		}
		else
		{
			val+=T[m][i];
			if(val>Mval)
			{
				Mval=val;
				ansX=i-k;ansY=Tv[m][i];
			}
		}
	}
	printf("%u %u\n",ansX+1,ansY+1);
	return 0;
}