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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,pr[MAXN/10],prcnt=0;
bitset<MAXN/2+5> vis;
bitset<MAXN+5> hav;
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&i*pr[j]<=n;j++){
			vis[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}
int main(){
	scanf("%d",&n);sieve(n>>1);
	vector<pii> ans;
	for(int i=prcnt;i;i--){
		vector<int> v;
		for(int j=pr[i];j<=n;j+=pr[i]) if(!hav[j]) v.pb(j);
		if(v.size()&1){
			ans.pb(mp(v[0],v[2]));hav[v[0]]=hav[v[2]]=1;
			for(int j=3;j<v.size();j+=2){
				hav[v[j]]=hav[v[j+1]]=1;
				ans.pb(mp(v[j],v[j+1]));
			}
		} else {
			for(int j=0;j<v.size();j+=2){
				hav[v[j]]=hav[v[j+1]]=1;
				ans.pb(mp(v[j],v[j+1]));
			}
		}
	} printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}