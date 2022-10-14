//  Created by  on 2018/8/18.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,co[200020],nxt[200020],vis[200020] = {0};
vector<int> hs;
void dfs(int num,int col){
	vis[num] = col;
	if(vis[nxt[num]] == col){
		hs.push_back(nxt[num]);
	}
	if(!vis[nxt[num]]){
		dfs(nxt[num],col);
	}
}
int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(co[i]);
	}
	for(int i=1;i<=n;i++){
		read(nxt[i]);
	}
	int cnt = 1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,cnt);
			cnt+=1;
		}
	}
	ll ans = 0;
	for(int i=0;i<hs.size();i++){
		ll cco = co[hs[i]],p = nxt[hs[i]];
		while(p!=hs[i]){
			cco = min(cco,co[p]);
			p = nxt[p];
		}
		ans+=cco;
	}
	cout<<ans<<endl;
	return 0;
}