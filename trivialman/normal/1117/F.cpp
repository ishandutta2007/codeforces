#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+5;
const LL INF = 1e16;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[N];
bool ok[1<<17], v[1<<17][17][17], a[20][20];
int n,p,dp[1<<17],cnt[20];

void rm(int mask,int a,int b){
	if(v[mask][a][b]) return;
	v[mask][a][b] = true;
	ok[mask] = false;
	int x=mask&(~(1<<a))&(~(1<<b)), y;
	for(;x;x-=y) y = x&-x, rm(mask-y,a,b);
}
int dfs(int mask,int num){
	if(!num) return 0;
	if(~dp[mask]) return dp[mask];
	dp[mask] = num;
	for(int x=mask,i;x;x-=(1<<i)){
		i = __builtin_ctz(x);
		if(ok[mask-(1<<i)]) dp[mask] = min(dp[mask], dfs(mask-(1<<i), num-cnt[i]));
	}
	return dp[mask];
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d\n",&n,&p);
	scanf("%s",s+1);
	rep(i,0,p-1)rep(j,0,p-1)scanf("%d",&a[i][j]);
	
	memset(ok,true,sizeof ok);
	memset(v,0,sizeof v);
	for(char ch='a';ch<='a'+p-1;++ch){
		int mask = -1;
		rep(i,1,n)
			if(s[i]==ch){
				int x = ch-'a';
				if(!a[x][x] && mask>=0) rm((1<<p)-1-mask,x,x);
				mask = 0;
			}else{
				if(mask<0)continue;
				int x = ch-'a', y=s[i]-'a';
				if(!(mask&(1<<y)) && !a[x][y]) rm((1<<p)-1-mask,x,y);
				mask |= 1<<y;
			}
	}
	memset(cnt,0,sizeof cnt);
	memset(dp,-1,sizeof dp);
	rep(i,1,n)cnt[s[i]-'a']++;
	dfs((1<<p)-1,n);
	cout<<dp[(1<<p)-1]<<endl;
	return 0;
}