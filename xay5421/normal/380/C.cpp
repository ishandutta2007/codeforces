#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=4000005;
int n,m,ans,res[N],cnt[N][2];char s[N];
int get(char ch){return ch=='(';}
void upd(int u,int a,int b){
	int x=std::min(cnt[a][1],cnt[b][0]);
	res[u]=res[a]+res[b]+x;
	cnt[u][0]=cnt[a][0]+cnt[b][0]-x;
	cnt[u][1]=cnt[a][1]+cnt[b][1]-x;
}
void bud(int u,int l,int r){
	if(l==r){++cnt[u][get(s[l])];return;}int mid=l+r>>1;
	bud(u<<1,l,mid),bud(u<<1|1,mid+1,r),upd(u,u<<1,u<<1|1);
}
void qry(int u,int l,int r,int lx,int rx){
	if(l==lx&&r==rx){ans+=res[u],upd(0,0,u);return;}int mid=l+r>>1;
	if(rx<=mid)qry(u<<1,l,mid,lx,rx);else
	if(mid<lx)qry(u<<1|1,mid+1,r,lx,rx);else
		qry(u<<1,l,mid,lx,mid),qry(u<<1|1,mid+1,r,mid+1,rx);
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%d",&m);
	bud(1,1,n);
	for(int i=1,l,r;i<=m;++i){
		scanf("%d%d",&l,&r);
		res[0]=0,cnt[0][0]=cnt[0][1]=0;
		qry(1,1,n,l,r);
		printf("%d\n",res[0]*2);
	}
	return 0;
}