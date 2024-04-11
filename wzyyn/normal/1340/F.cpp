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
const int moo=1000000007;
const int N=100005;
const int B=355,BLK=300;
int n,cnt,Q,a[N],L[B],R[B];
int bas1,bas2,p1[B],p2[B];
int flag[B];
int rnd(){
	int x=0;
	For(i,1,9) x=x*10+rand()%10;
	return x;
}
void init_seed(){
	for (;clock()<30;rnd());
	bas1=rnd()%50000000*2+1+1926*817;
	bas2=rnd()%50000000*2+1+1926*817;
	p1[0]=p2[0]=1;
	For(i,1,B-1) p1[i]=1ll*p1[i-1]*bas1%moo;
	For(i,1,B-1) p2[i]=1ll*p2[i-1]*bas2%moo;
}

struct Hash_node{
	int a[B],v1[B],v2[B],top;
	void init(){
		top=0;
	}
	void ins(int x){
		a[++top]=x;
	}
	void build(){
		v1[0]=v2[0]=0;
		For(i,1,top) v1[i]=(1ll*v1[i-1]*bas1+a[i]+N)%moo;
		For(i,1,top) v2[i]=(1ll*v2[i-1]*bas2+a[i]+N)%moo;
	}
	pii ask(int r,int len){
		int key1=(v1[r]+moo-1ll*v1[r-len]*p1[len]%moo)%moo;
		int key2=(v2[r]+moo-1ll*v2[r-len]*p2[len]%moo)%moo;
		return pii(key1,key2);
	}
}hsh1[B],hsh2[B];
void build(int id,int l,int r){
	static int q[B],top;
	top=flag[id]=0;
	For(i,l,r)
		if (a[i]<0&&top&&q[top]==-a[i]) --top;
		else q[++top]=a[i];
	For(i,2,top) if (q[i]<0&&q[i-1]>0) flag[id]=1;
	if (flag[id]) return;
	hsh1[id].init(); hsh2[id].init();
	Rep(i,top,1) if (q[i]<0) hsh1[id].ins(-q[i]);
	For(i,1,top) if (q[i]>0) hsh2[id].ins(q[i]);
	hsh1[id].build();
	hsh2[id].build();
}
void change(int x,int y){
	a[x]=y;
	int be=(x-1)/BLK+1;
	build(be,L[be],R[be]);	
}
int top,ok;
pii q[B];
void insert(int id){
	if (flag[id]) ok=0;
	if (!ok) return;
	int len=hsh1[id].top;
	for (;top&&ok&&len;){
		int v=min(q[top].se,len);
		if (hsh2[q[top].fi].ask(q[top].se,v)!=hsh1[id].ask(len,v)) ok=0;
		if (!(q[top].se-=v)) --top;
		len-=v;
	}
	if (len) ok=0;
	if (hsh2[id].top)
		q[++top]=pii(id,hsh2[id].top); 
}
bool query(int l,int r){
	int bl=(l-1)/BLK+1,br=(r-1)/BLK+1;
	if (bl==br){
		static int q[B],top;
		top=0;
		For(i,l,r)
			if (a[i]<0&&top&&q[top]==-a[i]) --top;
			else q[++top]=a[i];
		return !top;
	}
	else{
		build(cnt+1,l,R[bl]);
		build(cnt+2,L[br],r);
		top=0; ok=1;
		insert(cnt+1);
		For(i,bl+1,br-1) insert(i);
		insert(cnt+2);
		return ok&&!top;
	}
}
int main(){
	init_seed();
	scanf("%d%*d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	cnt=(n-1)/BLK+1;
	For(i,1,cnt){
		L[i]=(i-1)*BLK+1;
		R[i]=min(n,i*BLK);
		build(i,L[i],R[i]);
	}
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(x,y);
		else puts(query(x,y)?"Yes":"No");
	}
}