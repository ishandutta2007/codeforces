#include<bits/stdc++.h>
using namespace std;
const int px[]={0,1,1,1,0,-1,-1,-1};
const int py[]={1,1,0,-1,-1,-1,0,1};
int n,omg[310][310],use[8][310][310],ans,i,cnt,ln,x,X,Y,Z,j;
int qx[800010],qy[800010],qz[800010],Qx[800010],Qy[800010],Qz[800010]; 
int main()
{
	scanf("%d",&n);
	omg[150][150]=1;
	qx[cnt=1]=150;qy[1]=150;qz[1]=0;
	for(int _=1;_<=n;_++)
	{
		scanf("%d",&x);
		memset(use,0,sizeof(use));
		for(i=1;i<=cnt;i++)
		{
			Z=(qz[i]+7)%8;
			X=qx[i]+px[Z];
			Y=qy[i]+py[Z];
			if(_==1)Z=qz[i],X=qx[i],Y=qy[i];
			if(!use[Z][X][Y])
			{
				use[Z][X][Y]=1;
				omg[X][Y]=1;
				for(j=2;j<=x;j++)
					X+=px[Z],Y+=py[Z],omg[X][Y]=1;
				Qx[++ln]=X;Qy[ln]=Y;Qz[ln]=Z;
			}
			Z=(qz[i]+1)%8;
			X=qx[i]+px[Z];
			Y=qy[i]+py[Z];
			if(_==1)Z=qz[i],X=qx[i],Y=qy[i];
			if(!use[Z][X][Y])
			{
				use[Z][X][Y]=1;
				omg[X][Y]=1;
				for(j=2;j<=x;j++)
					X+=px[Z],Y+=py[Z],omg[X][Y]=1;
				Qx[++ln]=X;Qy[ln]=Y;Qz[ln]=Z;
			}
		}
		cnt=ln;
		for(i=1;i<=cnt;i++)
			qx[i]=Qx[i],qy[i]=Qy[i],qz[i]=Qz[i];
		ln=0;
	}
	for(i=0;i<=300;i++)
		for(j=0;j<=300;j++)
			ans+=omg[i][j];
	printf("%d\n",ans);
}