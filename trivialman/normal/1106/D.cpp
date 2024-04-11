#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 100010;

vector<int> g[N];
int n,m,x,y;
bool v[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	priority_queue<int> a;
	a.push(-1);
	rep(i,1,n){
		while(!a.empty()&&v[-a.top()])a.pop();
		int x = -a.top();
		v[x] = true;
		printf("%d ",x);
		for(auto y:g[x])a.push(-y);
	}
	return 0;
}