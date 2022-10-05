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
const int MAXN=2e5;
int n,p[MAXN+5],pth_n;
bool vis[MAXN+5];
vector<int> pth[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) if(!vis[i]&&p[i]!=i){
		int cur=p[i];pth[++pth_n].pb(i);vis[i]=1;
		while(cur!=i) pth[pth_n].pb(cur),vis[cur]=1,cur=p[cur];
	} vector<pii> ans;//printf("%d\n",pth_n);
	for(int i=1;i+1<=pth_n;i+=2){
		ans.pb(mp(pth[i][0],pth[i+1][0]));
		for(int j=1;j<pth[i].size();j++) ans.pb(mp(pth[i][j],pth[i+1][0]));
		for(int j=1;j<pth[i+1].size();j++) ans.pb(mp(pth[i+1][j],pth[i][0]));
		ans.pb(mp(pth[i][0],pth[i+1][0]));
	}
	if(pth_n&1){
		if(pth[pth_n].size()==2){
			for(int i=1;i<=n;i++){
				if((i^pth[pth_n][0])&&(i^pth[pth_n][1])){
					ans.pb(mp(i,pth[pth_n][0]));
					ans.pb(mp(i,pth[pth_n][1]));
					ans.pb(mp(i,pth[pth_n][0]));
					break;
				}
			}
		} else {
			for(int i=1;i+1<pth[pth_n].size();i++)
				ans.pb(mp(pth[pth_n][0],pth[pth_n][i]));
			ans.pb(mp(pth[pth_n][1],pth[pth_n].back()));
			ans.pb(mp(pth[pth_n][0],pth[pth_n].back()));
			ans.pb(mp(pth[pth_n][0],pth[pth_n][1]));
		}
	} printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}