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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=500;
const int MAXP=1<<16;
const int MOD=1e9+7;
int n,m,dp[MAXN+5][MAXP+5],rt;char s[MAXN+5];
int mch[MAXN+5],op[MAXN+5],ncnt=0,ch[MAXN+5][2];
int must[16],msk[8];
int build(int l,int r){
//	printf("%d %d\n",l,r);
	if(l==r){
		int id=++ncnt;
		if(s[l]>='A'&&s[l]<='D') op[id]=s[l]-'A';
		else if(s[l]>='a'&&s[l]<='d') op[id]=s[l]-'a'+4;
		else op[id]=8;return id;
	}
	if(s[r]==')'){
		if(mch[r]==l) return build(l+1,r-1);
		else{
			int id=++ncnt,pos=mch[r]-1;
			if(s[pos]=='&') op[id]=0;
			else if(s[pos]=='|') op[id]=1;
			else op[id]=2;
			ch[id][0]=build(l,pos-1);
			ch[id][1]=build(pos+1,r);
			return id;
		}
	} else {
		int id=++ncnt,pos=r-1;
		if(s[pos]=='&') op[id]=0;
		else if(s[pos]=='|') op[id]=1;
		else op[id]=2;
		ch[id][0]=build(l,pos-1);
		ch[id][1]=build(pos+1,r);
		return id;
	}
}
int tmp1[MAXP+5],tmp2[MAXP+5];
void FWTor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<len;j+=i){
			for(int k=0;k<(i>>1);k++){
				a[(i>>1)+j+k]=(a[(i>>1)+j+k]+1ll*type*a[j+k])%MOD;
			}
		}
	}
}
void FWTand(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1){
		for(int j=0;j<len;j+=i){
			for(int k=0;k<(i>>1);k++){
				a[j+k]=(a[j+k]+1ll*type*a[(i>>1)+j+k])%MOD;
			}
		}
	}
}
void dfs(int x){
	if(!ch[x][0]){
//		printf("%d\n",op[x]);
		if(op[x]<=7) dp[x][msk[op[x]]]++;
		else for(int i=0;i<=7;i++) dp[x][msk[i]]++;
		return;
	}
	dfs(ch[x][0]);dfs(ch[x][1]);
	if(op[x]!=1){
		for(int i=0;i<(1<<16);i++) tmp1[i]=dp[ch[x][0]][i];
		for(int i=0;i<(1<<16);i++) tmp2[i]=dp[ch[x][1]][i];
		FWTand(tmp1,1<<16,1);FWTand(tmp2,1<<16,1);
		for(int i=0;i<(1<<16);i++) tmp1[i]=1ll*tmp1[i]*tmp2[i]%MOD;
		FWTand(tmp1,1<<16,MOD-1);
		for(int i=0;i<(1<<16);i++) dp[x][i]=(dp[x][i]+tmp1[i])%MOD;
	}
	if(op[x]){
		for(int i=0;i<(1<<16);i++) tmp1[i]=dp[ch[x][0]][i];
		for(int i=0;i<(1<<16);i++) tmp2[i]=dp[ch[x][1]][i];
		FWTor(tmp1,1<<16,1);FWTor(tmp2,1<<16,1);
		for(int i=0;i<(1<<16);i++) tmp1[i]=1ll*tmp1[i]*tmp2[i]%MOD;
		FWTor(tmp1,1<<16,MOD-1);
		for(int i=0;i<(1<<16);i++) dp[x][i]=(dp[x][i]+tmp1[i])%MOD;
	}
}
int main(){
	scanf("%s%d",s+1,&m);n=strlen(s+1);
	for(int i=0;i<16;i++){
		int a=i&1,b=i>>1&1,c=i>>2&1,d=i>>3&1;
		msk[0]|=(a<<i);msk[1]|=(b<<i);
		msk[2]|=(c<<i);msk[3]|=(d<<i);
		msk[4]|=((!a)<<i);msk[5]|=((!b)<<i);
		msk[6]|=((!c)<<i);msk[7]|=((!d)<<i);
	}
//	for(int i=0;i<8;i++) printf("%d\n",msk[i]);
	stack<int> stk;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') stk.push(i);
		else if(s[i]==')') mch[i]=stk.top(),stk.pop();
	} rt=build(1,n);dfs(rt);
	memset(must,-1,sizeof(must));
	for(int i=1;i<=m;i++){
		int a,b,c,d,e;scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int t=a+(b<<1)+(c<<2)+(d<<3);must[t]=e;
	} int ans=0;
	for(int i=0;i<(1<<16);i++){
		bool flg=1;
		for(int j=0;j<16;j++) if(must[j]!=-1&&((i>>j&1)!=must[j]))
			flg=0;
		if(flg) ans=(ans+dp[rt][i])%MOD;
	} printf("%d\n",ans);
	return 0;
}