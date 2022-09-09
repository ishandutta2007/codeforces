#include <stdio.h>
const int N=2050;
char ch[N][N];
void work(int x, int y)
{
	int i,j,cnt=0;
	for(i=0;i<2;i++) for(j=0;j<2;j++) cnt+=ch[x+i][y+j]=='.';
	if(cnt==3)
	{
		for(i=0;i<2;i++) for(j=0;j<2;j++) ch[x+i][y+j]='.';
		for(i=-1;i<2;i++) for(j=-1;j<2;j++) work(x+i,y+j);
	}
}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(i=1;i<n;i++) for(j=1;j<m;j++) work(i,j);
	for(i=1;i<=n;i++) printf("%s\n",ch[i]+1);
	return 0;
}