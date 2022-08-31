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

int n,m,tag;
int a[100005],mina[300000];

void build(int id,int l,int r){
	if(l==r){
		if(!l) mina[id]=0;
		else mina[id]=1e9;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(chkmin(mina[id],c));
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
}

int query(int id,int l,int r,int ql,int qr){
	if(ql>qr) return 1e9;
	if(l==ql&&r==qr) return mina[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	m=unique(a+1,a+n+1)-a-1;
	build(1,0,n);
	for(int i=1;i<=m;i++){
		int tmp=min(query(1,0,n,a[i],a[i]),min(query(1,0,n,0,a[i]-1)+1,query(1,0,n,a[i]+1,n)+1))+tag;
		tag++;
		change(1,0,n,a[i-1],tmp-tag);
	}
	printf("%d\n",mina[1]+tag);
	return 0;
}