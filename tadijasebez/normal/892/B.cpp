#include <stdio.h>
const int N=1000500;
int BIT[N],x[N];
void Set(int i){ for(;i<N;i+=i&-i) BIT[i]++;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,sol=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	for(i=n;i;i--)
	{	
		if(!Get(i)) sol++;
		Set(max(i-x[i],1));
	}
	printf("%i\n",sol);
	return 0;
}