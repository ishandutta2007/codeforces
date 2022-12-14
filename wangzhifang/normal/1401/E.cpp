#include <cstdio>
#include <algorithm>
using namespace std;
#define max_v 1000000
struct node{
	int x,l,r;
	friend bool operator<(const node&a,const node&b){
		return a.x<b.x;
	}
};
node a[max_v+7],b[max_v+7];
int bit[max_v+7];
void add(int x,int v){
	for(; x<=max_v+1; x+=x&-x)
		bit[x]+=v;
}
int sum(int x,int res=0){
	for(; x; x&=x-1)
		res+=bit[x];
	return res;
}
int main(){
	int cntm=0,cntq=0,nowq,nowm,n,m;
	long long ans=1;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w; i<=n; ++i){
		scanf("%d%d%d",&u,&v,&w);
		if(v==0&&w==max_v)
			++ans;
		++u,++v,++w;
		a[++cntm]=node{v-1,1,u};
		a[++cntm]=node{w,-1,u};
	}
	sort(a+1,a+cntm+1);
	for(int i=1,u,v,w; i<=m; ++i){
		scanf("%d%d%d",&u,&v,&w);
		if(v==0&&w==max_v)
			++ans;
		++u,++v,++w;
		b[++cntq]=node{u,v,w};
	}
	sort(b+1,b+cntq+1);
	nowq=1,nowm=1;
	for(int j=0; j<=max_v+1; ++j){
		for(; nowq<=cntq&&j==b[nowq].x; ++nowq)
			ans+=sum(b[nowq].r)-sum(b[nowq].l-1);
		for(; nowm<=cntm&&j==a[nowm].x; ++nowm)
			add(a[nowm].r,a[nowm].l);
	}
	printf("%lld\n",ans);
	return 0;
}