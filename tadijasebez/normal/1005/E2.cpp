#include <stdio.h>
#define ll long long
const int N=200050;
const int M=2*N;
int cnt[M],a[N];
void Init(){ for(int i=0;i<M;i++) cnt[i]=0;}
void Set(int i){ for(;i<M;i+=i&-i) cnt[i]++;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=cnt[i];return ret;}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	Set(N);
	int sum=0;
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]<m) sum--;
		else sum++;
		ans+=Get(N+sum-1);
		//printf("%i ",Get(N+sum-1));
		Set(N+sum);
	}
	//printf("\n");
	sum=0;
	Init();
	Set(N);
	for(i=1;i<=n;i++)
	{
		if(a[i]<=m) sum--;
		else sum++;
		ans-=Get(N+sum-1);
		//printf("%i ",Get(N+sum-1));
		Set(N+sum);
	}
	//printf("\n");
	printf("%lld\n",ans);
	return 0;
}