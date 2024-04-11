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
const int MAXN=1e5;
const int MAXP=1<<18;
const int pr=3;
const int ipr=332748118;
const int MOD=998244353;
int inv[MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int rev[MAXP+5],A[MAXP+5],B[MAXP+5],C[MAXP+5];
void NTT(int *a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
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
vector<int> conv(vector<int> x,vector<int> y){
	if(x.size()+y.size()<=16){
		vector<int> res(x.size()+y.size()-1);
		for(int i=0;i<x.size();i++) for(int j=0;j<y.size();j++)
			res[i+j]=(res[i+j]+1ll*x[i]*y[j])%MOD;
		return res;
	}
	int LEN=1;while(LEN<x.size()+y.size()) LEN<<=1;
	for(int i=0;i<LEN;i++) A[i]=B[i]=C[i]=0;
	for(int i=0;i<x.size();i++) A[i]=x[i];
	for(int i=0;i<y.size();i++) B[i]=y[i];
	NTT(A,LEN,1);NTT(B,LEN,1);
	for(int i=0;i<LEN;i++) C[i]=1ll*A[i]*B[i]%MOD;NTT(C,LEN,-1);
	vector<int> res;for(int i=0;i<x.size()+y.size()-1;i++) res.pb(C[i]);
	return res;
}
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;ll X;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],wson[MAXN+5],fa[MAXN+5];
void dfs0(int x,int f){
	siz[x]=1;fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs0(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
vector<vector<int> > p;
vector<int> dp[MAXN+5];
void addzero(vector<int> &v){
	v.pb(0);
	for(int i=(int)(v.size())-2;~i;i--) swap(v[i],v[i+1]);
}
vector<int> plus_one(vector<int> v){(v[0]+=1)%=MOD;return v;}
vector<int> minus_one(vector<int> v){(v[0]+=MOD-1)%=MOD;return v;}
vector<int> plus_vec(vector<int> a,vector<int> b){
	if(a.size()<b.size()) swap(a,b);b.resize(a.size(),0);
	for(int i=0;i<a.size();i++) (a[i]+=b[i])%=MOD;
	return a;
}
pair<vector<int>,vector<int> > solve(int l,int r){
	if(l==r) return mp(plus_one(p[l]),p[l]);int mid=l+r>>1;
	pair<vector<int>,vector<int> > L=solve(l,mid);
	pair<vector<int>,vector<int> > R=solve(mid+1,r);
//	printf("%d %d %d %d!!!\n",L.fi.size(),L.se.size(),R.fi.size(),R.se.size());
	return mp(plus_vec(conv(minus_one(L.fi),R.se),R.fi),conv(L.se,R.se));
}
void dfs(int x){
	if(!wson[x]) return dp[x]=vector<int>(2,1),void();
	for(int y=x;y;y=wson[y]){
		for(int e=hd[y];e;e=nxt[e]){
			int z=to[e];if(z==fa[y]||z==wson[y]) continue;
			dfs(z);
		}
	} p.clear();
	for(int y=x;y;y=wson[y]){
		bool flg=0;
		for(int e=hd[y];e;e=nxt[e]){
			int z=to[e];if(z==fa[y]||z==wson[y]) continue;
			addzero(dp[z]);p.pb(dp[z]);flg=1;
		} if(!flg) p.pb(minus_one(vector<int>(2,1)));
	} assert(!p.empty());reverse(p.begin(),p.end());
	dp[x]=solve(0,p.size()-1).fi;//printf("%d: ",x);
//	for(int i=0;i<dp[x].size();i++) printf("%d ",dp[x][i]);
//	printf("!\n");
}
int main(){
	scanf("%d%lld",&n,&X);X%=MOD;
	for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);adde(u,v),adde(v,u);}
	dfs0(1,0);dfs(1);int ans=0;
	for(int i=(inv[0]=inv[1]=1)+1;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
//	for(int i=0;i<dp[1].size();i++) printf("%d%c",dp[1][i]," \n"[i+1==dp[1].size()]);
	for(int i=1,t=1;i<dp[1].size();i++){
		ans=(ans+1ll*dp[1][i]*t)%MOD;
		t=1ll*t*(X+i)%MOD*inv[i]%MOD;
	} printf("%d\n",ans);
	return 0;
}