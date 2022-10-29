#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 200010;

struct edge{
	int x,y,d;
}e[N];
int fa[N],n,m,x,y,z,i,j;

int findset(int x){return x==fa[x]?x:(fa[x]=findset(fa[x]));}

bool cmp(edge x, edge y){return x.d<y.d;}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&x,&y,&z);
		e[i]={x,y,z};
	}
	sort(e+1,e+m+1,cmp);
	int ans=0;
	rep(i,1,n)fa[i]=i;
	for(i=1;i<=m;){
		for(j=i;i<=m&&e[j].d==e[i].d;++i);
		int cnt1=0,cnt2=0;
		rep(k,j,i-1)if(findset(e[k].x)!=findset(e[k].y))++cnt1;
		rep(k,j,i-1)if(findset(e[k].x)!=findset(e[k].y)){
			fa[findset(e[k].y)]=findset(e[k].x);
			++cnt2;
		}
		ans+=cnt1-cnt2;
	}
	cout<<ans<<endl;
	return 0;
}