#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int mod=998244353;
char a[N],b[N];
int cnt[N];
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ans=(ll)ans*x%mod;return ans;}
void add(int &x, int y){ x+=y;if(x>=mod) x-=mod;}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	scanf("%s",a+1);reverse(a+1,a+1+n);
	scanf("%s",b+1);reverse(b+1,b+1+m);
	for(int i=m;i>=1;i--) cnt[i]=cnt[i+1]+(b[i]=='1');
	int ans=0;
	for(int i=1;i<=n;i++) add(ans,(ll)(a[i]=='1')*pow(2,i-1)*cnt[i]%mod);
	printf("%i\n",ans);
	return 0;
}