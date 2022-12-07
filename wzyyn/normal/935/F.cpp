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
const int N=100005;
int n,Q,a[N];
ll tt[N],ans;
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) tt[x]+=v;
}
ll ask(int x){
	ll ans=0;
	for (;x;x-=x&(-x)) ans+=tt[x];
	return ans;
}
struct node{
	ll v1a,v1b,v2,v3;
}t[N*4];
node operator +(node a,node b){
	node ans;
	ans.v3=a.v3|b.v3;
	ans.v2=min(a.v2,b.v2);
	ans.v1a=min(a.v1a,b.v1a);
	ans.v1b=min(a.v1b,b.v1b);
	return ans;
}
void build(int k,int l,int r){
	if (l==r){
		ll v1=ask(l-1),v2=ask(l),v3=ask(l+1);
		//cout<<l<<' '<<v1<<' '<<v2<<' '<<v3<<endl;
		if (v1>v3) swap(v1,v3);
		if (v2>=v3) t[k]=(node){1ll<<60,1ll<<60,1ll<<60,1};
		else if (v2<v1) t[k]=(node){v3+v1-v2-v2,v1-v2,1ll<<60,0};
		else t[k]=(node){1ll<<60,1ll<60,v3-v2,0};
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p){
	if (l==r){
		ll v1=ask(l-1),v2=ask(l),v3=ask(l+1);
		if (v1>v3) swap(v1,v3);
		if (v2>=v3) t[k]=(node){1ll<<60,1ll<<60,1ll<<60,1};
		else if (v2<v1) t[k]=(node){v3+v1-v2-v2,v1-v2,1ll<<60,0};
		else t[k]=(node){1ll<<60,1ll<60,v3-v2,0};
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y); 
}
void query(int x,int y,int v){
	ll dif=-(1ll<<60);
	node tmp=ask(1,2,n-1,x,y);
	if (tmp.v3) dif=2*v;
	else{
		if (tmp.v2!=(1ll<<60))
			dif=max(0ll,2*(v-tmp.v2));
		if (tmp.v1a!=(1ll<<60))
			if (v<=tmp.v1b) dif=max(dif,2ll*(-v));
			else dif=max(dif,2*max(v-tmp.v1a,-tmp.v1b));
		//dif=max(dif,2*(v-tmp.v1));
	}
	printf("%lld\n",ans+dif);
}
void change(int x,int y,int v){
	ans-=abs(ask(x)-ask(x-1));
	ans-=abs(ask(y+1)-ask(y));
	change(x,v);
	change(y+1,-v);
	ans+=abs(ask(x)-ask(x-1));
	ans+=abs(ask(y+1)-ask(y));
	if (x!=2) change(1,2,n-1,x-1);
	change(1,2,n-1,x);
	change(1,2,n-1,y);
	if (y!=n-1) change(1,2,n-1,y+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1) ans+=abs(a[i]-a[i+1]);
	For(i,1,n) change(i,a[i]-a[i-1]);
	build(1,2,n-1);
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y,v;
		scanf("%d%d%d%d",&tp,&x,&y,&v);
		if (tp==1) query(x,y,v);
		else change(x,y,v);
	}
}
/*
3
10 1 14
4
1 2 2 1
1 2 2 9
1 2 2 10
1 2 2 15
*/