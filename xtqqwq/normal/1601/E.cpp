#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,id;
	node(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator<(const node c)const{return mp(l,r)<mp(c.l,c.r);}
};

int n,q,k,top;
vector<node> qry[300005];
int lazy[1100000],lg2[300005],rmq[300005][20],a[300005],A[300005],B[300005],stk[300005];
ll sum[1100000],ans[300005];

void build(int id,int l,int r){
	sum[id]=lazy[id]=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id,int l,int r){
	if(lazy[id]){
		int mid=(l+r)/2;
		lazy[id<<1]=lazy[id<<1|1]=lazy[id];
		sum[id<<1]=1ll*(mid-l+1)*lazy[id];
		sum[id<<1|1]=1ll*(r-mid)*lazy[id];
		lazy[id]=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(lazy[id]=c,sum[id]=1ll*(r-l+1)*c);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

ll query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return sum[id];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int getmin(int l,int r){
	int k=lg2[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}

int main(){
	n=readint(); q=readint(); k=readint();
	for(int i=0;i<n;i++) a[i]=readint();
	int x,y;
	for(int i=1;i<=q;i++){
		x=readint()-1; y=readint()-1;
		qry[x%k].pb(node(x/k,x/k+(y-x)/k,i));
	}
	for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=0;i<n;i++) rmq[i][0]=a[i];
	for(int i=1;(1<<i)<=n;i++) for(int j=0;j+(1<<i)-1<n;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	for(int i=0;i<k;i++){
		if(!qry[i].size()) continue;
		sort(qry[i].begin(),qry[i].end());
		int m=(n-i-1)/k;
		for(int j=0;j<=m;j++) A[j]=a[j*k+i],B[j]=getmin(j*k+i,min(n,j*k+i+k-1));
//		cout<<"test "<<i<<' '<<m<<endl;
//		for(int j=0;j<=m;j++) cout<<A[j]<<' ';
//		cout<<endl;
//		for(int j=0;j<=m;j++) cout<<B[j]<<' ';
//		cout<<endl;
//		for(auto r:qry[i]) cout<<"query "<<r.l<<' '<<r.r<<' '<<r.id<<endl;
		top=0;
		build(1,0,m);
		int now=qry[i].size();
		for(int j=m;j>=0;j--){
			while(top&&B[stk[top]]>=B[j]) top--;
			int pl=top?stk[top]-1:m;
			change(1,0,m,j,pl,B[j]);
			if(pl<m) change(1,0,m,pl+1,pl+1,getmin(j*k+i,(pl+1)*k+i));
			change(1,0,m,j,j,A[j]);
			while(now>0&&qry[i][now-1].l==j){
				ans[qry[i][now-1].id]=query(1,0,m,j,qry[i][now-1].r);
				now--;
			}
			stk[++top]=j;
		}
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}