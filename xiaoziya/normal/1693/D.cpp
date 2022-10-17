#include<stdio.h>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=200005,maxt=maxn<<2;
int n,top;
long long res;
int p[maxn],q[maxn],stk[maxn],Lmn[maxn],Rmx[maxn],lazy[maxt],ans[maxn];
vector<int>v2[maxn],v3[maxn];
void build(int l,int r,int now){
	lazy[now]=0;
	if(l==r)
		return ;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
}
inline void getlazy(int now,int v){
	lazy[now]=max(lazy[now],v);
}
inline void pushdown(int now){
	if(lazy[now]!=0)
		getlazy(lc(now),lazy[now]),getlazy(rc(now),lazy[now]),lazy[now]=0;
}
void update(int l,int r,int now,int L,int R,int v){
	if(L<=l&&r<=R){
		getlazy(now,v);
		return ;
	}
	pushdown(now);
	if(L<=mid)
		update(l,mid,lc(now),L,R,v);
	if(mid<R)
		update(mid+1,r,rc(now),L,R,v);
}
int query(int l,int r,int now,int p){
	if(l==r)
		return lazy[now];
	pushdown(now);
	if(p<=mid)
		return query(l,mid,lc(now),p);
	return query(mid+1,r,rc(now),p);
}
void solve(){
	for(int i=1;i<=n;i++){
		while(top&&p[stk[top]]>p[i])
			top--;
		Lmn[i]=stk[top],stk[++top]=i;
	}
	top=0,stk[top]=n+1;
	for(int i=n;i>=1;i--){
		while(top&&p[stk[top]]<p[i])
			top--;
		Rmx[i]=stk[top],stk[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++){
//		printf("i=%d %d %d\n",i,Lmn[i],Rmx[i]);
		v3[Rmx[i]].push_back(i),v2[Lmn[i]].push_back(i);
	}
	build(1,n,1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v3[i].size();j++){
			int k=v3[i][j];
//			printf("%d : 4 ; %d : 3\n",i,k);
			if(p[k]>1)
				update(1,n,1,1,p[k]-1,k);
		}
		for(int j=0;j<v2[i].size();j++){
//			printf("%d : 1 ; %d : 2\n",i,v2[i][j]);
			ans[v2[i][j]]=max(ans[v2[i][j]],query(1,n,1,p[v2[i][j]]));
		}
		v2[i].clear(),v3[i].clear();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	solve();
	for(int i=1;i<=n;i++)
		p[i]=n-p[i]+1;
	solve();
	for(int i=1;i<=n;i++)
		ans[i]=max(ans[i],ans[i-1]),res+=i-ans[i];
	printf("%lld\n",res);
	return 0;
}
//3412 2143