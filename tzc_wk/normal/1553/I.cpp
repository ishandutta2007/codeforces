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
#define mt make_tuple
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
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MAXP=1<<18;
const int pr=3;
const int ipr=332748118;
const int MOD=998244353;
const int INV2=499122177;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int rev[MAXP+5];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			for(int k=0,w=1;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*w*a[(i>>1)+j+k]%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	} if(!~type){
		int ivn=qpow(len,MOD-2);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*ivn%MOD;
	}
}
vector<int> conv(vector<int> a,vector<int> b){
	int LEN=1;while(LEN<a.size()+b.size()) LEN<<=1;
	a.resize(LEN,0);b.resize(LEN,0);NTT(a,LEN,1);NTT(b,LEN,1);
	for(int i=0;i<LEN;i++) a[i]=1ll*a[i]*b[i]%MOD;NTT(a,LEN,-1);
	return a;
}
int n,m,a[MAXN+5],b[MAXN+5],fac[MAXN+5];
void init_fac(int n){for(int i=(fac[0]=1);i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;}
struct dat{
	vector<int> v[2][2];
	void resize(int x){
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			v[i][j].resize(x+1);
	}
	vector<int>* operator [](int x){return v[x];}
};
dat solve(int l,int r){
	if(r-l+1<=3){
		dat ret;ret.resize(r-l+1);
		if(r-l+1==2){
			ret[b[l]][b[r]][2]=(b[l]+1)*(b[r]+1);
			ret[1][1][1]=2;
		} else {
			ret[b[l]][b[r]][3]=(b[l]+1)*(b[r]+1)*(b[l+1]+1);
			ret[b[l]][1][2]=(b[l]+1<<1);ret[1][b[r]][2]+=(b[r]+1<<1);
			ret[1][1][1]=2;
		} return ret;
	} int mid=l+r>>1;
	dat L=solve(l,mid),R=solve(mid+1,r);
	dat ret;ret.resize(r-l+1);
	for(int i=0;i<2;i++) for(int j=0;j<2;j++){
		for(int x=0;x<2;x++) for(int y=0;y<2;y++){
			vector<int> tmp=conv(L[i][x],R[y][j]);
//			printf("%d %d %d %d\n",i,x,y,j);
			for(int t=1;t<=r-l+1;t++) ret[i][j][t]=(ret[i][j][t]+tmp[t])%MOD;
			for(int t=1;t<=r-l;t++){
				if(x+y==2) ret[i][j][t]=(ret[i][j][t]+1ll*tmp[t+1]*INV2)%MOD;
				else if(x+y==1) ret[i][j][t]=(ret[i][j][t]+tmp[t+1])%MOD;
				else ret[i][j][t]=(ret[i][j][t]+2ll*tmp[t+1])%MOD;
			}
		}
	} return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int l=1,r;l<=n;l=r){
		r=l;while(a[l]==a[r]) ++r;
		if((r-l)%a[l]) return puts("0"),0;
		for(int j=1;j<=(r-l)/a[l];j++) b[++m]=(a[l]>1);
	} init_fac(m);
	if(m==1) return printf("%d\n",(b[1])?2:1),0;
	dat res=solve(1,m);int ans=0;
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=0;j<2;j++) for(int k=0;k<2;k++) sum=(sum+res[j][k][i])%MOD;
		if((m-i)&1) ans=(ans-1ll*sum*fac[i]%MOD+MOD)%MOD;
		else ans=(ans+1ll*sum*fac[i])%MOD;
	} printf("%d\n",ans);
	return 0;
}