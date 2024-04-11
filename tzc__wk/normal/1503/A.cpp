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
const int MAXN=2e5;
int n;char s[MAXN+5],s1[MAXN+5],s2[MAXN+5];
void solve(){
	scanf("%d%s",&n,s+1);int c0=0;s1[n+1]=s2[n+1]='\0';
	for(int i=1;i<=n;i++) if(s[i]=='0') c0++;
	if(c0&1) return puts("NO"),void();
	for(int i=1,cc=(n-c0)/2;i<=n;i++){
		if(s[i]=='1'){
			if(cc) s1[i]=s2[i]='(',cc--;
			else s1[i]=s2[i]=')';
		}
	}
	int msk=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			if(msk) s1[i]='(',s2[i]=')';
			else s1[i]=')',s2[i]='(';
			msk^=1;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=(s1[i]=='(')?1:-1;
		if(sum<0) return puts("NO"),void();
	}
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=(s2[i]=='(')?1:-1;
		if(sum<0) return puts("NO"),void();
	}
	printf("YES\n%s\n%s\n",s1+1,s2+1);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}