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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1000;
const int MAXD=50;
const int MAXNODE=1e5;
const int MOD=1e9+7;
int n,d;char s[MAXN+5],s1[MAXD+5],s2[MAXD+5];
int ch[MAXNODE+5][11],fail[MAXNODE+5],is[MAXNODE+5],ncnt=0;
int dp[MAXD+5][MAXNODE+5][2][2];
void add(int &x,int v){((x+=v)>=MOD)&&(x-=MOD);}
void getfail(){
	queue<int> q;
	for(int i=0;i<10;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<10;i++){
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],is[ch[x][i]]|=is[fail[ch[x][i]]],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int solve(char *t){
	memset(dp,0,sizeof(dp));dp[0][0][1][0]=1;
	for(int i=0;i<d;i++) for(int j=0;j<=ncnt;j++) for(int k=0;k<2;k++)
		for(int l=0;l<2;l++){
			int up=(k)?(t[i+1]-'0'):9;
			for(int o=0;o<=up;o++){
				add(dp[i+1][ch[j][o]][k&&(o==up)][l|is[ch[j][o]]],dp[i][j][k][l]);
			}
		}
	int ans=0;
	for(int j=0;j<=ncnt;j++) add(ans,dp[d][j][0][1]),add(ans,dp[d][j][1][1]);
	return ans;
}
int main(){
	scanf("%s%s%s",s+1,s1+1,s2+1);
	n=strlen(s+1);d=strlen(s1+1);
	for(int i=1;i<=n-(d>>1)+1;i++){
		int cur=0;
		for(int j=1;j<=d&&j+i-1<=n;j++){
			if(!ch[cur][s[j+i-1]-'0']) ch[cur][s[j+i-1]-'0']=++ncnt;
			cur=ch[cur][s[j+i-1]-'0'];if(j>=(d>>1)) is[cur]=1;
		}
	} getfail();int ret=solve(s2)-solve(s1);
	if(ret<0) ret+=MOD;int cur=0;
	for(int i=1;i<=d;i++){
		cur=ch[cur][s1[i]-'0'];
		if(is[cur]){(ret+=1)%=MOD;break;}
	} printf("%d\n",ret);
	return 0;
}