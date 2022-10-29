#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int sz[N], group[N];
int n,x,y;
vector<int> g[N];

int center(int x,int fa){
	bool flag = true;
	sz[x] = 1;
	for(auto u:g[x])if(u!=fa){
		int y = center(u,x);
		if(y) return y;
		sz[x] += sz[u];
		if(sz[u]>n/2) flag = false;
	}
	if(n-sz[x]>n/2) flag = false;
	return flag ? x : 0;
}

void calcsz(int x,int fa){
	sz[x] = 1;
	for(auto u:g[x])if(u!=fa){
		calcsz(u, x);
		sz[x] += sz[u];
	}
}

void dfs(int x,int fa,int mul){
	int s = 1;
	for(auto u:g[x])if(u!=fa){
		printf("%d %d %d\n", x, u, s * mul);
		dfs(u, x, mul);
		s += sz[u];
	}
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	int rt = center(1,0);
	calcsz(rt, 0);
	
	vector<PII> tmp;
	int sum = 0, s1 = 0;
	for(auto u:g[rt]){
		tmp.PB({sz[u],u});
	} 
	sort(tmp.begin(),tmp.end());
	for(auto x:tmp){
		s1 += x.first;
		group[x.second] = 1;
		if(s1>=(n+1)/3)break;
	}
	//cout<<rt<<" "<<s1<<endl;
	//rep(i,1,n)cout<<sz[i]<<" ";cout<<endl;
	
	int t1 = 1, t2 = 1;
	for(auto u:g[rt]){
		//printf("group[%d]=%d\n",u,group[u]);
		if(group[u]){
			printf("%d %d %d\n", rt, u, t1);
			dfs(u, rt, 1);
			t1 += sz[u];
		}else{
			printf("%d %d %d\n", rt, u, t2 * (s1+1));
			dfs(u, rt, s1+1);
			t2 += sz[u];
		}
	}
	
	return 0;
}