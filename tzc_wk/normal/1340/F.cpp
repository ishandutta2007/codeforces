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
const int MAXN=1e5;
const int BLK=316;
const u64 B=191;
u64 pw[MAXN+5];
int n,k,qu,a[MAXN+5],blk_cnt,blk_sz;
int bel[MAXN+5],L[BLK+5],R[BLK+5];
bool ok[BLK+5];
vector<int> lft[BLK+5],rit[BLK+5];
vector<u64> lft_hs[BLK+5];u64 rit_hs[BLK+5];
struct node{int x,l,r;u64 hs;};
u64 gethash(int x,int l,int r){
	return (lft_hs[x][l]-((r+1==lft[x].size())?0:lft_hs[x][r+1]*pw[r-l+1]));
}
void redone(int x){
	stack<int> stk;ok[x]=1;lft[x].clear();rit[x].clear();
	for(int i=L[x];i<=R[x];i++){
		if(a[i]<0){
			if(!stk.empty()&&stk.top()^(-a[i])) return ok[x]=0,void();
			else if(stk.empty()) rit[x].pb(-a[i]);else stk.pop();
		} else stk.push(a[i]);
	} while(!stk.empty()) lft[x].pb(stk.top()),stk.pop();
	lft_hs[x].resize(lft[x].size(),0);rit_hs[x]=0;
	for(int i=(int)(lft[x].size())-1;~i;i--) lft_hs[x][i]=((i+1==lft[x].size())?0:lft_hs[x][i+1])*B+lft[x][i];
	for(int i=0;i<rit[x].size();i++) rit_hs[x]+=rit[x][i]*pw[i];
//	printf("Block %d:\n",x);
//	for(int i=0;i<lft[x].size();i++) printf("%d ",lft[x][i]);printf("\n");
//	for(int i=0;i<rit[x].size();i++) printf("%d ",rit[x][i]);printf("\n");
}
bool query(int l,int r){
	if(bel[l]==bel[r]){
		stack<int> stk;
		for(int i=l;i<=r;i++){
			if(a[i]<0){
				if(stk.empty()||stk.top()^(-a[i])) return 0;
				stk.pop();
			} else stk.push(a[i]);
		} return stk.empty();
	} for(int i=bel[l]+1;i<bel[r];i++) if(!ok[i]) return 0;
	stack<node> stk;
	for(int i=l;i<=R[bel[l]];i++){
		if(a[i]<0){
			if(stk.empty()) return 0;node t=stk.top();stk.pop();
			u64 hs=(!~t.l)?t.hs:gethash(t.x,t.l,t.l);if(hs+a[i]) return 0;
			if(t.l^t.r) stk.push({t.x,t.l+1,t.r,gethash(t.x,t.l+1,t.r)});
		} else stk.push({bel[l],-1,-1,a[i]});
	}
	for(int i=bel[l]+1;i<bel[r];i++){
		int need=rit[i].size(),clen=0;u64 cur_hs=0;
		while(!stk.empty()&&need){
			node t=stk.top();stk.pop();int len=t.r-t.l+1;
			if(need<=len){
				if(!~t.l) cur_hs+=t.hs*pw[clen];
				else cur_hs+=gethash(t.x,t.l,t.l+need-1)*pw[clen];
				if(need^len) stk.push({t.x,t.l+need,t.r,gethash(t.x,t.l+need,t.r)});
				need=0;break;
			} else {
				cur_hs+=t.hs*pw[clen];
				need-=len;clen+=len;
			}
		} if(need) return 0;if(cur_hs^rit_hs[i]) return 0;
		if(!lft[i].empty()) stk.push({i,0,lft[i].size()-1,lft_hs[i][0]});
	}
	for(int i=L[bel[r]];i<=r;i++){
		if(a[i]<0){
			if(stk.empty()) return 0;node t=stk.top();stk.pop();
			u64 hs=(!~t.l)?t.hs:gethash(t.x,t.l,t.l);if(hs+a[i]) return 0;
			if(t.l^t.r) stk.push({t.x,t.l+1,t.r,gethash(t.x,t.l+1,t.r)});
		} else stk.push({bel[l],-1,-1,a[i]});
	} return stk.empty();
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=(pw[0]=1);i<=n;i++) pw[i]=pw[i-1]*B;
	blk_cnt=(int)pow(n,0.5);blk_sz=(n-1)/blk_cnt+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk_sz+1;R[i]=min(i*blk_sz,n);
//		printf("%d %d\n",L[i],R[i]);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	for(int i=1;i<=blk_cnt;i++) redone(i);
	scanf("%d",&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int p,x;scanf("%d%d",&p,&x);a[p]=x;
			redone(bel[p]);
		} else {
			int l,r;scanf("%d%d",&l,&r);
			printf("%s\n",query(l,r)?"Yes":"No");
		}
	}
	return 0;
}
/*
10 10
4 4 4 -4 1 -1 -4 8 -8 -4
1
2 2 9

10 1
9 3 7 -7 4 -4 -3 1 -1 -9
1
2 1 10
*/