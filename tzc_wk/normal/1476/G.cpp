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
const int MAXN=1e5;
const int BLK_2_3=2000;
const int BLK_1_2=316;
const int INF=0x3f3f3f3f;
int n,qu,qk=0,a[MAXN+5],tot_cnt[MAXN+5],cnt[MAXN+5],cnt_cnt[MAXN+5];
int blk_cnt,L[MAXN+5],R[MAXN+5],bel[MAXN+5];
struct chg{int x,pre,cur;} c[MAXN+5];
vector<int> tot;
void push(int x){cnt_cnt[cnt[x]]--;cnt[x]++;cnt_cnt[cnt[x]]++;}
void pop(int x){cnt_cnt[cnt[x]]--;cnt[x]--;cnt_cnt[cnt[x]]++;}
struct query{
	int l,r,k,id;
	bool operator <(const query &rhs){
		if(bel[l]!=bel[rhs.l]) return l<rhs.l;
		else if(bel[r]!=bel[rhs.r]) return r<rhs.r;
		return id<rhs.id;
	}
} q[MAXN+5];
int ans[MAXN+5];
int deal(int k){
	vector<int> over;int ret=INF;
	for(int i=0;i<tot.size();i++) if(cnt[tot[i]]>BLK_1_2) over.pb(cnt[tot[i]]);
	sort(over.begin(),over.end());
	for(int l=1,r=1,sum=0;l<=BLK_1_2;l++){
		while(r<=BLK_1_2&&sum<k) sum+=cnt_cnt[r],r++;
		if(sum<k){
			int need=k-sum;
			if(need<=over.size()) chkmin(ret,over[need-1]-l);
		} else chkmin(ret,r-l-1);
		sum-=cnt_cnt[l];
	}
	for(int i=0;i+k-1<over.size();i++) chkmin(ret,over[i+k-1]-over[i]);
	return ret;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),tot_cnt[a[i]]++;
	blk_cnt=(n-1)/BLK_2_3+1;
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*BLK_2_3+1;R[i]=min(i*BLK_2_3,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	for(int i=1;i<=qu;i++){
		int opt;scanf("%d",&opt);
		if(opt==1){
			qk++;scanf("%d%d%d",&q[qk].l,&q[qk].r,&q[qk].k);
			q[qk].id=i;
		} else {
			scanf("%d%d",&c[i].x,&c[i].cur);
			c[i].pre=a[c[i].x];a[c[i].x]=c[i].cur;
			tot_cnt[c[i].cur]++;
		}
	} sort(q+1,q+qk+1);int cl=1,cr=0,ct=qu;
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=MAXN;i++) if(tot_cnt[i]>BLK_1_2) tot.pb(i);
	for(int i=1;i<=qk;i++){
		while(cr<q[i].r) push(a[++cr]);
		while(cl>q[i].l) push(a[--cl]);
		while(cr>q[i].r) pop(a[cr--]);
		while(cl<q[i].l) pop(a[cl++]);
		while(ct<q[i].id){
			if(c[ct].x){
				if(q[i].l<=c[ct].x&&c[ct].x<=q[i].r) pop(c[ct].pre);
				a[c[ct].x]=c[ct].cur;
				if(q[i].l<=c[ct].x&&c[ct].x<=q[i].r) push(c[ct].cur);
			} ct++;
		}
		while(ct>q[i].id){
			if(c[ct].x){
				if(q[i].l<=c[ct].x&&c[ct].x<=q[i].r) pop(c[ct].cur);
				a[c[ct].x]=c[ct].pre;
				if(q[i].l<=c[ct].x&&c[ct].x<=q[i].r) push(c[ct].pre);
			} ct--;
		} ans[q[i].id]=deal(q[i].k);
	}
	for(int i=1;i<=qu;i++) if(~ans[i]) printf("%d\n",(ans[i]^INF)?ans[i]:-1);
	return 0;
}
/*
12 11
2 1 1 2 1 1 3 2 1 1 3 3
1 2 10 3
1 2 11 3
2 7 2
1 3 9 2
1 1 12 1
1 1 12 4
2 12 4
1 1 12 4
2 1 5
1 3 12 2
1 1 4 3
*/
/*
10 2
1 2 2 1 1 3 1 1 3 1
1 3 8 2
1 3 8 3
*/