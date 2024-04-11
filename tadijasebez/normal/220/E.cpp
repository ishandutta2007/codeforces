#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
struct BIT
{
	int sum[N];
	void Init(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
	int Get(int r, int l){ return Get(r)-Get(l-1);}
} L,R,T;
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int a[N];
int main()
{
	int n,i,j;ll k;
	scanf("%i %lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.pb(a[i]);
	sort(id.begin(),id.end());
	id.resize(unique(id.begin(),id.end())-id.begin());
	for(i=1;i<=n;i++) a[i]=Find(a[i]);
	ll sol=0;
	for(i=2;i<=n;i++) R.Set(a[i],1);
	ll inv=0;
	int sz=id.size();
	for(i=1;i<=n;i++) inv+=T.Get(sz,a[i]+1),T.Set(a[i],1);
	//printf("inv:%i\n",inv);
	j=2;
	for(i=1;i<=n;i++)
	{
		if(j==i)
		{
			inv-=L.Get(sz,a[j]+1);
			inv-=R.Get(a[j],1);
			R.Set(a[j],-1);
			j++;
		}
		if(i!=1)
		{
			inv+=L.Get(sz,a[i]+1);
			inv+=R.Get(a[i]-1,1);
		}
		L.Set(a[i],1);
		for(;j<=n && inv>k;j++)
		{
			inv-=L.Get(sz,a[j]+1);
			inv-=R.Get(a[j]-1,1);
			R.Set(a[j],-1);
			//printf("%i %i %i\n",i,j,inv);
		}
		if(j>n) break;
		//printf("%i %i\n",i,j);
		sol+=n-j+1;
	}
	printf("%lld\n",sol);
	return 0;
}