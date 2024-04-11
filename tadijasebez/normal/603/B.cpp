#include <stdio.h>
#define ll long long
const int N=1000050;
const int mod=1e9+7;
int k,p;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
bool was[N];
void DFS(int x)
{
	if(was[x]) return;
	was[x]=1;
	DFS((ll)x*k%p);
}
int main()
{
	int i;
	scanf("%i %i",&p,&k);
	if(k==0) return printf("%i\n",pow(p,p-1)),0;
	if(k==1) return printf("%i\n",pow(p,p)),0;
	int cnt=0;
	for(i=1;i<p;i++) if(!was[i]) cnt++,DFS(i);
	printf("%i\n",pow(p,cnt));
	return 0;
}