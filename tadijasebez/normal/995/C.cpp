#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
using namespace std;
#define ll long long
const int N=100050;
const ll goal=(ll)1500000*1500000;
struct Vector
{
	int x,y;
	Vector(){}
	ll sz(){ return (ll)x*x+(ll)y*y;}
	Vector operator + (Vector b) const
	{
		Vector c;
		c.x=x+b.x;
		c.y=y+b.y;
		return c;
	}
	Vector operator - (Vector b) const
	{
		Vector c;
		c.x=x-b.x;
		c.y=y-b.y;
		return c;
	}
} a[N];
bool operator < (Vector a, Vector b){ return a.sz()<=b.sz();}
int id[N],sol[N];
int main()
{
	srand(time(0));
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++) id[i]=i;
	while(1)
	{
		random_shuffle(id+1,id+1+n);
		Vector my;
		my.x=my.y=0;
		for(i=1;i<=n;i++)
		{
			if((my+a[id[i]])<(my-a[id[i]]))
			{
				my=my+a[id[i]];
				sol[id[i]]=1;
			}
			else my=my-a[id[i]],sol[id[i]]=-1;
		}
		if(my.sz()<=goal) break;
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}