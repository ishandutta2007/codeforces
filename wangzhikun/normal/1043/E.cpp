//  Created by WangZhikun on 2018/10/28.

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,m,ans[300030],x[300030],y[300030],u,v;
struct pp{
	ll id,x,y;
} ppl[300030];
ll sux = 0,suy = 0;
bool cmp(pp a,pp b){return a.x-a.y<b.x-b.y;}
int main() {
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(x[i]);read(y[i]);
		ppl[i].x = x[i];
		ppl[i].y = y[i];
		ppl[i].id = i;
		suy+=y[i];
	}
	sort(ppl+1,ppl+n+1,cmp);
	for(int i=1;i<=n;i++){
		suy-=ppl[i].y;
		ans[ppl[i].id] = ppl[i].y*(i-1)+sux+suy+ppl[i].x*(n-i);
		sux+=ppl[i].x;
	}
	for(int i=0;i<m;i++){
		read(u);read(v);
		ll cv = min(x[u]+y[v],x[v]+y[u]);
		ans[u]-=cv;
		ans[v]-=cv;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}