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
int n=read(),a[26],b[26],c[26],mid=1;
int ans=-0x3f3f3f3f,st1=0,st2=0;
const int HSB=100000000;
const int MOD=19260817;
struct hashtable{
	int head[19260817],pre[2000005],st[2000005];
	int v[2000005][3],cnt=0;
	inline void insert(int a,int b,int c,int sta){
		int hs=((b-a)%MOD+MOD)%MOD;
//		cout<<a<<" "<<b<<" "<<c<<endl;
		for(int i=head[hs];i;i=pre[i]){
			if(v[i][0]==a&&v[i][1]==b&&v[i][2]==c)	return;
		}
//		cout<<a<<" "<<b<<" "<<c<<" "<<hs<<endl;
		pre[++cnt]=head[hs];
		head[hs]=cnt;
		v[cnt][0]=a;
		v[cnt][1]=b;
		v[cnt][2]=c;
		st[cnt]=sta;
	}
	inline void update(int a,int b,int c,int sta){
		int hs=((a-b)%MOD+MOD)%MOD;
//		cout<<a<<" "<<b<<" "<<c<<" "<<hs<<endl;
		for(int i=head[hs];i;i=pre[i]){
			if(ans<v[i][0]+a&&v[i][2]-v[i][1]==b-c){
				ans=v[i][0]+a;
				st1=st[i];
				st2=sta;
			}
		} 
	}
} hst;
inline void dfs(int x,int mx,int sa,int sb,int sc,int sta,int id){
	if(x==mx+1){
//		cout<<sa<<" "<<sb<<" "<<sc<<endl;
		if(id==0)	hst.insert(sa,sb,sc,sta);
		else		hst.update(sa,sb,sc,sta);
		return;
	}
	dfs(x+1,mx,sa,sb+b[x],sc+c[x],sta*3,id);
	dfs(x+1,mx,sa+a[x],sb,sc+c[x],sta*3+1,id);
	dfs(x+1,mx,sa+a[x],sb+b[x],sc,sta*3+2,id);
}
int t[26];
signed main(){
	fz(i,1,n)	a[i]=read(),b[i]=read(),c[i]=read();
	mid=(n+1)>>1;
	dfs(1,mid,0,0,0,0,0);
	dfs(mid+1,n,0,0,0,0,1);
	if(ans==-0x3f3f3f3f)	puts("Impossible");
	else{
//		cout<<ans<<endl;
		fd(i,mid,1){
			t[i]=st1%3;st1/=3;
		}
		fd(i,n,mid+1){
			t[i]=st2%3;st2/=3;
		}
		fz(i,1,n){
			if(t[i]==0)	puts("MW");
			if(t[i]==1)	puts("LW");
			if(t[i]==2)	puts("LM");
		}
	}
	return 0;
}