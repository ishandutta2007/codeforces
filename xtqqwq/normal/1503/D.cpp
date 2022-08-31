#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,v;
	bool operator<(const node c)const{return l<c.l;}
}a[200005];

int n;

struct sgt{
	int tag[600000],mina[600000],mark[600000];
	void build(int id,int l,int r){
		mina[id]=1<<30;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void pushdown(int id){
		if(mark[id]){
			mark[id<<1]=mark[id<<1|1]=1,tag[id<<1]=tag[id<<1|1]=0,mina[id<<1]=mina[id<<1|1]=1<<30;
			mark[id]=0;
		}
		if(tag[id]){
			tag[id<<1]+=tag[id],tag[id<<1|1]+=tag[id];
			mina[id<<1]+=tag[id],mina[id<<1|1]+=tag[id];
			tag[id]=0;
		}
	}
	void clear(){mark[1]=1,tag[1]=0,mina[1]=1<<30;}
	void change(int id,int l,int r,int x,int c){
		if(l==r) return (void)(chkmin(mina[id],c));
		pushdown(id);
		int mid=(l+r)/2;
		if(x<=mid) change(id<<1,l,mid,x,c);
		else change(id<<1|1,mid+1,r,x,c);
		mina[id]=min(mina[id<<1],mina[id<<1|1]);
	}
	int query(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return mina[id];
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
}T[2];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].l=readint(),a[i].r=readint(),a[i].v=0;
	for(int i=1;i<=n;i++) if(a[i].l>a[i].r) swap(a[i].l,a[i].r),a[i].v=1;
	int l=1,r=n+n;
	for(int i=1;i<=n;i++) chkmax(l,a[i].l),chkmin(r,a[i].r);
	if(l>r){
		printf("-1\n");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i].r-=n;
	int min1=n+n+1,min2=n+n+1;
	T[0].build(1,1,n+1);
	T[1].build(1,1,n+1);
	for(int i=1;i<=n;i++){
		if(a[i].r>min2) return printf("-1\n"),0;
		if(a[i].r>min1) chkmin(min2,a[i].r);
		chkmin(min1,a[i].r);
		if(i==1){
			T[0].change(1,1,n+1,n+1,a[i].v);
			T[1].change(1,1,n+1,n+1,a[i].v^1);
			continue;
		}
		int tmp0=T[0].query(1,1,n+1,a[i].r,n+1)+(a[i].v^1);
		int tmp1=T[1].query(1,1,n+1,a[i].r,n+1)+a[i].v;
		if(a[i].r<a[i-1].r){
			T[0].tag[1]+=a[i].v,T[0].mina[1]+=a[i].v;
			T[1].tag[1]+=a[i].v^1,T[1].mina[1]+=a[i].v^1;
			T[0].change(1,1,n+1,a[i-1].r,tmp1);
			T[1].change(1,1,n+1,a[i-1].r,tmp0);
		}
		else{
			T[0].clear();
			T[1].clear();
			T[0].change(1,1,n+1,a[i-1].r,tmp1);
			T[1].change(1,1,n+1,a[i-1].r,tmp0);
		}
	}
	printf("%d\n",min(T[0].mina[1],T[1].mina[1]));
	return 0;
}