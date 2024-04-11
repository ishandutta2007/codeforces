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
const int MAXN=16;
const int MAXV=2000;
const int MAXP=1<<MAXN;
int n,k,a[MAXN+5],b[MAXN+5],sum=0;
bitset<MAXV+5> bt[MAXP+5];
void getstate(int st,int x){
//	printf("%d %d\n",st,x);
	if(!st) return;
	if(x*k<=sum&&bt[st][x*k]){
		for(int i=1;i<=n;i++) if(st>>i-1&1) b[i]++;
		getstate(st,x*k);return;
	}
	for(int i=1;i<=n;i++) if(st>>i-1&1){
		if(x-a[i]>=0&&bt[st^1<<i-1][x-a[i]]){
			getstate(st^1<<i-1,x-a[i]);return;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	bt[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++) if(i>>j-1&1) bt[i]|=bt[i^1<<j-1]<<a[j];
		for(int j=sum/k;j;j--) if(bt[i][j*k]) bt[i][j]=1;
	}
	if(!bt[(1<<n)-1][1]) puts("NO");
	else{
		puts("YES");getstate((1<<n)-1,1);
		priority_queue<pii> q;
		for(int i=1;i<=n;i++) q.push(mp(b[i],a[i]));
		while(q.size()>1){
			pii p1=q.top();q.pop();
			pii p2=q.top();q.pop();
			printf("%d %d\n",p1.se,p2.se);
			p1.se+=p2.se;
			while(p1.se%k==0) p1.se/=k,p1.fi--;
			q.push(p1);
		}
	}
	return 0;
}