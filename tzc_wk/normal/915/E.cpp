#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
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
int n=read(),m=read(),key[600005],hs[600005],hs_pt=0,cnt=0;
struct Query{
	int l,r,k;
} q[300005];
inline void input(int x){
	q[x].l=read();
	q[x].r=read();
	q[x].r++;
	q[x].k=read();
	key[++cnt]=q[x].l;
	key[++cnt]=q[x].r;
}
inline void discrete(int x){
	q[x].l=lower_bound(hs+1,hs+hs_pt,q[x].l)-hs;
	q[x].r=lower_bound(hs+1,hs+hs_pt,q[x].r)-hs;
}
struct SegTree{
	struct node{
		int l,r,val,lz,sum;
	} s[2400005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=hs[l+1]-hs[l];
			s[k].sum=s[k].val;
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
		s[k].sum=s[k].val;
	}
	inline void pushdown(int k){
		if(s[k].lz==-1)	return;
		s[k<<1].lz=s[k].lz;
		s[k<<1|1].lz=s[k].lz;
		if(s[k].lz){
			s[k<<1].val=0;
			s[k<<1|1].val=0;
		}
		else{
			s[k<<1].val=s[k<<1].sum;
			s[k<<1|1].val=s[k<<1|1].sum;
		}
		s[k].lz=-1;
	}
	inline void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].lz=x;
			if(x==1)	s[k].val=0;
			else		s[k].val=s[k].sum;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
} st;
int main(){
	fz(i,1,m)	input(i);
	sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(key[i]!=key[i-1])	hs[++hs_pt]=key[i];
	}
	fz(i,1,m)	discrete(i);
	int ans=hs[1]-1+n-hs[hs_pt]+1;
	st.build(1,1,hs_pt-1);
	fz(i,1,m){
		st.modify(1,q[i].l,q[i].r-1,q[i].k%2);
		print(st.s[1].val+ans);eoln;
	}
	return 0;
}