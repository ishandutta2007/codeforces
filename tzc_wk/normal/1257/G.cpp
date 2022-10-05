//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXP=1<<19;
const int MAXV=3e6;
const int pr=3;
const int ipr=332748118;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,cnt[MAXV+5];
struct poly{
	vector<int> vec;int p;
	bool operator <(poly rhs) const{
		if(vec.size()^rhs.vec.size()) return vec.size()>rhs.vec.size();
		return p>rhs.p;//otherwise there will be some mysterious problems
	}
};
priority_queue<poly> q;
int rev[MAXP+5];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2,l=1;i<=len;i<<=1,l++){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			for(int k=0,w=1;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*a[(i>>1)+j+k]*w%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(!~type){
		int ivn=qpow(len,MOD-2);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*ivn%MOD;
	}
}
poly conv(poly x,poly y){
	if(x.vec.size()+y.vec.size()<=16){
		poly res;res.p=min(x.p,y.p);
		res.vec.resize(x.vec.size()+y.vec.size()-1,0);
		for(int i=0;i<x.vec.size();i++) for(int j=0;j<y.vec.size();j++)
			res.vec[i+j]=(res.vec[i+j]+1ll*x.vec[i]*y.vec[j])%MOD;
		return res;
	}
	int LEN=1;while(LEN<x.vec.size()+y.vec.size()) LEN<<=1;
	x.vec.resize(LEN,0);y.vec.resize(LEN,0);poly res;
	NTT(x.vec,LEN,1);NTT(y.vec,LEN,0);
	res.vec.resize(LEN,0);res.p=min(x.p,y.p);
	for(int i=0;i<LEN;i++) res.vec[i]=1ll*x.vec[i]*y.vec[i]%MOD;
	NTT(res.vec,LEN,-1);
	while(res.vec.size()>=x.vec.size()+y.vec.size())
		res.vec.pop_back();
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=MAXV;i++) if(cnt[i]){
		poly cur;cur.p=i;
		for(int j=0;j<=cnt[i];j++) cur.vec.pb(1);
		q.push(cur);
	}
	while(q.size()>1){
		poly x=q.top();q.pop();
		poly y=q.top();q.pop();
		q.push(conv(x,y));
	} printf("%d\n",q.top().vec[n>>1]);
	return 0;
}