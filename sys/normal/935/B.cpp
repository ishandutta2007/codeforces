#include <bits/stdc++.h>
using namespace std;
int x,cost;
string mov;
struct pnt
{
	int x,y,now;
}fa;
int main()
{
	scanf("%d",&x);
	getchar();
	cin>>mov;
	if(mov[0]=='U')
		fa.y++;
	if(mov[0]=='R')
		fa.x++,fa.now=1;
	for(int i=1;i<x;i++)
	{
		if(mov[i]=='U')
			fa.y++;
		if(mov[i]=='R')
			fa.x++;
		if((fa.x>fa.y)&&(!fa.now)){cost++;fa.now=1;}
		else if((fa.y>fa.x)&&fa.now){cost++;fa.now=0;}
	}
	printf("%d",cost);
	return 0;
}