#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int L=45;
int cif[L],dig[L],lg,sz;
bool Check()
{
	int ret=0,i,j=1;
	for(i=1;i<=lg;i++)
	{
		bool done=0;
		for(;j<=sz;j++)
		{
			if(dig[i]==cif[j])
			{
				done=1;
				j++;
				break;
			}
		}
		//printf("%i ",j);
		if(!done) return 0;
	}
	return 1;
}
int sol=-1;
int main()
{
	int i,n,j,m;
	scanf("%i",&n);m=n;
	while(n) cif[++sz]=n%10,n/=10;
	//for(i=1;i<=sz;i++) printf("%i ",cif[i]);printf("\n");
	for(i=1;i*i<=m;i++)
	{
		n=i*i;
		lg=0;
		while(n) dig[++lg]=n%10,n/=10;
		//for(j=1;j<=lg;j++) printf("%i ",dig[j]);printf("\n");
		//if(i==9)
		//{
			//printf("9\n");
			//printf("%i\n",Check());
			//printf("\n");
		//}
		if(Check())
		{
			if(sol==-1 || sol>sz-lg)
			{
				sol=sz-lg;
				//printf("%i %i\n",i*i,sz-lg);
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}