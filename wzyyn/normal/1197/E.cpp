#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 hfjskghsdjkfg
using namespace std;
const int N=200005;
const int M=8000005;
const int MX=1000000000;
const int mo=1000000007;
int n,mx,rt,nd,ls[M],rs[M];
pii a[N],b[N],t[M];
pii operator +(const pii &a,const pii &b){
	pii ans;
	ans.fi=max(a.fi,b.fi);
	if (a.fi==ans.fi) ans.se=(ans.se+a.se)%mo;
	if (b.fi==ans.fi) ans.se=(ans.se+b.se)%mo;
	return ans;
}
void insert(int &k,int l,int r,int p,pii v){
	if (!k) k=++nd;
	t[k]=t[k]+v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p,v);
	else insert(rs[k],mid+1,r,p,v);
}
pii ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	For(i,1,n) mx=max(mx,a[i].se);
	sort(a+1,a+n+1);
	insert(rt,0,MX,0,pii(0,1));
	For(i,1,n){
		b[i]=ask(rt,0,MX,0,a[i].se);
		b[i].fi+=a[i].fi-a[i].se;
		insert(rt,0,MX,a[i].fi,b[i]);
	}
	int mnv=1<<30,ans=0;
	For(i,1,n)
		if (a[i].fi>mx){
			b[i].fi=a[i].fi-b[i].fi;
			if (b[i].fi<mnv) mnv=b[i].fi,ans=0;
			if (b[i].fi==mnv) ans=(ans+b[i].se)%mo;
		}
	printf("%d\n",ans);
}