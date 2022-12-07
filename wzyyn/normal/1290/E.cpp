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
const int N=150005;
int n,p[N],a[N],b[N];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) b[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=b[x];
	return ans;
}
int atg[N*4],mtg[N*4],sz[N*4];
int mn0[N*4],mn1[N*4],mns[N*4];
ll sum[N*4],ans[N];
void adv(int k,int v){
	atg[k]+=v; mtg[k]+=v;
	mn0[k]+=v; mn1[k]+=v;
	sum[k]+=1ll*sz[k]*v;
}
void mxv(int k,int v){
	mtg[k]=max(mtg[k],v);
	if (mn0[k]>=v||!sz[k]) return;
	assert(mn1[k]>v);
	sum[k]+=1ll*mns[k]*(v-mn0[k]);
	mn0[k]=v;
}
void pushdown(int k){
	if (atg[k]){
		adv(k*2,atg[k]);
		adv(k*2+1,atg[k]);
		atg[k]=0;
	}
	if (mtg[k]){
		mxv(k*2,mtg[k]);
		mxv(k*2+1,mtg[k]);
		mtg[k]=0;
	}
}
void pushup(int k){
	sum[k]=sum[k*2]+sum[k*2+1];
	sz[k]=sz[k*2]+sz[k*2+1];
	mn0[k]=min(mn0[k*2],mn0[k*2+1]);
	mn1[k]=min(mn0[k*2]==mn0[k]?mn1[k*2]:mn0[k*2],
			   mn0[k*2+1]==mn0[k]?mn1[k*2+1]:mn0[k*2+1]);
	mns[k]=(mn0[k]==mn0[k*2]?mns[k*2]:0)+
		   (mn0[k]==mn0[k*2+1]?mns[k*2+1]:0);
}
void changeP(int k,int l,int r,int p){
	if (l==r){
		mns[k]=sz[k]=1;
		mn0[k]=0;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) changeP(k*2,l,mid,p);
	else changeP(k*2+1,mid+1,r,p);
	pushup(k);
}
void changev(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y)
		return adv(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) changev(k*2,l,mid,x,y,v);
	else if (x>mid) changev(k*2+1,mid+1,r,x,y,v);
	else{
		changev(k*2,l,mid,x,mid,v);
		changev(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
void changemx(int k,int l,int r,int x,int y,int v){
	//cout<<"changemx "<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<v<<endl;
	//cout<<mn0[k]<<' '<<mn1[k]<<' '<<mns[k]<<' '<<sum[k]<<endl; 
	if (mn0[k]>=v||!sz[k]) return;
	if (l==x&&r==y&&mn1[k]>v)
		return mxv(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) changemx(k*2,l,mid,x,y,v);
	else if (x>mid) changemx(k*2+1,mid+1,r,x,y,v);
	else{
		changemx(k*2,l,mid,x,mid,v);
		changemx(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
void solve(){
	memset(sum,0,sizeof(sum));
	memset(atg,0,sizeof(atg));
	memset(mtg,0,sizeof(mtg));
	memset(mn0,60,sizeof(mn0));
	memset(mn1,60,sizeof(mn1));
	memset(mns,0,sizeof(mns));
	memset(sz,0,sizeof(sz));
	memset(b,0,sizeof(b));
	For(i,1,n) p[a[i]]=i;
	For(i,1,n){
		int x=p[i],v=ask(x)+1;
		changeP(1,1,n,x);
		if (x!=n){
			changev(1,1,n,x+1,n,1);
			changemx(1,1,n,x+1,n,v);
		}
		ans[i]+=1ll*i*(i-1)/2-sum[1];
		change(x,1);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	solve();
	reverse(a+1,a+n+1);
	solve();
	For(i,1,n) printf("%lld\n",ans[i]+i);
}