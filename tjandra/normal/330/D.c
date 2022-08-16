#include<stdio.h>
typedef unsigned u;
u M[1000][1000],i,j,k,x,y,Sx,Sy,Qx[5000],Qy[5000],Rx[5000],Ry[5000],Qi,Qj,r;
char O[1000][1000],c;
int main()
{
	u *Xa,*Ya,*Xb,*Yb,*Z;
	scanf("%u%u",&x,&y);
	for(i=0;i<x;i++)for(j=0;j<y;j++)
	{
		while((c=getchar())<=' ');
		if(c=='E'){*Qx=i;*Qy=j;}
		else if(c=='S'){Sx=i;Sy=j;}
		else if(c=='T')M[i][j]=0xffffffffu;
		else O[i][j]=c-'0';
	}
	Xa=Qx;Ya=Qy;Xb=Rx;Yb=Ry;
	for(Qi=k=1;Qi;k++)
	{
		for(Qj=0;Qi--;)
		{
			i=Xa[Qi]-1;j=Ya[Qi];
			if(i<x&&j<y&&M[i][j]==0){M[i][j]=k;Xb[Qj]=i;Yb[Qj++]=j;}
			i++;i++;
			if(i<x&&j<y&&M[i][j]==0){M[i][j]=k;Xb[Qj]=i;Yb[Qj++]=j;}
			i--;j--;
			if(i<x&&j<y&&M[i][j]==0){M[i][j]=k;Xb[Qj]=i;Yb[Qj++]=j;}
			j++;j++;
			if(i<x&&j<y&&M[i][j]==0){M[i][j]=k;Xb[Qj]=i;Yb[Qj++]=j;}
		}
		Qi=Qj;Qj=0;
		Z=Xa;Xa=Xb;Xb=Z;
		Z=Ya;Ya=Yb;Yb=Z;
	}
	k=M[Sx][Sy];
	for(i=0;i<x;i++)for(j=0;j<y;j++)if(M[i][j]!=0&&M[i][j]<=k)r+=O[i][j];
	printf("%u\n",r);
	return 0;
}