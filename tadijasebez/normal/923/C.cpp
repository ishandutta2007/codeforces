#include <stdio.h>
const int N=300050;
const int M=31*N;
int x[M],go[M][2],tsz,root;
void Set(int &c, int X, int lvl)
{
	if(!c) c=++tsz;
	x[c]++;
	if(lvl<0) return;
	Set(go[c][(X>>lvl)&1],X,lvl-1);
}
int A;
void Get(int &c, int X, int lvl)
{
	x[c]--;
	if(lvl<0) return;
	int g=(X>>lvl)&1;
	if(x[go[c][g]]) Get(go[c][g],X,lvl-1);
	else A+=1<<lvl,Get(go[c][g^1],X,lvl-1);
}
int Get(int X){ A=0;Get(root,X,30);return A;}
int a[N],b[N];
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&x),Set(root,x,30);
	for(i=1;i<=n;i++) b[i]=Get(a[i]);
	for(i=1;i<=n;i++) printf("%i ",b[i]);
	return 0;
}