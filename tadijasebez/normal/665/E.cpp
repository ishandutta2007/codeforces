#include <stdio.h>
#define ll long long
const int N=1000050;
const int L=30;
const int M=N*L;
int x[M],go[M][2],clock,root;
void Set(int &c, int lvl, int X)
{
	if(!c) c=++clock;
	x[c]++;
	if(!(~lvl)) return;
	Set(go[c][(X>>lvl)&1],lvl-1,X);
}
int A,sol;
void Get(int &c, int lvl, int X, int k)
{
	if(!(~lvl)) return;
	int g=((X>>lvl)&1)^1;
	if(x[go[c][g]])
	{
		A+=((ll)1)<<lvl;
		if(A>=k)
		{
			A-=((ll)1)<<lvl;
			sol+=x[go[c][g]];
			Get(go[c][g^1],lvl-1,X,k);
		}
		else Get(go[c][g],lvl-1,X,k);
	}
	else Get(go[c][g^1],lvl-1,X,k);
}
int a[N];
ll ans;
int main()
{
	int n,i,k,mass=0;
	Set(root,L,0);
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		mass^=a[i];
		A=0;
		sol=0;
		Get(root,L,mass,k);
		ans+=sol;
		Set(root,L,mass);
	}
	printf("%lld\n",ans);
	return 0;
}