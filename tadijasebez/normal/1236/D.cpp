#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
struct myset:set<int>{
	int nxt(int x){return *lower_bound(x);}
	int prv(int x){return *prev(upper_bound(x));}
}hor[N],ver[N];
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	ll need=(ll)n*m-k;
	for(int i=1,x,y;i<=k;i++)scanf("%i %i",&x,&y),hor[x].insert(y),ver[y].insert(x);
	for(int i=1;i<=n;i++)hor[i].insert(0),hor[i].insert(m+1);
	for(int i=1;i<=m;i++)ver[i].insert(0),ver[i].insert(n+1);
	int dir=0,xl=1,xr=n,yl=1,yr=m;
	while(xl<=xr && yl<=yr){
		if(dir==0){
			int t=min(yr,hor[xl].nxt(yl)-1);
			need-=t-yl+1;
			xl++;yr=t;
		}else if(dir==1){
			int t=min(xr,ver[yr].nxt(xl)-1);
			need-=t-xl+1;
			yr--;xr=t;
		}else if(dir==2){
			int t=max(yl,hor[xr].prv(yr)+1);
			need-=yr-t+1;
			xr--;yl=t;
		}else if(dir==3){
			int t=max(xl,ver[yl].prv(xr)+1);
			need-=xr-t+1;
			yl++;xl=t;
		}
		dir=(dir+1)%4;
	}
	if(need==0)printf("Yes\n");
	else printf("No\n");
	return 0;
}