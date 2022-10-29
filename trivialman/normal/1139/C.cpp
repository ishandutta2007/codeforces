#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,x,y,c,cnt[N];
vector<int> g[N];
bool v[N];

int pw(LL x,int n){
	LL res = 1;
	for(;n;n>>=1,x=x*x%P)if(n&1)res=res*x%P;
	return res;
}

void dfs(int x,int &tot){
	v[x] = true;
	++tot;
	for(auto u:g[x])if(!v[u]){
		dfs(u,tot);
	}
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		scanf("%d%d%d",&x,&y,&c);
		if(c==0) g[x].PB(y), g[y].PB(x);
	}
	memset(v,false,sizeof v);
	rep(i,1,n)if(!v[i]){
		dfs(i,cnt[i]);
	}
	LL ans = 0;
	rep(i,1,n){
		ans = (ans + pw(cnt[i],k)) % P;
	}
	ans = (pw(n,k) - ans + P) % P;
	cout<<ans<<endl;
	return 0;
}