#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 998244353;
const int N = 200010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,x;
LL pw10[25];
vector<LL> a[15];

LL f(int x,int k){
	LL b[15],m;
	rep(i,1,k){
		b[i]=x%10;
		x/=10;
	}
	LL res=0;
	rrep(i,k,1) res = res * 100 + b[i];
	return res % MOD;
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		int y=x,k=0;
		while(y){
			y/=10;
			++k;
		}
		a[k].PB(x);
	}
	pw10[0]=1;
	rep(i,1,19)pw10[i]=pw10[i-1]*10;
	LL ans = 0;
	rep(i,1,10)rep(j,i,10){
		LL szi = a[i].size(), szj = a[j].size();
		//number in a[j] is bigger
		for(auto x : a[i]){
			ans = (ans + f(x, i) * 11LL % MOD * szj % MOD) % MOD;
		}
		if(i<j){
			for(auto x : a[j]){
				ans = (ans + f(x, i) * 11LL % MOD * szi % MOD) % MOD;
				ans = (ans + (x - x % pw10[i]) % MOD * pw10[i] % MOD * 2 % MOD * szi % MOD) % MOD;
			}
		}
		//if(i<=2&&j<=2)cout<<i<<" "<<j<<" "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}