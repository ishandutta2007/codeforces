#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=400005;
int n,a[N],q[N];
int dfn[N],ed[N];
int pr[N],su[N];
int ls[N],rs[N];
struct SEG{
	int mx[N*2],tg[N*2];
	void build(){
		memset(mx,0,sizeof(mx));
		memset(tg,0,sizeof(tg));
	}
	void change(int k,int l,int r,int x,int y,int v){
		if (l==x&&r==y){
			tg[k]+=v; mx[k]+=v;
			return;
		}
		int mid=(l+r)/2;
		if (y<=mid) change(k*2,l,mid,x,y,v);
		else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
		else{
			change(k*2,l,mid,x,mid,v);
			change(k*2+1,mid+1,r,mid+1,y,v);
		}
		mx[k]=max(mx[k*2],mx[k*2+1])+tg[k];
	}
}T;
void build(int x){
	dfn[x]=++*dfn;
	if (ls[x]) build(ls[x]);
	if (rs[x]) build(rs[x]);
	ed[x]=*dfn;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int l=1,r=n,tp=0;
	for (;a[l]!=1;a[l+n]=a[l],++l,++r);
	For(i,l,r){
		for (;tp;)
			if (a[q[tp]]<a[i]){
				rs[q[tp]]=i;
				break;
			}
			else{
				rs[q[tp]]=ls[i];
				ls[i]=q[tp--];
			}
		q[++tp]=i;
	}
	build(l);
	T.build();
	For(i,l,r){
		T.change(1,1,n,dfn[i],ed[i],1);
		pr[i]=T.mx[1];
	}
	T.build();
	Rep(i,r,l){
		T.change(1,1,n,dfn[i],ed[i],1);
		su[i]=T.mx[1]+(i!=l);
	}
	int ansv=1<<30,ansp;
	For(i,1,n){
		int L=i,R=i+n-1;
		if (L<l) L+=n;
		if (R>r) R-=n;
		int v=max(su[L],pr[R]);
		if (v<ansv) ansv=v,ansp=i-1;
	}
	printf("%d %d\n",ansv,ansp);
}