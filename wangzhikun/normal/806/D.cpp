#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,a[2020][2020];
ll dis[2020],vis[2020] = {0};
priority_queue< pii, vector<pii>, greater<pii> > Q;
int main() {
	read(n);
	ll cmin = 1e18;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			read(a[i][j]);
			a[j][i] = a[i][j];
			cmin = min(cmin,a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]-=cmin;
	for(int i=1;i<=n;i++){
		dis[i] = 1e18;
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i] = min(dis[i],1ll*a[i][j]*2);
		}
		Q.push(make_pair(dis[i],i));
	}
	while(!Q.empty()){
		pii cc = Q.top();Q.pop();
		if(vis[cc.second])continue;
		dis[cc.second] = cc.first;
		vis[cc.second] = 1;
		for(int i=1;i<=n;i++){
			if(!vis[i])Q.push(make_pair(cc.first+a[cc.second][i],i));
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dis[i]+cmin*(n-1)<<endl;
	}
	return 0;
}