#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MOD 998244353

int n,m,t,x,y;
int which[N],v[N],num[N],num0[N];
bool flag;
vector<int> g[N];

LL pw(LL x,int n){
	if(n==0)return 1;
	LL y = pw(x,n/2);
	y = (y*y)%MOD;
	return n%2?(x*y)%MOD:y;
}

void dfs(int x, int w, int &num, int &num0){
	if(!flag)return;
	v[x] = true;
	which[x] = w;
	++num; num0+=w;
	for(auto u:g[x]){
		if(v[u]&&which[x]==which[u]){
			flag = false; return;
		}
		if(!v[u]) dfs(u,1-w,num,num0);
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)which[i]=v[i]=num[i]=num0[i]=0;
	rep(i,1,n)g[i].clear();
	rep(i,1,m){
		scanf("%d%d",&x,&y); 
		g[x].push_back(y);
		g[y].push_back(x);
	}
	flag = true;
	rep(i,1,n)if(!v[i])dfs(i,0,num[i],num0[i]);
	if(!flag)printf("0\n");
	else{
		LL ans = 1;
		rep(i,1,n)if(num[i]){
			if(num[i]==1) ans = ans*3%MOD;
			else ans = ans*(pw(2,num[i]-num0[i])+pw(2,num0[i]))%MOD;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}