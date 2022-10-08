#include<bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc()getchar()
	#else
		#define gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

#define ws ws_

const int N=2005;

int n,ws[30],wt[30],p[N],q[N],perm[N],pos[N];
char s[N],t[N];

vector<int>opt;
void shift(int k){
	k=n-k;
	if(k==0)return;
	static int tmp[N];
	opt.pb(k);
	fo(i,1,k)tmp[i]=perm[n-i+1];
	fo(i,k+1,n)tmp[i]=perm[i-k];
	fo(i,1,n)perm[i]=tmp[i];
}
void move(int l,int k){
	shift(k-1);
	shift(n-(k-1-l));
	shift(n-l-1);
}
int find(int u){
	fo(i,1,n)if(perm[i]==u)return i;
}

int main(){
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	fo(i,1,n)ws[s[i]-'a']++,wt[t[i]-'a']++;
	fo(i,0,25)if(ws[i]!=wt[i])puts("-1"),exit(0);
	fo(i,1,25)ws[i]+=ws[i-1],wt[i]+=wt[i-1];
	fo(i,1,n){
		p[i]=ws[s[i]-'a']--;
		q[i]=wt[t[i]-'a']--;
	}
	fo(i,1,n)pos[p[i]]=i;
	fo(i,1,n)perm[pos[q[i]]]=i;
	opt.clear();
	int l=(n+1>>1)+1,r=l-1,o=0;
	while(l!=1||r!=n){
		if(o){
			move(r-l+1,find(r+1));
			r++;
		}else{
			move(r-l+1,find(l-1));
			l--;
		}
		o^=1;
	}
	if(perm[1]!=1)shift(0);
	printf("%u\n",opt.size());
	for(int w:opt)printf("%d\n",w);
	return 0;
}