#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005,B=305;
int n,W,cnt,mx;
int tg[N],q[N];
int pos[N],now[N];
int L[N],R[N];
ll sum[N];
pll res[N],ans;
vector<int> vec[N];
bool cmp(int x,int y,int z){
	return 1ll*(z-x)*(sum[y]-sum[x])<=
		   1ll*(y-x)*(sum[z]-sum[x]);
}
ll F(int p,int dif){
	return 1ll*p*dif+sum[p];
}
void build(int x){
	pos[x]=L[x]-1;
	now[x]=L[x];
	For(i,L[x],R[x]){
		for (;pos[x]>L[x]&&cmp(q[pos[x]-1],q[pos[x]],i);--pos[x]);
		q[++pos[x]]=i;
	}
}
void UPD(int x){
	for (;now[x]<pos[x]&&F(q[now[x]],tg[x])<F(q[now[x]+1],tg[x]);++now[x]);
}
pll query(int x){
	return pll(F(q[now[x]],tg[x]),q[now[x]]);
}
void build_blk(){
	cnt=(100000-1)/B+1;
	For(i,1,cnt){
		L[i]=(i-1)*B+1;
		R[i]=min(i*B,100000);
		build(i); UPD(i);
	}
}
void change(int x){
	int be=(x-1)/B+1;
	For(i,1,be-1) ++tg[i],UPD(i);
	For(i,L[be],x) sum[i]+=i;
	build(be); UPD(be);
}
int main(){
	scanf("%d%d",&n,&W);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		mx=max(mx,y);
		vec[y].PB(x);
	}
	build_blk();
	int sum=n;
	For(i,0,mx+1){
		printf("%lld %lld\n",ans.fi+1ll*i*W*sum,ans.se);
		for (auto j:vec[i]) change(j),sum--;
		For(j,1,cnt) ans=max(ans,query(j));
	}
}