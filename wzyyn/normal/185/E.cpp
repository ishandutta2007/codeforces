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
const int N=200005;
const int M=5000005;
pii a[N],b[N],mn[N],q[N];
int X[N],Y[N],t[N],n,k;
int rt[N],ls[M],rs[M],S[M],nd;
vector<int> vec[N];
void change(int k,int v){
	for (;k<=*Y;k+=k&(-k)) t[k]=max(t[k],v);
}
int ask(int k){
	int ans=-(1<<30);
	for (;k;k-=k&(-k)) ans=max(ans,t[k]);
	return ans;
}
void change(int &nk,int k,int l,int r,int p){
	nk=++nd; S[nk]=S[k]+1;
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(ls[nk],ls[k],l,mid,p);
	else change(rs[nk],rs[k],mid+1,r,p);
}
int ask(int k,int l,int r,int x,int y){
	if (!k) return 0;
	if (l==x&&r==y) return S[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
}
bool ask(int lx,int rx,int ly,int ry){
	lx=lower_bound(X+1,X+*X+1,lx)-X;
	ly=lower_bound(Y+1,Y+*Y+1,ly)-Y;
	rx=lower_bound(X+1,X+*X+1,rx+1)-X;
	ry=lower_bound(Y+1,Y+*Y+1,ry+1)-Y;
	if (ly==ry) return 0;
	return ask(rt[lx-1],1,*Y,ly,ry-1)!=
		   ask(rt[rx-1],1,*Y,ly,ry-1);
}
void findclosest(){
	*Y=0;
	For(i,1,n) a[i]=pii(-a[i].se,a[i].fi);
	For(i,1,k) b[i]=pii(-b[i].se,b[i].fi);
	For(i,1,n) Y[++*Y]=a[i].se;
	For(i,1,k) Y[++*Y]=b[i].se;
	sort(Y+1,Y+*Y+1);
	*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,1,*Y) t[i]=-(1<<30);
	For(i,1,n) q[i]=pii(a[i].fi,i);
	For(i,1,k) q[i+n]=pii(b[i].fi,-i);
	sort(q+1,q+n+k+1);
	For(i,1,n+k){
		int id=q[i].se;
		if (id>0){
			int p=lower_bound(Y+1,Y+*Y+1,a[id].se)-Y;
			mn[id].fi=min(mn[id].fi,a[id].fi+a[id].se-ask(p));
		}
		else{
			int p=lower_bound(Y+1,Y+*Y+1,b[-id].se)-Y;
			change(p,b[-id].fi+b[-id].se);
		}
	}
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	For(i,1,k) scanf("%d%d",&b[i].fi,&b[i].se);
	For(i,1,n) mn[i]=pii(1<<29,i);
	For(T,0,3) findclosest();
	//For(i,1,n) printf("%d\n",mn[i].fi);
	For(i,1,n) a[i]=pii(a[i].fi+a[i].se,a[i].fi-a[i].se);
	For(i,1,k) b[i]=pii(b[i].fi+b[i].se,b[i].fi-b[i].se);
	*X=*Y=0;
	For(i,1,k) X[++*X]=b[i].fi;
	For(i,1,k) Y[++*Y]=b[i].se;
	X[++*X]=Y[++*Y]=-(1<<30);
	X[++*X]=Y[++*Y]=(1<<30);
	sort(X+1,X+*X+1);
	sort(Y+1,Y+*Y+1);
	*X=unique(X+1,X+*X+1)-X-1;
	*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,1,k){
		b[i].fi=lower_bound(X+1,X+*X+1,b[i].fi)-X;
		b[i].se=lower_bound(Y+1,Y+*Y+1,b[i].se)-Y;
		vec[b[i].fi].PB(b[i].se);
	}
	For(i,1,*X){
		rt[i]=rt[i-1];
		for (auto j:vec[i])
			change(rt[i],rt[i],1,*Y,j);
	}
	sort(mn+1,mn+n+1);
	int l=0,r=(1<<29),ans;
	while (l<=r){
		int mid=(l+r)/2;
		int lx=-(1<<29),rx=-lx;
		int ly=lx,ry=rx,ok=0;
		Rep(i,n,1){
			int id=mn[i].se;
			int d=mid-mn[i].fi;
			if (d>=0){
				ok|=ask(lx-d,rx+d,ly-d,ry+d);
				if (ok) break;
			}
			lx=max(lx,a[id].fi-mid);
			ly=max(ly,a[id].se-mid);
			rx=min(rx,a[id].fi+mid);
			ry=min(ry,a[id].se+mid);
			if (lx>rx||ly>ry) break;
		}
		ok|=(lx<=rx&&ly<=ry);
		if (ok) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}