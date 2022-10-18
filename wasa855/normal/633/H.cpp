#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1<<30)-1)
#define int long long
int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(int x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=3e4+5;
int nouse[100],F[MN],a[MN],d[MN],n,s;
struct atom { int x,y,z; };
atom operator + (const atom &a,const atom &b) {
	if(!a.z) return b;
	atom ans;
	ans.x=a.x+b.x*F[a.z+1]+b.y*F[a.z];
	ans.y=a.y+b.x*F[a.z]+b.y*F[a.z-1];
	ans.z=a.z+b.z;
	ans.x%=P,ans.y%=P;
	return ans;
}
struct SMT {
	static const int N=MN<<2;
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	atom a[N];
	void upd(int k,int l,int r,int pos,int val) {
		if(l==r) {
//			cerr<<l<<' '<<val<<endl;
			
			if(val) a[k]=(atom){d[pos],0,1};
			else a[k]=(atom){0,0,0}; 
			return;
		}
		pos<=mid?upd(ls,l,mid,pos,val):upd(rs,mid+1,r,pos,val);
		a[k]=a[ls]+a[rs];
	}
	int qry() {
		return a[1].x;
	}
}tr; 

int S;
struct Qry {
	int l,r,id;
	bool operator < (const Qry &b) const {
		return l/S==b.l/S?(l/S&1?r<b.r:r>b.r):l<b.l;	
	}
}q[MN];
int ans[MN],cnt[MN];
void add(int x) {
	
	if(cnt[x]==0) tr.upd(1,1,n,x,1);
	cnt[x]++;
}
void del(int x) {
	cnt[x]--;
	if(cnt[x]==0) tr.upd(1,1,n,x,0);
}
signed main() {
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),P=read(); S=sqrt(n);
	F[1]=F[2]=1; For(i,3,n) F[i]=add(F[i-1],F[i-2]);
	For(i,1,n) d[i]=a[i]=read(); sort(d+1,d+1+n);
	For(i,1,n) a[i]=lower_bound(d+1,d+1+n,a[i])-d;
	For(i,1,n) d[i]%=P;
	int m=read();
	For(i,1,m) {
		q[i].l=read(),q[i].r=read(),q[i].id=i;
	}
	sort(q+1,q+1+m);
	int L=1,R=0;
	For(i,1,m) {
		int l=q[i].l,r=q[i].r,id=q[i].id;
		while(L>l) add(a[--L]);
		while(R<r) add(a[++R]);
		while(L<l) del(a[L++]);
		while(R>r) del(a[R--]);
		ans[id]=tr.qry();
	}
	For(i,1,m) {
		printf("%lld\n",ans[i]);
	}
	return FastIO::Fflush(),0;
}
/*
?t??? 1??? 12?
*/