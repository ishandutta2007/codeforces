#include<cstdio>
#include<cstring>

using namespace std;

char ch[110];

int x[110],y[110];
int tx,ty;

int main()
{
	int gx,gy;
	scanf("%d%d",&gx,&gy);
	scanf("%s",ch);
	int ln=strlen(ch);
	x[0]=0,y[0]=0;
	for(int i=0;i<ln;i++)
	{
		if(ch[i]=='L')
		{
			x[i+1]=x[i]-1;
			y[i+1]=y[i];
		}
		else if(ch[i]=='R')
		{
			x[i+1]=x[i]+1;
			y[i+1]=y[i];
		}
		else if(ch[i]=='U')
		{
			x[i+1]=x[i];
			y[i+1]=y[i]+1;
		}
		else
		{
			x[i+1]=x[i];
			y[i+1]=y[i]-1;
		}
	}
	tx=x[ln],ty=y[ln];
//	for(int i=0;i<=ln;i++) printf("%d %d\n",x[i],y[i]);
	for(int i=0;i<ln;i++)
	{
		int dx=gx-x[i],dy=gy-y[i];
//		printf("%d %d\n",dx,dy);
//		printf("%d %d %d %d\n",dx%tx,dx/tx,dy%ty,dy/ty);
		bool x_ok=false,y_ok=false;
		int xx=-1,yy=-1;
		if(tx==0) {if(dx==0) x_ok=true;}
		else if((dx%tx)==0&&(dx/tx)>=0)
		{
			x_ok=true;
			xx=dx/tx;
		}
		if(ty==0) {if(dy==0) y_ok=true;}
		else if((dy%ty)==0&&(dy/ty)>=0)
		{
			y_ok=true;
			yy=dy/ty;
		}
		if(x_ok&&y_ok)
		{
	//		printf("%d %d %d\n",i,xx,yy);
			if(xx!=-1&&yy!=-1) if(xx!=yy) continue;
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}