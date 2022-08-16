#include"stdio.h"
#include"set"
using namespace std;
set<char> solution;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char A[n][m+1];
	int horizontal[n][m],vertical[n][m];
	for(int x=0;x<n;x++)
	{
		scanf("%s",A[x]);
		horizontal[x][0]=(A[x][0]=='#');
		for(int y=1;y<m;y++)
		{
			horizontal[x][y]=horizontal[x][y-1]+(A[x][y]=='#');
		}
	}
	for(int x=0;x<m;x++)
	{
		vertical[0][x]=(A[0][x]=='#');
		for(int y=1;y<n;y++)
		{
			vertical[y][x]=vertical[y-1][x]+(A[y][x]=='#');
		}
	}
	int k;
	scanf("%d",&k);
	char drn[k][5];int len[k];
	for(int x=0;x<k;x++)
	{
		scanf("%s%d",drn[x],&len[x]);
	}
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<m;y++)
		if(A[x][y]>='A'&&A[x][y]<='Z')
		{
			int x0=x,y0=y;
			bool ss=true;
			for(int t=0;t<k&&ss;t++)
			{
				int xp,yp;
				switch(drn[t][0])
				{
					case 'N':
						xp=x0-len[t],yp=y0;
						if(xp<=0)ss=false;
						else ss=(vertical[x0][y0]==vertical[xp-1][yp]);
						x0=xp;y0=yp;
						break;
					case 'S':
						xp=x0+len[t],yp=y0;
						if(xp>=n)ss=false;
						else ss=(vertical[x0-1][y0]==vertical[xp][yp]);
						x0=xp;y0=yp;
						break;
					case 'E':
						xp=x0,yp=y0+len[t];
						if(yp>=m)ss=false;
						else ss=(horizontal[x0][y0-1]==horizontal[xp][yp]);
						x0=xp;y0=yp;
						break;
					case 'W':
						xp=x0,yp=y0-len[t];
						if(yp<=0)ss=false;
						else ss=(horizontal[x0][y0]==horizontal[xp][yp-1]);
						x0=xp;y0=yp;
						break;
				}
//				if(!ss)
//					printf("%c %d",A[x][y],t);
			}
			if(ss)solution.insert(A[x][y]);
		}
	}
	if(solution.size()>0)
		for(set<char>::iterator it=solution.begin();it!=solution.end();it++)
			printf("%c",*it);
	else printf("no solution");
	
}