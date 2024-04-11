#include <stdio.h>
#include <map>
using namespace std;
const int M=1e9;
map<int, map<int,int> > BIT;
void Set(int x, int t, int v)
{
	for(;t<=M;t+=t&-t) BIT[x][t]+=v;
}
int Get(int x, int t)
{
	int ret=0;
	for(;t;t-=t&-t) ret+=BIT[x][t];
	return ret;
}
int main()
{
	int n,a,t,x;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i %i",&a,&t,&x);
		if(a==1) Set(x,t,1);
		if(a==2) Set(x,t,-1);
		if(a==3) printf("%i\n",Get(x,t));
	}
	return 0;
}