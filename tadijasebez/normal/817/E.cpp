#include <stdio.h>
const int N=100050;
const int L=28;
const int M=L*N;
int x[M],go[M][2],clock,root;
void Set(int &c, int lvl, int X, int f)
{
	if(!c) c=++clock;
	x[c]+=f;
	//printf("%i ",x[c]);
	if(!(~lvl)) return;
	Set(go[c][(X>>lvl)&1],lvl-1,X,f);
}
int A,sol;
void Get(int c, int lvl, int X, int l)
{
	if(!(~lvl)) return;
	int g=((X>>lvl)&1)^1;
	//printf("%i %i ",lvl,g);
	if(x[go[c][g]])
	{
		A+=1<<lvl;
		//printf("%i %i\n",A,x[go[c][g]]);
		if(A>=l)
		{
			//printf(":D");
			sol+=x[go[c][g]];
			A-=1<<lvl;
			//printf("\n");
			Get(go[c][g^1],lvl-1,X,l);
		}
		else
		{
			//printf("\n");
			Get(go[c][g],lvl-1,X,l);
		}
	}
	else
	{
		//printf("\n");
		Get(go[c][g^1],lvl-1,X,l);
	}
}
int main()
{
	int n,p,l,t,m=0;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i",&p),Set(root,L,p,1),m++;
		if(t==2) scanf("%i",&p),Set(root,L,p,-1),m--;
		if(t==3)
		{
			scanf("%i %i",&p,&l);
			A=0;
			sol=0;
			Get(root,L,p,l);
			printf("%i\n",m-sol);
		}
	}
	return 0;
}