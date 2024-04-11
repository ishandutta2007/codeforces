//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=500;
int n,siz[MAXN+5],ord[MAXN+5];set<int> st;
bool cmp(int x,int y){return siz[x]<siz[y];}
bool check(int x,int l,int r){
	set<int>::iterator it=st.begin();
	for(int i=1;i<l;i++) ++it;printf("%d\n",r-l+1);
	for(int i=1;i<=r-l+1;i++) printf("%d%c",*it++," \n"[i==r-l+1]);
	printf("1\n1\n%d\n",x);fflush(stdout);
	int t;scanf("%d",&t);return t>0;
}
int main(){
	scanf("%d",&n);siz[1]=n;
	for(int i=2;i<=n;i++){
		printf("%d\n",n-1);
		for(int j=2;j<=n;j++) printf("%d%c",j," \n"[j==n]);
		printf("1\n1\n%d\n",i);fflush(stdout);
		scanf("%d",&siz[i]);
	} for(int i=1;i<=n;i++) ord[i]=i;sort(ord+1,ord+n+1,cmp);
	vector<pii> ans;
	for(int i=1;i<n;i++){
		if(!st.empty()){
			int cur=0;vector<int> son;
			while(cur<st.size()){
				int l=cur+1,r=st.size(),p=st.size()+1;
				while(l<=r){
					int mid=l+r>>1;
					if(check(ord[i],cur+1,mid)) p=mid,r=mid-1;
					else l=mid+1;
				} if(p!=st.size()+1){
					set<int>::iterator it=st.begin();
					for(int j=1;j<p;j++) ++it;
					son.pb(*it);
				} cur=p;
			} for(int x:son) st.erase(st.find(x)),ans.pb(mp(x,ord[i]));
		} st.insert(ord[i]);
	} printf("ANSWER\n");
	for(int x:st) ans.pb(mp(x,1));
	for(pii p:ans) printf("%d %d\n",p.fi,p.se);
	fflush(stdout);
	return 0;
}