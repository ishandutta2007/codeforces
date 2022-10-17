#include<stdio.h>
#include<algorithm>
#define lc(x) (x)<<1
#define rc(x) (x)<<1|1
using namespace std;
const int maxn=300005,maxt=4000005;
int n,m,ans;
int minn[maxt],lazy[maxt];
struct Segment{
	int l,r,v;
}s[maxn];
inline int cmp(Segment a,Segment b){
	return a.v<b.v;
}
inline void getlazy(int now,int v){
	lazy[now]+=v,minn[now]+=v;
}
inline void pushdown(int now){
	if(lazy[now])
		getlazy(lc(now),lazy[now]),getlazy(rc(now),lazy[now]),lazy[now]=0;
}
void update(int l,int r,int now,int L,int R,int v){
	if(L<=l&&r<=R){
		getlazy(now,v);
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(now);
	if(L<=mid)
		update(l,mid,lc(now),L,R,v);
	if(mid<R)
		update(mid+1,r,rc(now),L,R,v);
	minn[now]=min(minn[lc(now)],minn[rc(now)]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].v);
	sort(s+1,s+1+n,cmp);
	ans=s[n].v;
	int l=1,r=0;
	while(r<n){
		r++,update(1,m-1,1,s[r].l,s[r].r-1,1);
		while(l<=r&&minn[1]>0){
			ans=min(ans,s[r].v-s[l].v);
			update(1,m-1,1,s[l].l,s[l].r-1,-1),l++;
		}
	}
	printf("%d\n",ans);
	return 0;
}