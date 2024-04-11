#include <iostream>
#include <cstring>
using namespace std;
const int mod=998244353;
const int maxn=2e5+5;
long long p[maxn];
long long dp[maxn];
int c[maxn]; 
int a[maxn];
typedef long long ll;
ll quickmod(ll a,ll b)
{
    ll sum=1;
    while(b)
    {
        if(b&1)
            sum=(sum*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return sum;
}
ll inv(ll w){
	return quickmod(w,mod-2);
}
void init(){
	p[0]=1;
	for (int i=1;i<=maxn-5;i++)
		p[i]=(p[i-1]*i)%mod;
	for (int i=1;i<=maxn-5;i++)
		dp[i]=(p[i-1]*i%mod*(i-1)%mod*inv(2ll)%mod+dp[i-1]*i%mod)%mod;
}
int n;
ll ans;
int cnt;
void ADD(int x,int y)
{
   for(int i=x;i<=n;i+=i&(-i)  ){
      c[i]+=y;
   }
}
int sum(int x)
{
   int SUM=0;
   for(int i=x;i>=1;i-=i&(-i))
      SUM+=c[i];
   return SUM;
}
int s1[maxn],s2[maxn];
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) s1[i]=1,s2[i]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==-1) cnt++;
		else s1[a[i]]=0,s2[a[i]]=0;
	}
	for (int i=1;i<=n;i++)
		s1[i]+=s1[i-1];
	for (int i=n-1;i>=0;i--)
		s2[i]+=s2[i+1];
	ans=dp[cnt];
	ll k=0;
	for (int i=1;i<=n;i++){
		if (a[i]!=-1){
			k=(k+sum(n)-sum(a[i]))%mod;
			ADD(a[i],1);
		}
	}
	k=(k*p[cnt])%mod;
	ans=(ans+k)%mod;
	memset(c,0,sizeof(c));
	long long S=0;
	for (int i=1;i<=n;i++){
		if (a[i]==-1)
			ans=(ans+S*p[cnt-1]%mod)%mod;
		else
			S+=s1[a[i]];
	}
	S=0;
	for (int i=n;i>=1;i--){
		if (a[i]==-1)
			ans=(ans+S*p[cnt-1]%mod)%mod;
		else
			S+=s2[a[i]];
	}
//	ans=39;
	ans=ans*inv(p[cnt])%mod;
	printf("%lld",ans);
	//cout << 499122183ll*p[cnt]%mod << endl;
}