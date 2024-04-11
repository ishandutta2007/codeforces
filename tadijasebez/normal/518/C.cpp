#include <stdio.h>
#define ll long long
const int N=100050;
void swap(int &a, int &b){int tmp=a;a=b;b=tmp;}
int Pos[N],Ord[N];
ll sol;
int main()
{
	int n,m,k,i,x;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&Ord[i]),Pos[Ord[i]]=i;
	while(m--)
	{
		scanf("%i",&x);
		sol+=(Pos[x]+k-1)/k;
		if(Pos[x]!=1)
		{
			int tmp=Pos[x];
			Pos[Ord[tmp-1]]++;
			Pos[x]--;
			swap(Ord[tmp],Ord[tmp-1]);
		}
	}
	printf("%lld\n",sol);
	return 0;
}