#include <bits/stdc++.h>
using namespace std;
bool ask(int x, int y)
{
	if(x==-1 || y==-1) return 0;
	printf("1 %i %i\n",x,y);
	fflush(stdout);
	char ch[5];
	scanf("%s",ch);
	return ch[0]=='T';
}
int Search(int bot, int top)
{
	if(top<bot) return -1;
	if(top==bot) return top;
	int mid=top+bot>>1;
	if(ask(mid,mid+1)) return Search(bot,mid);
	else return Search(mid+1,top);
}
int main()
{
	int n,i;
	scanf("%i%*i",&n);
	int x=Search(1,n);
	int y=Search(1,x-1);
	int z=Search(x+1,n);
	if(ask(y,x)) printf("2 %i %i\n",y,x);
	else printf("2 %i %i\n",x,z);
	fflush(stdout);
	return 0;
}