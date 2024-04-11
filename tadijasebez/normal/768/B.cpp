#include <stdio.h>
#define ll long long
const int N=100050;
int a[N],sz,BIT[N];
void Init(){ for(int i=0;i<N;i++) BIT[i]=0;}
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int Get(int l, int r){ return Get(r)-Get(l-1);}
ll done,l,r;
void Recur(ll n, int lg)
{
	if(done+((ll)1<<lg)-1<l)
	{
		done+=((ll)1<<lg)-1;
		return;
	}
	if(sz>=N) return;
	if(n<2){ a[++sz]=n;Set(sz,n);return;}
	Recur(n/2,lg-1);
	if(sz>=N) return;
	if(done+1>=l){ a[++sz]=n&1;Set(sz,n&1);}
	done++;
	if(sz>=N) return;
	Recur(n/2,lg-1);
}
int main()
{
	ll n;int lg=0,j;
	scanf("%lld %lld %lld",&n,&l,&r);
	for(j=0;j<55;j++) if((n>>j)&1) lg=j+1;
	Recur(n,lg);
	printf("%i\n",Get(r-l+1));
	return 0;
}