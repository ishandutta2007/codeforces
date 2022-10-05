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
const int MAXN=1000;
int n,a[MAXN+5],c[MAXN+5][MAXN+5];
vector<int> ps[MAXN+5];
int banl[MAXN+5],banr[MAXN+5],lft[MAXN+5];
int main(){
	scanf("%d",&n);bool flg=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) ps[a[i]].pb(i);
	vector<int> one;int cur=0;
	for(int i=1;i<=n;i++) if(ps[i].size()){
		if(ps[i].size()==1){one.pb(i);continue;}
		int stp=min((int)ps[i].size()-1,i);
		lft[i]=i-stp;
		for(int j=0;j<ps[i].size();j++){
			for(int k=0;k<stp;k++) c[cur+1+j][ps[i][(j+k)%(ps[i].size())]]=1;
		} banl[i]=cur+1;banr[i]=cur+ps[i].size();
//		printf("%d %d\n",banl[i],banr[i]);
		cur+=ps[i].size();
	}
	sort(one.begin(),one.end());
	for(int i=0;i<one.size();i++){
		int v=one[i];lft[v]=v-(i+1);banl[v]=cur+1;banr[v]=n;
		for(int j=1;j<=i+1;j++) c[cur+j][ps[v][0]]=1;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++)
		if(!(banl[i]<=j&&j<=banr[i])&&lft[i]){
			flg|=(j==n+1);bool add=1;
			for(int p:ps[i]) add&=(!c[j][p]);
			if(!add) continue;
			for(int p:ps[i]) c[j][p]=1;
			lft[i]--;
		}
	int upb=(flg)?(n+1):n;printf("%d\n",upb);
	for(int i=1;i<=upb;i++){
		for(int j=1;j<=n;j++) printf("%d",c[i][j]);
		printf("\n");
	}
	return 0;
}
/*
5
2 3 5 5 5
*/