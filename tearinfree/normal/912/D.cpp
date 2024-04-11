#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long lli;
typedef unsigned long long llu;
typedef pair<lli, lli> pll;
const lli inf=1e15;

set<lli> vis;
const int dy[4]={1,-1,0,0},dx[4]={0,0,-1,1};

int main() {
	int n,m,r,k;
	scanf("%d%d%d%d",&n,&m,&r,&k);

	priority_queue<pll> que;
	for(lli i=(n+1)/2;i<=(n+2)/2;i++) {
		for(lli j=(m+1)/2;j<=(m+2)/2;j++) {
			lli rl=max(1ll,i-r+1), rr=min(n-r+1ll,i);
			lli cl=max(1ll,j-r+1), cr=min(m-r+1ll,j);

			lli nxt=i*m+j;
			vis.insert(nxt);
			que.push(pll((rr-rl+1)*(cr-cl+1),nxt));	
		}
	}
	
	lli nu=0;
	while(k--) {
		pll cur=que.top();que.pop();
		nu+=cur.first;
		lli y=cur.second/m, x=cur.second%m;
		for(int k=0;k<4;k++) {
			lli yy=y+dy[k], xx=x+dx[k];
			if(yy>=1 && xx>=1 && yy<=n && xx<=m) {
				lli nxt=yy*m+xx;
				lli rl=max(1ll,yy-r+1), rr=min(n-r+1ll,yy);
				lli cl=max(1ll,xx-r+1), cr=min(m-r+1ll,xx);
				lli cost=(rr-rl+1)*(cr-cl+1);
				if(vis.find(nxt)==vis.end()) {
					vis.insert(nxt);
					que.push(pll(cost,nxt));
				}
			}
		}
	}


	printf("%.12Lf\n",(long double)nu/( 1ll*(n-r+1)*(m-r+1) ));
	
	return 0;
}