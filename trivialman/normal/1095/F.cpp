#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

struct edge{
	LL x,y,w;
}e[N*2];
LL n,m;
LL a[N],fa[N];

LL findset(LL x){
	return (x==fa[x])?x:(fa[x]=findset(fa[x]));
}

bool cmp(edge x,edge y){return x.w<y.w;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%lld%lld",&n,&m);
	rep(i,1,n)fa[i]=i;
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,m){
		LL x,y,w;
		scanf("%lld%lld%lld",&x,&y,&w);
		e[i] = {x,y,w};
	}
	LL minw = 1e14, minpos = 0;
	rep(i,1,n)if(a[i]<minw){
		minw = a[i];
		minpos = i;
	}
	rep(i,1,n)if(i!=minpos){
		e[++m] = {minpos,i,a[i]+a[minpos]};
	}
	sort(e+1, e+m+1, cmp);
	LL ans = 0;
	rep(i,1,m){
		LL x=e[i].x, y=e[i].y, w=e[i].w;
		LL fax = findset(x), fay = findset(y);
		if(fax!=fay){
			ans += w;
			fa[fay] = fax;
		}
	}
	printf("%lld\n",ans);
	return 0;
}