#include <bits/stdc++.h>
using namespace std;
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
bool rmq=0;
inline int read(){
	rmq=0;
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	if(c==' ')	rmq=1;
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,a[200005];
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[800005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline void pushdown(int k){
		s[k<<1].val+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
	inline void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val+=x;
			s[k].lz+=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} st;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)	a[i]=read();
	st.build(1,1,n);
	int T=read();
	while(T--){
		int l=read(),r=read();
		l++;r++;
		if(rmq){
			int x=read();
			if(l>r)	st.modify(1,l,n,x),st.modify(1,1,r,x);
			else	st.modify(1,l,r,x);
		}
		else{
			int ans=0;
			if(l>r)	ans=min(st.query(1,l,n),st.query(1,1,r));
			else	ans=st.query(1,l,r);
			print(ans);eoln;
		}
	}
	return 0;
}