#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
typedef long long LL;
const int N = 3010;
 
int g[N][N],h[N][N],n,m,a,b,g0,x,y,z;
 
int main(){
	cin>>n>>m>>a>>b;
	cin>>g0>>x>>y>>z;
	rep(i,1,n)rep(j,1,m){
		g[i][j] = g0;
		g0 = (1ll*g0*x+y)%z;
	}
	rep(i,1,n){
		deque<int> que;
		rep(j,1,m){
			while(!que.empty()&&que.front()<j-b+1)que.pop_front();
			while(!que.empty()&&g[i][que.back()]>g[i][j])que.pop_back();
			que.PB(j);
			if(j>=b)h[i][j-b+1] = g[i][que.front()];
		}
	}
	LL ans = 0ll;
	rep(j,1,m-b+1){
		deque<int> que;
		rep(i,1,n){
			while(!que.empty()&&que.front()<i-a+1)que.pop_front();
			while(!que.empty()&&h[que.back()][j]>h[i][j])que.pop_back();
			que.PB(i);
			if(i>=a)ans += h[que.front()][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}