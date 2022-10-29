#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int T, n, a, b, x, y, len;
int dep[N], maxd[N], fa[N], upa[N], upb[N];
vector<int> g[N];

struct dat{
	array<int, 4> a;
	void ins(int x){
		int i;
		for(i=2; i>=0 && x>a[i]; i--)
			a[i+1] = a[i];
		a[++i] = x;
	}
	void print(int i){cout<<i<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;}
}dp[N];

void calD(int x, int fa){
	for(auto u:g[x]) if(u!=fa){
		calD(u, x);
		dp[x].ins(dp[u].a[0]+1);
	}
}
void calU(int x, int fa, int d){
	if (x==b) len = d;
	for(auto u:g[x]) if(u!=fa){
		if(dp[u].a[0]+1 != dp[x].a[0])
			dp[u].ins(dp[x].a[0]+1);
		else
			dp[u].ins(dp[x].a[1]+1);
		calU(u, x, d+1);
	}
}

void dfs(int x, int fa_){
	maxd[x] = dep[x] = dep[fa_] + 1;
	fa[x] = fa_;
	for(auto u:g[x]) if(u!=fa_){
		dfs(u, x);
		maxd[x] = max(maxd[x], maxd[u]);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		rep(i,1,n) g[i].clear(), dp[i].a.fill(0);
		
		rep(i,1,n-1){
			scanf("%d%d",&x,&y);
			g[x].PB(y),g[y].PB(x);
		}
		calD(a,0), calU(a,0,1);
		
		int rt = 0;
		rep(i,1,n) if(dp[i].a[2]>=len-1) rt = i;
		if (!rt) {
			printf("NO\n");
			continue;
		}
		
		dep[0] = 0, dfs(rt, 0);
		int na = 0, nb = 0, idSame = 1;
		while (a) upa[++na] = a, a = fa[a];
		a = upa[1], reverse(upa+1, upa+na+1);
		while (b) upb[++nb] = b, b = fa[b];
		b = upb[1], reverse(upb+1, upb+nb+1);
		while(upa[idSame]==upb[idSame]) idSame++;
		idSame--;
		
		//rep(i,1,na) cout<<upa[i]<<" ";cout<<endl;
		//rep(i,1,nb) cout<<upb[i]<<" ";cout<<endl;
		int da = dep[a], db = dep[b], lastb = b;
		while(1){
			da -= maxd[b] - db, db = maxd[b], a = upa[da];
			if (da <= idSame) break;
			db -= maxd[a] - da, da = maxd[a], b = upb[db];
			if (db <= idSame) break;
			if (lastb == b) break;
			lastb = b;
		}
		
		cout<<(min(da,db) > idSame ? "NO\n" : "YES\n");
	}
	return 0;
}