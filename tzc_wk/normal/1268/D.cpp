//Created time: 2022/3/27 9:44:19
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=2000;
int n,a[MAXN+5][MAXN+5],tmp[MAXN+5][MAXN+5],deg[MAXN+5],tmp_deg[MAXN+5];
bool check(){
	sort(tmp_deg+1,tmp_deg+n+1);int sum=0;
	for(int i=1;i<=n;i++){
		sum+=tmp_deg[i];
		if(i!=n&&sum==i*(i-1)/2) return 0;
	}
	return 1;
}
void flip(int x){
	for(int i=1;i<=n;i++) if(x^i){
		if(tmp[x][i]) tmp_deg[x]--,tmp_deg[i]++;
		else tmp_deg[i]--,tmp_deg[x]++;
		swap(tmp[x][i],tmp[i][x]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		scanf("%1d",&a[i][j]);tmp[i][j]=a[i][j];
		if(a[i][j]) deg[i]++;
	}
	memcpy(tmp_deg,deg,sizeof(deg));
	if(check()) return puts("0 1"),0;
	else if(n<=6){
		int mn=114514,cnt=0;
		for(int i=0;i<(1<<n);i++){
			memcpy(tmp,a,sizeof(tmp));
			memcpy(tmp_deg,deg,sizeof(deg));
			for(int j=1;j<=n;j++) if(i>>(j-1)&1) flip(j);
			if(check()){
//				printf("! %d\n",i);
				if(mn>__builtin_popcount(i)) mn=__builtin_popcount(i),cnt=1;
				else if(mn==__builtin_popcount(i)) cnt++;
			}
		}
		if(mn==114514) puts("-1");
		else{
			for(int i=1;i<=mn;i++) cnt*=i;
			printf("%d %d\n",mn,cnt);
		}
	} else {
		int cnt=0;
		for(int i=1;i<=n;i++){
			memcpy(tmp_deg,deg,sizeof(deg));
			flip(i);if(check()) cnt++;flip(i);
		}
		printf("1 %d\n",cnt);
	}
	return 0;
}