#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long lli;
typedef std::pair<int, lli> lp;
const lli MAX=1<<19;
struct data {
	int a,b,c;
	bool operator<(const data &rhs) const {
		return c<rhs.c;
	}
};
lli st[1<<20],lst[1<<20];
int mt[1<<20],lmt[1<<20];
int n,p,q,r;
data arr[1<<19];
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0'&&c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
  return sum;
}
void push_mt(int node,int s, int f) {
	if(lmt[node]==0) return;
	mt[node]=std::max(mt[node],lmt[node]);
	if(s!=f) {
		int ch=node<<1;
		lmt[ch]=std::max(lmt[ch],lmt[node]);
		lmt[ch+1]=std::max(lmt[ch+1],lmt[node]);	
	}
	lmt[node]=0;
}
int lower_mt(int node, int st, int fi,int idx,int val) {
	if(st==fi) {
		if(mt[node]<=val) return st;
		else return st+1;
	}
	if(st>idx) return st;
	
	int ch=node<<1,md=(st+fi)>>1;
	push_mt(ch,st,md); push_mt(ch+1,md+1,fi);
	if(mt[ch+1]>val) {
		return lower_mt(ch+1,md+1,fi,idx,val);
	}
	else {
		return lower_mt(ch,st,md,idx,val);
	}
}
void push_st(int node,int s, int f) {
	if(lst[node]==0) return;
	st[node]=lst[node]*(long long)(f-s+1);
	if(s!=f) {
		int ch=node<<1;
		lst[ch]=lst[ch+1]=lst[node];
	}
	lst[node]=0;
}
lp update_mt(int node, int s, int f, int le, int ri, int val) {
	push_mt(node,s,f);
	push_st(node,s,f);
	
	if(f<le||s>ri) return lp(mt[node],st[node]);
	if(le<=s&&f<=ri) {
		lmt[node]=std::max(lmt[node],val);
		push_mt(node,s,f);
		lst[node]=val;
		push_st(node,s,f);
		return lp(mt[node],st[node]);
	}
	else {
		int ch=node<<1,idx=(s+f)>>1;
		lp lev=update_mt(ch,s,idx,le,ri,val),riv=update_mt(ch+1,idx+1,f,le,ri,val);
		mt[node]=std::max(lev.first,riv.first);
		st[node]=lev.second+riv.second;
		return lp(mt[node],st[node]);
	}
}
void init() {
	for(int i=0;i<n;i++) {
		int l=lower_mt(1,1,p,arr[i].a,arr[i].b),r=arr[i].a;
		if(l>r) continue;
		update_mt(1,1,p,l,r,arr[i].b);
	}
}
int main() {
	n=read();p=read();q=read();r=read();
	for(int i=0;i<n;i++) { arr[i].a=read(); arr[i].b=read(); arr[i].c=read();}
	
	std::sort(arr, arr+n);
	init();

	lli res=0,s=(long long)p*q;
	int prev=r;
	for(int i=n-1;i>=0;i--) {
		res+=(long long)(prev-arr[i].c)*(s-st[1]);
		prev=arr[i].c;
		
		update_mt(1,1,p,1,arr[i].a,q);

		int l=lower_mt(1,1,p,p,arr[i].b),r=p;
		if(l>r) continue;
		update_mt(1,1,p,l,r,arr[i].b);
	}
	res+=prev*(s-st[1]);
	printf("%lld\n",res);
	
	return 0;
}