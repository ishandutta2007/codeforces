#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500050;
const int mod=1e9+7;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
struct BIT
{
	int sum[N];
	void init(){ for(int i=0;i<N;i++) sum[i]=0;}
	BIT(){ init();}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]=add(sum[i],f);}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans=add(ans,sum[i]);return ans;}
	int Get(int l, int r){ return sub(Get(r),Get(l-1));}
} LS,RS;
int a[N],id[N];
int main()
{
	int n,j,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int x, int y){ return a[x]<a[y];});
	int ans=0;
	for(j=1;j<=n;j++)
	{
		i=id[j];
		ans=add(ans,mul(mul(i,n-i+1),a[i]));
		int ls=LS.Get(1,i);
		int rs=RS.Get(i,n);
		ans=add(ans,mul(mul(n-i+1,ls),a[i]));
		ans=add(ans,mul(mul(i,rs),a[i]));
		LS.Set(i,i);
		RS.Set(i,n-i+1);
	}
	printf("%i\n",ans);
	return 0;
}