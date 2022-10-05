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
char a[500005],b[500005],s[1000005];
char buf[1500005];
int cnt=0,za[1500005],zb[1500005],z1[500005],z2[500005];
struct Fenwick_Tree{
	int bit[1500005];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int x,int val){
		x=max(x,1ll);
		for(int i=x;i<=1000000;i+=lowbit(i))	bit[i]+=val;
	}
	inline int query(int x){
		int ans=0;
		for(int i=x;i;i-=lowbit(i))	ans+=bit[i];
		return ans;
	}
} t1,t2;
signed main(){
	scanf("%s%s%s",a+1,b+1,s+1);
	fz(i,1,m-1)	buf[cnt++]=s[i];
	buf[cnt++]='#';
	fz(i,1,n)	buf[cnt++]=a[i];
	int l=0,r=0;
	for(int i=1;i<cnt;i++){
		if(i<=r)	za[i]=min(za[i-l],r-i);
		while(i+za[i]<cnt&&buf[za[i]]==buf[i+za[i]])	za[i]++;
		if(i+za[i]>r){
			l=i;
			r=i+za[i];
		}
	}
	fill0(buf);cnt=0;
	fd(i,m,2)	buf[cnt++]=s[i];
	buf[cnt++]='#';
	fd(i,n,1)	buf[cnt++]=b[i];
	l=0,r=0;
	for(int i=1;i<cnt;i++){
		if(i<=r)	zb[i]=min(zb[i-l],r-i);
		while(i+zb[i]<cnt&&buf[zb[i]]==buf[i+zb[i]])	zb[i]++;
		if(i+zb[i]>r){
			l=i;
			r=i+zb[i];
		}
	}
	fz(i,1,n)	z1[i]=za[i+m-1];
	fz(i,1,n)	z2[i]=zb[i+m-1];
	reverse(z2+1,z2+n+1);
//	fz(i,1,n)	cout<<z1[i]<<" "<<z2[i]<<endl; 
	int r2=1,ans=0;
	fz(l1,1,n){
		while(r2<=min(l1+m-2,n)){
			t1.add(m-1-z2[r2],z2[r2]);
//			cout<<"Add "<<m-1-z2[r2]<<" "<<z2[r2]<<endl;
			t2.add(m-1-z2[r2],1);
			r2++;
		}
		ans+=(z1[l1]-m+1)*t2.query(z1[l1])+t1.query(z1[l1]);
//		cout<<(z1[l1]-m+1)*t2.query(z1[l1])+t1.query(z1[l1])<<endl;
		t1.add(m-1-z2[l1],-z2[l1]);
		t2.add(m-1-z2[l1],-1);
	}
	cout<<ans<<endl;
	return 0;
}