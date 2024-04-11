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
int n=read(),t=read();
int a[200005],sum[200005];
int key[400005],cnt0=0,hs[400005],cnt=0;
inline int get(int x){
	return lower_bound(hs+1,hs+cnt+1,x)-hs;
}
struct Fenwick_Tree{
	int bit[1500005];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int x,int val){
//		cout<<"Add "<<x<<endl;
		for(int i=x;i<=400005;i+=lowbit(i))	bit[i]+=val;
	}
	inline int query(int x){
//		cout<<"Query "<<x<<endl;
		int ans=0;
		for(int i=x;i;i-=lowbit(i))	ans+=bit[i];
		return ans;
	}
} tr;
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	sum[i]=sum[i-1]+a[i],key[++cnt0]=sum[i],key[++cnt0]=sum[i]-t;
	key[++cnt0]=0;
	key[0]=-0x3f3f3f3f3f3f3f3fll;
	sort(key+1,key+cnt0+1);
	fz(i,1,cnt0){
		if(key[i]!=key[i-1]){
			hs[++cnt]=key[i];
		}
	}
	tr.add(get(0),1);
	int ans=0;
	fz(i,1,n){
		ans+=i-tr.query(get(sum[i]-t));
		tr.add(get(sum[i]),1);
	}
	cout<<ans<<endl;
	return 0;
}