#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,w[300030],gi[300030],u,v,c,ans = 0;
vector<pll> G[300030];
void dfs(int num,int f = -1){
	ll ma = 0,sma = 0;
	for(auto cw:G[num]){
		if(cw.first == f)continue;
		dfs(cw.first,num);
		ll cc = gi[cw.first]-cw.second;
		if(cc>=sma){
			if(cc>=ma){
				sma = ma;
				ma = cc;
			}else{
				sma = cc;
			}
		}
	}
	gi[num] = ma+w[num];
	ans = max(ans,ma+sma+w[num]);
	ans = max(ans,gi[num]);
}
int main() {
	read(n);
	for(int i=1;i<=n;i++)read(w[i]);
	for(int i=1;i<n;i++){
		read(u);read(v);read(c);
		G[u].push_back(make_pair(v,c));
		G[v].push_back(make_pair(u,c));
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}