#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll mod = 1e9+7;
ll n,k,pri[50],cnt[50],pn = 0,sminv[100010],dp[10010][55][55] = {0},ans = 0;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;y=0;return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
ll inv(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll mul(ll a,ll b){
	return a*b%mod;
}
ll add(ll a,ll b){
	return a+b>=mod?a+b-mod:a+b;
}
void dfs(ll n,ll dep,ll psb){
	if(dep == pn){
		//cout<<n<<' '<<psb<<endl;
		ans=add(ans,mul(n%mod,psb));
		return;
	}
	for(int i=0;i<=cnt[dep];i++){
		dfs(n,dep+1,mul(psb,dp[k][cnt[dep]][i]));
		n*=pri[dep];
	}
}
int main() {
	read(n);read(k);
	ll cn = n;
	for(ll i = 2;i*i<=cn;i++){
		if(cn%i == 0){
			pri[pn] = i;
			while(cn%i == 0){
				cn/=i;
				++cnt[pn];
			}
			++pn;
		}
	}
	if(cn!=1){
		pri[pn] = cn;cnt[pn] = 1;pn++;
	}
	for(int i=0;i<100000;i++)sminv[i] = inv(i);
	for(int i=1;i<=50;i++)dp[0][i][i] = 1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=50;j++){
			for(int kk=j;kk>=0;kk--){
				dp[i][j][kk] = add(dp[i][j][kk+1],mul(dp[i-1][j][kk],sminv[kk+1]));
			}
		}
	}
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}