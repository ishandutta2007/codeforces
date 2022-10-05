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
const int MAXP=1<<6;
const int AL=6;
char s[MAXN+5],ans[MAXN+5];bool is[MAXN+5];
int n,cnt[AL+2],sum[MAXN+5][MAXP+3],can[MAXN+5];
bool check(int x,int y){
	cnt[y]--;
	for(int i=0;i<MAXP;i++){
		int ss=0,num=n-x-sum[x+1][(MAXP-1)^i];
		for(int j=0;j<AL;j++) if(i>>j&1) ss+=cnt[j];
		if(num<ss) return cnt[y]++,0;
	} return 1;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
	int tzc_is_juruo;scanf("%d",&tzc_is_juruo);
	while(tzc_is_juruo--){
		int pos;static char buf[AL+2];
		scanf("%d%s",&pos,buf+1);is[pos]=1;
		int len=strlen(buf+1),msk=0;
		for(int i=1;i<=len;i++) msk|=(1<<buf[i]-'a');
		for(int i=0;i<MAXP;i++) if((i&msk)==msk) sum[pos][i]++;
		can[pos]=msk;
	}
	for(int i=1;i<=n;i++) if(!is[i]) sum[i][MAXP-1]++,can[i]=MAXP-1;
	for(int i=n;i;i--) for(int j=0;j<MAXP;j++) sum[i][j]+=sum[i+1][j];
	for(int i=1;i<=n;i++){
		for(int j=0;j<AL;j++) if(cnt[j]&&(can[i]>>j&1)&&check(i,j)){
			ans[i]=j+'a';break;
		}
		if(!ans[i]){puts("Impossible");return 0;}
	}
	printf("%s\n",ans+1);
	return 0;
}