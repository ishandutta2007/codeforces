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

struct pov{
	int x,y,val;
	bool operator < (const pov &rhs) const{
		return val<rhs.val;
	}
};

pov b[1000010];
int cmx[1000010],crx[1000010],cmy[1000010],cry[1000010],n,m;
vector< pov > vp,ep[1000010];
vector<int> ans[1000010],lk[1000010],G[1000010];
int vis[1000010];

int main() {
	read(n);read(m);
	for(int i=0;i<n;i++){
		ans[i].resize(m);
		ep[i].resize(m);
		for(int j=0;j<m;j++){
			ep[i][j].x = i;ep[i][j].y = j;
			read(ep[i][j].val);
			vp.push_back(ep[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[j] = ep[i][j];
		}
		sort(b,b+m);
		for(int j=0;j<m-1;j++){
			if(b[j].val == b[j+1].val){
				G[b[j].x*m+b[j].y].push_back(b[j+1].x*m+b[j+1].y);
				G[b[j+1].x*m+b[j+1].y].push_back(b[j].x*m+b[j].y);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			b[j] = ep[j][i];
		}
		sort(b,b+n);
		for(int j=0;j<n-1;j++){
			if(b[j].val == b[j+1].val){
				G[b[j].x*m+b[j].y].push_back(b[j+1].x*m+b[j+1].y);
				G[b[j+1].x*m+b[j+1].y].push_back(b[j].x*m+b[j].y);
			}
		}
	}
	sort(vp.begin(),vp.end());
	for(auto ech:vp){
		if(ans[ech.x][ech.y])continue;
		queue<int> Q;
		
		int cux = 0;
		Q.push(ech.x*m+ech.y);
		int cu = 1;
		while(!Q.empty()){
			int num = Q.front();
			pov cp = ep[Q.front()/m][Q.front()%m];Q.pop();
			cux = max(cux,cmx[cp.x]+1);
			cux = max(cux,cmy[cp.y]+1);
			for(auto ct:G[num])if(vis[ct]!=cu){
				vis[ct] = cu;
				Q.push(ct);
			}
		}
		cu = 2;
		Q.push(ech.x*m+ech.y);
		
		while(!Q.empty()){
			int num = Q.front();
			pov cp = ep[Q.front()/m][Q.front()%m];Q.pop();
			ans[cp.x][cp.y] = cux;
			cmy[cp.y] = ans[cp.x][cp.y];
			cmx[cp.x] = ans[cp.x][cp.y];
			for(auto ct:G[num])if(vis[ct]!=cu){
				vis[ct] = cu;
				Q.push(ct);
			}
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}