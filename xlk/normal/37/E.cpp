#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,qx[20000],qy[20000],d[55][55],h,t,z;
char s[55][55];
bool b[55][55];
void ck(int x,int y)
{
	h=t=0;
	qx[t]=x,qy[t]=y;
	t++;
	memset(d,0x3f,sizeof d);
	d[x][y]=1;
	while(h<t)
	{
		x=qx[h],y=qy[h],h++;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m)
				continue;
			int nd=d[x][y]+(s[x][y]!=s[nx][ny]);
			if(nd<d[nx][ny])
			{
				d[nx][ny]=nd;
				qx[t]=nx,qy[t]=ny;
				t++;
			}
		}
	}
	int w=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='B')
				w=max(w,d[i][j]);
	z=min(z,w);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	z=0x3f3f3f3f;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ck(i,j);	
	printf("%d\n",z);
	return 0;
}