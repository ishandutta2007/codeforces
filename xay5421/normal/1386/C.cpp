// author: xay5421
// created: Wed Apr 28 08:22:34 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,Q,u[N],v[N],ans[N];
struct ds{
	int st[N][2],top,sz[N],fa[N],col[N];
	int res,bad;
	int fd(int k1){
		res=0;
		while(fa[k1]!=k1){
			res^=col[k1];
			k1=fa[k1];
		}
		return k1;
	}
	void roll_back(){
		assert(top);
		int k1=st[top][0],k2=st[top][1]; --top;
		if(k1==-1)bad-=k2;
		else fa[k2]=k2,sz[k1]-=sz[k2],col[k2]=0;
	}
	void mer(int k1,int k2){
		k1=fd(k1);
		int c1=res;
		k2=fd(k2);
		int c2=res;
		if(k1==k2){
			st[++top][0]=-1,st[top][1]=c1==c2,bad+=c1==c2;
			return;
		}
		if(sz[k1]<sz[k2])swap(k1,k2);
		st[++top][0]=k1,st[top][1]=k2;
		fa[k2]=k1,sz[k1]+=sz[k2],col[k2]=c1^c2^1;
	}
}o;
void sol(int l,int r,int L,int R){
	if(l>r)return;
	while(r>R)ans[r]=r-1,--r;
	if(L==R){
		rep(i,l,r){
			if(o.bad)ans[i]=L;
			o.mer(u[i],v[i]);
		}
		rep(i,l,r)o.roll_back();
		return;
	}
	int mid=(L+R+1)>>1;
	rep(i,mid+1,R)o.mer(u[i],v[i]);
	int pos=l-1;
	rep(i,l,mid){
		if(o.bad)break;
		pos=i;
		o.mer(u[i],v[i]);
	}
	rep(i,l,pos)o.roll_back();
	o.mer(u[mid],v[mid]);
	sol(l,pos,L,mid-1);
	o.roll_back();
	rep(i,mid+1,R)o.roll_back();
	rep(i,l,pos)o.mer(u[i],v[i]);
	sol(pos+1,r,mid,R);
	rep(i,l,pos)o.roll_back();
}
int main(){
	rd(n),rd(m),rd(Q);
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		u[i]=k1,v[i]=k2;
	}
	rep(i,1,n)o.fa[i]=i,o.sz[i]=1;
	rep(i,1,m)o.mer(u[i],v[i]);
	if(!o.bad){
		rep(i,1,Q)puts("NO");
		return 0;
	}
	rep(i,1,m)o.roll_back();
	sol(1,m,1,m);
	rep(i,1,Q){
		int l,r;
		rd(l),rd(r);
		puts(ans[l]>=r?"YES":"NO");
	}
	return 0;
}