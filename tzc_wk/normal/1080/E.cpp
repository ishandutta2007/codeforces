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
const int MAXN=250;
const int MOD1=469762049;
const int MOD2=1004535809;
const int ALPHA=26;
int hsbase,pw1[ALPHA+2],pw2[ALPHA+2];
bool ispri(int x){
	for(int i=2;i*i<=x;i++) if(!(x%i)) return 0;
	return 1;
}
int n,m;char s[MAXN+5][MAXN+5];
int hs1[MAXN+5],hs2[MAXN+5],cnt[MAXN+5][ALPHA+2],odd[MAXN+5];
pii a[MAXN*2+5];int mx[MAXN*2+5];ll ans=0;
int main(){
	scanf("%d%d",&n,&m);srand(time(0));
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	hsbase=rand()%100+250;while(!ispri(hsbase)) ++hsbase;
	pw1[0]=1;for(int i=1;i<=ALPHA;i++) pw1[i]=1ll*pw1[i-1]*hsbase%MOD1;
	pw2[0]=1;for(int i=1;i<=ALPHA;i++) pw2[i]=1ll*pw2[i-1]*hsbase%MOD2;
	for(int l=1;l<=m;l++){
		memset(hs1,0,sizeof(hs1));memset(hs2,0,sizeof(hs2));
		memset(cnt,0,sizeof(cnt));memset(odd,0,sizeof(odd));
		for(int r=l;r<=m;r++){
			for(int i=1;i<=n;i++){
				cnt[i][s[i][r]-'a']++;
				hs1[i]=(hs1[i]+pw1[s[i][r]-'a'])%MOD1;
				hs2[i]=(hs2[i]+pw2[s[i][r]-'a'])%MOD2;
				if(cnt[i][s[i][r]-'a']&1) odd[i]++;
				else odd[i]--;
			} int len=0,t=0;a[0]=mp(MOD1+1,MOD2+1);
			for(int i=1;i<=n;i++){
				a[++len]=mp(MOD1,MOD2);
				if(odd[i]>=2) --t,a[++len]=mp(t,t);
				else a[++len]=mp(hs1[i],hs2[i]);
			} a[++len]=mp(MOD1,MOD2);memset(mx,0,sizeof(mx));
			int R=0,pos=0;
			for(int i=1;i<=len;i++){
				if(i<=R) mx[i]=min(R-i,mx[pos*2-i]);
				while(a[i+mx[i]]==a[i-mx[i]]) mx[i]++;
				if(i+mx[i]-1>R) R=i+mx[i]-1,pos=i;
				if((i&1)||odd[i>>1]<2) ans+=mx[i]>>1;
			}
		}
	} printf("%lld\n",ans);
	return 0;
}
/*
3 3
aaa
aaa
aba
*/