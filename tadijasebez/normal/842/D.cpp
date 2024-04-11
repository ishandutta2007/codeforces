#include <stdio.h>
const int N=1000050;
int time;
int v[N],ls[N],rs[N];
void Set(int &x, int num, int p)
{
	if(!x) x=++time;
	v[x]++;
	if(p<0) return;
	if(num & (1<<p)) Set(rs[x],num,p-1);
	else Set(ls[x],num,p-1);
}
int sol;
void Find(int x, int num, int p)
{
	if(p<0) return;
	if(num & (1<<p))
	{
		if(v[rs[x]]<(1<<p))
		{
			Find(rs[x],num,p-1);
		}
		else
		{
			sol|=1<<p;
			Find(ls[x],num,p-1);
		}
	}
	else
	{
		if(v[ls[x]]<(1<<p))
		{
			Find(ls[x],num,p-1);
		}
		else
		{
			sol|=1<<p;
			Find(rs[x],num,p-1);
		}
	}
}
bool used[N];
int main()
{
	int x,n,q,i,j,r=0;
	scanf("%i%i",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%i",&j);
		if(!used[j]) Set(r,j,19);
		used[j]=true;
	}
	x=0;
	while(q--)
	{
		scanf("%i",&j);
		x^=j;
		sol=0;
		Find(r,x,19);
		printf("%i\n",sol);
	}
	return 0;
}