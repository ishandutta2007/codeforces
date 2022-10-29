#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int INF = 1e9;
const int N = 5005;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, m, n1, n2, n3, s1, s2, x, y, j, cnt=0;
array<int, 3> node[N];
char ans[N];
bool dp[N][N];
vector<int> g[N];

void ans_no(){
	printf("NO");
	exit(0);
}

void dfs(int x, int grp){
	ans[x] = grp;
	grp==1 ? ++s1 : ++s2;
	for(auto u:g[x]) 
		if(!ans[u]) dfs(u, 3-grp);
		else if(ans[u]==grp) ans_no();
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>n>>m>>n1>>n2>>n3;
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	memset(ans,0,sizeof ans);
	memset(dp,0,sizeof dp);
	dp[0][0] = true;
	
	rep(i,1,n) if(!ans[i]) {
		s1 = s2 = 0;
		dfs(i, 1);
		node[++cnt] = {i,s1,s2};
		rep(j,0,n){
			if(j>=s1 && dp[cnt-1][j-s1]) dp[cnt][j] = true;
			if(j>=s2 && dp[cnt-1][j-s2]) dp[cnt][j] = true;
		}
	}
	
	if(!dp[cnt][n2]) ans_no();
	
	memset(ans,0,sizeof ans);
	rrep(i,cnt,1){
		j = node[i][0], s1 = node[i][1], s2 = node[i][2];
		if(n2>=s1 && dp[i-1][n2-s1]){
			n2 -= s1; dfs(j, 2);
		}else{
			n2 -= s2; dfs(j, 1);
		}
	}
	
	cout<<"YES\n";
	rep(i,1,n) if(ans[i]==1 && n3) {
		ans[i] = 3, --n3;
	}
	
	rep(i,1,n) ans[i]+='0';
	cout<<(ans+1);
	return 0;
}