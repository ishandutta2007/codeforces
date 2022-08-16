#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
u V[512][512],Q[32][512][512],T[32];
u X[512*512*8],Y[512*512*8],*A,*B,*C;
u dx[8]={-1,-1, 0,+1,+1,+1, 0,-1};
u dy[8]={ 0,+1,+1,+1, 0,-1,-1,-1};
int main()
{
	u t,z,n,i=-1,j,k,p,q=1;
	for(scanf("%u",&n);++i<n;)scanf("%u",T+i);--*T;
	*(B=X)=256<<12|256<<3|0;A=Y;V[256][256]=1;
	for(z=-1;++z<n;)
	{
		C=A;A=B;B=C;
		for(p=q,q=0;p--;)
		{
			i=(A[p]>>12)&511;
			j=(A[p]>> 3)&511;
			k=A[p]&7;
			for(t=T[z];t--;)V[i+=dx[k]][j+=dy[k]]=1;
			t=(k+1)&7;tjan:;
			if(!((Q[z][i][j]>>t)&1))
			{
				Q[z][i][j]|=1u<<t;
				B[q++]=i<<12|j<<3|t;
			}
			if(t==((k+1)&7)){t=(k+7)&7;goto tjan;}
		}
	}
	for(k=0,i=-1;++i<512;)for(j=-1;++j<512;)if(V[i][j])++k;
	printf("%u\n",k);
	return 0;
}