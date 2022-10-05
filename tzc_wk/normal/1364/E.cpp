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
const int MAXN=2055;
int n,cnt[MAXN+5],res[MAXN+5],ans[MAXN+5];
int query(int x,int y){
	printf("? %d %d\n",x+1,y+1);fflush(stdout);
	int z;scanf("%d",&z);return z;
}
int main(){
	scanf("%d",&n);srand(20210910234852ll&4294967295u);
	vector<int> can;for(int i=0;i<n;i++) can.pb(i);
	int pp=0,fst=1;
	while(1){
		int x=rand()%n,y=rand()%n;
		if(x==y) continue;
		if(__builtin_popcount(query(x,y))<=6){
			pp=x;break;
		}
	}
	while(can.size()>1){
//		printf("%d\n",can.size());
		if(can.size()==2){
			vector<int> d;
			for(int i=0;i<n;i++) if(i!=can[0]&&i!=can[1]) d.pb(i);
			random_shuffle(d.begin(),d.end());
			for(int i=0;i<d.size();i++){
				int t1=query(d[i],can[0]),t2=query(d[i],can[1]);
				if(t1^t2){
					can.clear();
					if(t1<t2) can.pb(can[0]);
					else can.pb(can[1]);
					break;
				}
			} continue;
		}
		random_shuffle(can.begin(),can.end());
		int id=0;
		if(!fst) id=can[rand()%can.size()];
		else id=pp,fst=0;
		for(int i=0;i<can.size();i++) if(can[i]^id)
			res[i]=query(can[i],id);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<can.size();i++) if(can[i]^id) cnt[res[i]]++;
		int sum=0;
		for(int i=0;i<n;i++) sum+=(cnt[i]>0);
		if(sum==can.size()-1&&can.size()!=n){can.clear();can.pb(id);}
		else{
			int mn=n;
			for(int i=0;i<can.size();i++) if(can[i]^id)
				chkmin(mn,res[i]);
			vector<int> nw;
			for(int i=0;i<can.size();i++) if((can[i]^id)&&(res[i]==mn))
				nw.pb(can[i]);
			nw.pb(id);
//			printf("mn=%d\n",mn);
			swap(can,nw);
		}
	} int ps=can[0];
	for(int i=0;i<n;i++) if(i^ps) ans[i]=query(ps,i);
	printf("! ");
	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
	fflush(stdout);
	return 0;
}