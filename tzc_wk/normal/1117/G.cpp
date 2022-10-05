//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read();
int a[1000005],l[1000005],r[1000005];
vector<int> ql[1000005],qr[1000005];
struct Fenwick_Tree{
	int bit[1500005];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int x,int val){
		for(int i=x;i<=1500005;i+=lowbit(i))	bit[i]+=val;
	}
	inline int query(int x){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))	ans+=bit[i];
		return ans;
	}
	inline void add_range(int l,int r,int val){
		add(l,val);add(r+1,-val);
	}
	inline void clear(){
		fill0(bit);
	}
} cnt,sum;
int L[1000005],R[1000005],ans[1000005];
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,m)	l[i]=read(),qr[l[i]].push_back(i);
	fz(i,1,m)	r[i]=read(),ql[r[i]].push_back(i);
	fz(i,1,m)	ans[i]=r[i]-l[i]+1;
	stack<pii> stk;
	fz(i,1,n){
		while(!stk.empty()&&stk.top().fi<a[i]){
			R[stk.top().se]=i;
			stk.pop();
		}
		if(!stk.empty()){
			L[i]=stk.top().se;
		}
		stk.push({a[i],i});
	}
	fz(i,1,n){
		if(!R[i])	R[i]=n+1;
	}
//	fz(i,1,n)	cout<<L[i]<<" "<<R[i]<<endl;
	fz(i,1,n){
		cnt.add_range(L[i]+1,i,1);
		sum.add_range(L[i]+1,i,i);
		sum.add_range(1,L[i],i-L[i]-1);
		foreach(it,ql[i]){
			int ind=*it;
			int j=l[ind];
			ans[ind]+=sum.query(j)-cnt.query(j)*j;
		}
	}
	cnt.clear();sum.clear();
	fd(i,n,1){
		sum.add_range(i,R[i]-1,-i);
		cnt.add_range(i,R[i]-1,1);
		sum.add_range(R[i],n,R[i]-i-1);
		foreach(it,qr[i]){
			int ind=*it;
			int j=r[ind];
			ans[ind]+=sum.query(j)+cnt.query(j)*j;
		}
	}
	fz(i,1,m)	cout<<ans[i]<<" ";
	return 0;
}
/*
r-1 -> r
min(r-L[r]-1,r-l)

r-l<r-L[r]-1  ->  L[r]+1<l

1. l>=L[r]+1   r-l        sum.add(L[r]+1,r,r),cnt.add(L[r]+1,r,1)
2. l<=L[r]     r-L[r]-1   sum.add(1,L[r],r-L[r]-1)
*/
/*
l+1 -> l
min(R[l]-l-1,r-l)

r-l<R[l]-l-1 -> R[l]-1>r

1. r<=R[l]-1   r-l        sum.add(l,R[l]-1,l),cnt.add(l,R[l]-1,1)
2. l>=R[l]     R[l]-l-1   sum.add(R[l],n,R[l]-l-1)
*/