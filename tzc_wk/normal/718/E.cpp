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
const int MAXP=256;
const int INF=1061109567;
int n,cnt[MAXP+2][9];char s[MAXN+5];
int dis[MAXN+15][9],disc[9][9],res=0;ll resc=0;
void merge(int x,int y){
//	printf("%d %d\n",x,y);
	if(x>res) res=x,resc=y;
	else if(x==res) resc+=y;
}
int main(){
	scanf("%d%s",&n,s+1);
	memset(dis,63,sizeof(dis));memset(disc,63,sizeof(disc));
	for(int i=0;i<8;i++){
		deque<int> q;
		for(int j=1;j<=n;j++) if(s[j]-'a'==i) dis[j][i]=0,q.push_back(j);
		while(!q.empty()){
			int x=q.front();q.pop_front();
			if(x<=n){
				if(x-1>=1&&dis[x-1][i]==INF) dis[x-1][i]=dis[x][i]+1,q.push_back(x-1);
				if(x+1<=n&&dis[x+1][i]==INF) dis[x+1][i]=dis[x][i]+1,q.push_back(x+1);
				if(dis[s[x]-'a'+n+1][i]==INF) dis[s[x]-'a'+n+1][i]=dis[x][i]+1,q.push_back(s[x]-'a'+n+1);
			} else {
				for(int j=1;j<=n;j++) if(s[j]-'a'==x-n-1)
					if(dis[j][i]>=dis[x][i]) dis[j][i]=dis[x][i],q.push_front(j);
			}
		} for(int j=1;j<=n;j++) chkmin(disc[s[j]-'a'][i],dis[j][i]);
//		for(int j=1;j<=n;j++) printf("%d%c",dis[j][i]," \n"[j==n]);
	}
//	for(int i=0;i<8;i++) for(int j=0;j<8;j++)
//		printf("%d%c",disc[i][j]," \n"[j==7]);
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-15);j<=i;j++){
			int mn=i-j;
			for(int k=0;k<8;k++) chkmin(mn,dis[j][k]+dis[i][k]+1);
			merge(mn,1);
		} if(i-16>=1){
			int msk=0;
			for(int j=0;j<8;j++) msk|=(dis[i-16][j]-disc[s[i-16]-'a'][j])<<j;
			cnt[msk][s[i-16]-'a']++;
		} for(int j=0;j<MAXP;j++) for(int k=0;k<8;k++) if(cnt[j][k]){
			int mn=INF;
			for(int l=0;l<8;l++) chkmin(mn,dis[i][l]+disc[k][l]+(j>>l&1)+1);
			merge(mn,cnt[j][k]);
		}
	} printf("%d %lld\n",res,resc);
	return 0;
}