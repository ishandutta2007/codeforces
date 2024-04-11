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
const int MAXN=1e5;
const int MAX_BLK=316;
const int MAX_BLK2=1400;
int n,qu,a[MAXN+5],cnt[MAXN+5],cnt_cnt[MAXN+5],tmp[MAX_BLK2+5];
int blk,blk_cnt,blk_v,L[MAX_BLK+2],R[MAX_BLK+2],bel[MAXN+5];
vector<int> tt;ll ret[MAXN+5];
void ins(int v){cnt_cnt[cnt[v]]--;cnt[v]++;cnt_cnt[cnt[v]]++;}
void del(int v){cnt_cnt[cnt[v]]--;cnt[v]--;cnt_cnt[cnt[v]]++;}
ll deal(){
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=0;i<tt.size();i++) if(cnt[tt[i]]>blk_v) q.push(cnt[tt[i]]);
	for(int i=1;i<=blk_v;i++) tmp[i]=cnt_cnt[i];int pre=0;ll ret=0;
	for(int i=1;i<=blk_v;i++) if(tmp[i]){
		if(pre){
			ret+=pre+i;tmp[i]--;
			if(pre+i<=blk_v) tmp[pre+i]++;
			else q.push(pre+i);
			pre=0;
		} ret+=1ll*i*(tmp[i]/2*2);
		if(i+i<=blk_v) tmp[i+i]+=tmp[i]/2;
		else for(int j=1;j<=tmp[i]/2;j++) q.push(i+i);
		if(tmp[i]&1) pre=i;
	}
	if(pre) q.push(pre);
	while(q.size()>1){
		int x=q.top();q.pop();x+=q.top();q.pop();
		ret+=x;q.push(x);
	} return ret;
}
struct query{
	int l,r,id;
	bool operator <(const query &rhs){
		if(bel[l]!=bel[rhs.l]) return bel[l]<bel[rhs.l];
		return r<rhs.r;
	}
} q[MAXN+5];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	blk=(int)pow(n,0.5);blk_v=(int)sqrt(n*log(n)/log(2));blk_cnt=(n-1)/blk+1;
	for(int i=1;i<=MAXN;i++) if(cnt[i]>blk_v) tt.pb(i);memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk+1;R[i]=min(i*blk,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	} scanf("%d",&qu);
	for(int i=1;i<=qu;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+qu+1);int cl=1,cr=0;
	for(int i=1;i<=qu;i++){
		while(cr<q[i].r) ins(a[++cr]);
		while(cl>q[i].l) ins(a[--cl]);
		while(cl<q[i].l) del(a[cl++]);
		while(cr>q[i].r) del(a[cr--]);
		ret[q[i].id]=deal();
	}
	for(int i=1;i<=qu;i++) printf("%lld\n",ret[i]);
	return 0;
}