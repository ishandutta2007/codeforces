#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const LL P = 1e9+7;
const int N = 5005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,cnt=0,a[N],b[N],in[N];
vector<int> g[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",a+i,b+i);
		g[a[i]].push_back(b[i]), in[b[i]]++;
	}
	queue<int> Q;
	rep(i,1,n) if(!in[i]) Q.push(i);
	int cnt = 0;
	while(!Q.empty()){
		++cnt;
		int x = Q.front();
		Q.pop();
		for(auto u:g[x]){
			in[u]--;
			if(in[u]==0) Q.push(u);
		}
	}
	if(cnt==n){
		printf("1\n");
		rep(i,1,m)printf("1 ");
	}else{
		printf("2\n");
		rep(i,1,m)printf("%d ",a[i]<b[i]?1:2);
	}
	return 0;
}