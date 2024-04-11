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
const int BLOCK_SZ=320;
int n=read(),m=read(),k=read(),bel[100005],blk;
int cnt[1048576];
struct query{
	int l,r,id;
	inline bool operator <(query b){
		if(bel[l]!=bel[b.l])
			return bel[l]<bel[b.l];
		else if(bel[l]&1)
			return r>b.r;
		else
			return r<b.r;
	}
} q[100005];
int anss=0,ans[100005],a[100005];
inline void push(int x){
	anss+=cnt[a[x]^k];
	cnt[a[x]]++;
}
inline void pop(int x){
	cnt[a[x]]--;
	anss-=cnt[a[x]^k];
}
signed main(){
	fz(i,1,n)	a[i]=read(),a[i]^=a[i-1];
	blk=n/BLOCK_SZ+1;
	fz(i,1,blk){
		int l=(i-1)*BLOCK_SZ;
		int r=min(i*BLOCK_SZ-1,n);
		fz(j,l,r)	bel[j]=i;
	}
	fz(i,1,m){
		q[i].l=read();q[i].r=read();q[i].id=i;
		q[i].l--;
	}
	sort(q+1,q+m+1);
	int l=0,r=-1;
	fz(i,1,m){
		while(l<q[i].l)	pop(l++);
		while(l>q[i].l)	push(--l);
		while(r<q[i].r)	push(++r);
		while(r>q[i].r)	pop(r--);
		ans[q[i].id]=anss;
	}
	fz(i,1,m)	cout<<ans[i]<<endl;
	return 0;
}
/*
50 8 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
17 35
3 35
33 42
20 27
28 33
44 46
5 12
34 42
*/