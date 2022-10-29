#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int M = 40;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, m, k, ans[M];
LL x, mask, len, a[M];
vector<int> dp[M][M];

int pw(int x, int n){
	int res = 1;
	for(;n;n>>=1,x=1ll*x*x%P) if(n&1) res=1ll*res*x%P;
	return res;
}

void insert(LL x){
	rrep(i,m-1,0) if(x>>i&1) {
		if(a[i]==0){
			a[i] = x;
			rep(j,0,i-1) if(a[i]>>j&1) a[i] ^= a[j];
			rep(j,i+1,m-1) if(a[j]>>i&1) a[j] ^= a[i];
			break;
		}else x ^= a[i];
	}
}

void dfs(int m, LL x){
	while(m>=0 && !a[m]) m--;
	if(m==-1){
		ans[__builtin_popcountll(x)]++;
		return;
	}
	dfs(m-1, x);
	dfs(m-1, x^a[m]);
}

inline LL f(LL x, LL mask){
	x &= mask;
	LL res = 0, j = 0;
	rep(i,0,m-1) if(mask>>i&1){
		if(x>>i&1) res += 1ll<<j;
		j++;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%lld",&x);
		insert(x);
	}
	
	rep(i,0,m-1) k += (a[i]>0);
	if(k<=21){
		dfs(m-1, 0);
		rep(i,0,m) cout<<1ll*ans[i]*pw(2,n-k)%P<<" ";
	}else{
		k = 0, mask = 0;
		rep(i,0,m-1) if(!a[i]) mask |= (1<<i);
		reverse(a, a+m+1);
		rep(i,1,m) if(a[i]) a[++k] = a[i];
		len = 1<<m-k;
		dp[0][0].assign(len, 0), dp[0][0][0] = 1;
		rep(i,1,k)rep(j,0,i){
			dp[i][j].assign(len, 0);
			int z = f(a[i], mask);
			rep(s,0,len-1){
				int x = j<i ? dp[i-1][j][s] : 0, y = j>0 ? dp[i-1][j-1][s^z] : 0;
				dp[i][j][s] = (x + y)%P;
			}
		}
		rep(j,0,k) rep(s,0,len-1) (ans[j+__builtin_popcountll(s)] += dp[k][j][s]) %= P;
		rep(i,0,m) cout<<1ll*ans[i]*pw(2,n-k)%P<<" ";
	}
	return 0;
}