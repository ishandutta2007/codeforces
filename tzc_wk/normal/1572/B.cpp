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
const int MAXN=2e5;
int n,a[MAXN+5];vector<int> res;
void oper(int x){
	int sum=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=sum;
	res.pb(x);
}
void solve(){
	scanf("%d",&n);int sum=0,flg=1;res.clear();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],flg&=a[i];
	a[n+1]=0;if((sum&1)||flg) return puts("NO"),void();
	int msk=0;vector<pii> vec;bool rev=0;
	for(int l=1,r;l<=n;l=r){
		if(a[l]){
			r=l;while(a[r]) ++r;
			vec.pb(mp(l,r-1));
		} else r=l+1;
	}
	for(int i=0;i<vec.size();i++){
		if((vec[i].se-vec[i].fi+1)&1){
//			printf("%d %d\n",vec[i].fi,vec[i].se);
			if(i==(int)(vec.size())-1) assert(0);
			if(~(vec[i+1].fi-vec[i].se)&1){
				for(int j=vec[i].se;j<vec[i+1].fi;j+=2) oper(j);
				for(int j=vec[i+1].fi-4;j>=vec[i].fi;j-=2) oper(j);
				vec[i+1].fi++;
			} else {
				if(vec[i].fi!=1){
					for(int j=vec[i].se;j<vec[i+1].fi-1;j+=2) oper(j);
					for(int j=vec[i].fi-1;j<vec[i+1].fi;j+=2) oper(j);
					vec[i+1].fi++;
				} else if(vec[i+1].se!=n){
					for(int j=vec[i].se;j<vec[i+1].fi-1;j+=2) oper(j);
					if((vec[i+1].se-vec[i+1].fi+1)&1){
						for(int j=vec[i+1].se-1;j>=vec[i].fi;j-=2) oper(j);
						vec[i+1]=mp(1,0);
					} else vec[i+1]=mp(vec[i].fi,vec[i+1].se);
				} else return puts("NO"),void();
			}
		} else {
			if(vec[i].se==n) for(int j=vec[i].fi-1;j<vec[i].se;j+=2) oper(j);
			else for(int j=vec[i].se-1;j>=vec[i].fi;j-=2) oper(j);
		}
	} printf("YES\n%llu\n",res.size());
	for(int x:res) printf("%d ",(rev)?(n-1-x):x);printf("\n");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}
/*
1
9
1 0 0 0 1 0 1 0 1

1
8
0 1 1 1 0 0 1 0

1
6
1 0 1 1 0 1

1
10
1 0 0 1 0 0 1 0 0 1
*/