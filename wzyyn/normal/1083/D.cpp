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
const int mo=1000000007;
const int N=100005;
map<int,int> mp;
int n,a[N],pr[N],su[N];
int q1[N],q2[N],ans;
int sz[N*4],tg[N*4][2];
ll s[N*4][2],t[N*4];
void add(int k,int v,int p){
	tg[k][p]+=v;
	s[k][p]+=1ll*sz[k]*v;
	t[k]+=1ll*v*s[k][p^1];
}
void pushdown(int k){
	For(p,0,1) if (tg[k][p]){
		add(k*2,tg[k][p],p);
		add(k*2+1,tg[k][p],p);
		tg[k][p]=0;
	}
}
void pushup(int k){
	s[k][0]=s[k*2][0]+s[k*2+1][0];
	s[k][1]=s[k*2][1]+s[k*2+1][1];
	t[k]=t[k*2]+t[k*2+1];
}
void build(int k,int l,int r){
	sz[k]=r-l+1;
	if (l==r){
		s[k][0]=l;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int v,int p){
	if (x<=l&&r<=y) return add(k,v,p);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v,p);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v,p);
	pushup(k);
}
ll ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) pr[i]=mp[a[i]],mp[a[i]]=i;
	For(i,1,n) mp[a[i]]=n+1;
	Rep(i,n,1) su[i]=mp[a[i]],mp[a[i]]=i;
	For(i,1,n) pr[i]++,su[i]--;
	int prv=1,t1=0,t2=0;
	build(1,1,n);
	For(i,1,n){
		prv=max(prv,pr[i]);
		for (;t1&&pr[q1[t1]]<=pr[i];--t1) change(1,1,n,q1[t1-1]+1,q1[t1],pr[q1[t1]],0);
		for (;t2&&su[q2[t2]]>=su[i];--t2) change(1,1,n,q2[t2-1]+1,q2[t2],-su[q2[t2]],1);
		change(1,1,n,q1[t1]+1,i,-pr[i],0);
		change(1,1,n,q2[t2]+1,i,su[i],1);
		q1[++t1]=q2[++t2]=i;
		
		change(1,1,n,1,n,-i,1);
		ans=(ans+ask(1,1,n,prv,i))%mo;
		//cout<<ans<<' '<<prv<<' '<<pr[i]<<' '<<su[i]<<' '<<i<<endl;
		change(1,1,n,1,n,i,1);
	}
	printf("%d\n",ans);
}
/*
(l+1-pr) (r-i)
*/