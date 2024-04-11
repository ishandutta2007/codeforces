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
int n=read(),m=read(),a[300005];
struct ChairmanTree{
	struct node{
		int ls,rs,val;
	} s[12000005];
	int cnt=0,rt[300005];
	inline void build(int &k,int l,int r){
		k=++cnt;s[k].val=0;
		if(l==r)	return;
		int mid=(l+r)>>1;
		build(s[k].ls,l,mid);
		build(s[k].rs,mid+1,r);
	}
	inline int update(int k,int l,int r,int x){
		int id=++cnt;
		s[id].ls=s[k].ls;s[id].rs=s[k].rs;s[id].val=s[k].val+1;
		if(l==r)	return id;
		int mid=(l+r)>>1;
		if(x<=mid)	s[id].ls=update(s[k].ls,l,mid,x);
		else		s[id].rs=update(s[k].rs,mid+1,r,x);
		return id;
	}
	inline int query(int k1,int k2,int l,int r,int x){
		if(l==r)	return l;
		int mid=(l+r)>>1;
		if(s[s[k2].ls].val-s[s[k1].ls].val>x){
			int t=query(s[k1].ls,s[k2].ls,l,mid,x);
			if(t>0)
				return t;
		}
		if(s[s[k2].rs].val-s[s[k1].rs].val>x){
			int t=query(s[k1].rs,s[k2].rs,mid+1,r,x);
			if(t>0)
				return t;
		}
		return -1;
	}
} st;
int main(){
	for(int i=1;i<=n;i++)	a[i]=read();
	st.build(st.rt[0],1,n);
	for(int i=1;i<=n;i++)	st.rt[i]=st.update(st.rt[i-1],1,n,a[i]);
	while(m--){
		int l=read(),r=read(),k=read();
		print(st.query(st.rt[l-1],st.rt[r],1,n,(r-l+1)/k));eoln;
	}
	return 0;
}