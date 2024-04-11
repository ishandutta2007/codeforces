using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define N 1200001
#define getmid int mid=(L[no]+R[no])>>1
#define lc no<<1
#define rc no<<1|1
#define int long long
const int mod=(1e9+9);
int L[N],R[N],p[N],q[N],a[N],f[N],n,l,r,ty,S[N],m,sum[N];
int getit(int x,int y,int l,int r) {
	int rel=0,rer=0;
	l--;
	if(l>=2) rel=((S[l-2]+1)%mod*(x)+((S[l-1])%mod*y%mod)%mod)%mod;
	if(l==1) rel=x;
	if(r>=2) rer=(((S[r-2]+1)%mod*(x))%mod+((S[r-1])%mod*y)%mod)%mod;
	if(r==1) rer=x;
	return (rer-rel+mod)%mod;
}
void pushup(int no) {
	if(L[no]!=R[no]) sum[no]=(sum[lc]+sum[rc])%mod;else sum[no]=0;
	sum[no]=(sum[no]+(getit(p[no],q[no],1,R[no]-L[no]+1)))%mod;
}
int query(int no,int l,int r) {
	if(L[no]==l&&R[no]==r) {
		return sum[no]%mod;
	}
	getmid;
	int it=getit(p[no],q[no],l-L[no]+1,r-L[no]+1);
//	cout<<it<<endl;
//	cout<<"xxxx ";cout<<no<<" "<<p[no]<<" "<<q[no]<<" "<<l<<" "<<r<<" "<<L[no]<<" "<<R[no]<<" "<<it<<endl;
	if(l>mid) return (query(rc,l,r)%mod+it)%mod;
	else if(r<=mid) return (query(lc,l,r)%mod+it)%mod;
	else {
		return (query(lc,l,mid)%mod+query(rc,mid+1,r)%mod+it%mod)%mod;
	}
}
void build(int no,int l,int r) {
	L[no]=l;R[no]=r;if(l==r) return;
	getmid;
	build(lc,l,mid);build(rc,mid+1,r);
}
void add(int no,int l,int r,int x) {

	if(L[no]==l&&R[no]==r) {
		p[no]=(p[no]+f[x])%mod;
		q[no]=(q[no]+f[x+1])%mod;
		pushup(no);
		return;
	}
	getmid;
	if(l>mid) add(rc,l,r,x);
	else if(r<=mid) add(lc,l,r,x);
	else {
		add(lc,l,mid,x);add(rc,mid+1,r,x+mid-l+1);
	}
	pushup(no);
}
char c;
void rd(int &x) {
	scanf("%lld",&x);
}
main() {
	rd(n);rd(m);
	for(int i=1;i<=n;i++) rd(a[i]);
	for(int i=1;i<=n;i++) {
		a[i]=(a[i]+a[i-1])%mod;
	}
	f[1]=1;f[2]=1;
	for(int i=3;i<=300001;i++) f[i]=(f[i-2]+f[i-1])%mod;
	for(int i=1;i<=300001;i++) S[i]=(S[i-1]+f[i])%mod;
	build(1,1,n);
	for(int i=1;i<=m;i++) {
		rd(ty);
		if(ty==1) {
			rd(l);rd(r);
			add(1,l,r,1);
		}
		else {
			rd(l);rd(r);
			printf("%lld\n",((query(1,l,r)%mod+a[r]%mod-a[l-1]%mod)+mod)%mod);
		}
	}
}