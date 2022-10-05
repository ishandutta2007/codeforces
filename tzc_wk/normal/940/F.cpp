#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int BLOCK_SZ=2154;
const int BLOCK_CNT=MAXN/BLOCK_SZ+1;
const int INF=0x3f3f3f3f;
int n,m,qu=0,a[MAXN+5],key[MAXN*2+5],knum,hs[MAXN*2+5],num=0;
int blk,L[BLOCK_CNT+3],R[BLOCK_CNT+3],bel[MAXN+5];
struct chg{int x,pre,cur;} c[MAXN+5];
struct query{
	int t,l,r;
	bool operator <(const query &rhs){
		if(bel[l]!=bel[rhs.l]) return bel[l]<bel[rhs.l];
		if(bel[r]!=bel[rhs.r]) return bel[r]<bel[rhs.r];
		return t<rhs.t;
	}
} q[MAXN+5];
int cnt[MAXN*2+5],cnt_cnt[MAXN*2+5];
void ins(int x){cnt_cnt[cnt[a[x]]]--;cnt[a[x]]++;cnt_cnt[cnt[a[x]]]++;}
void del(int x){cnt_cnt[cnt[a[x]]]--;cnt[a[x]]--;cnt_cnt[cnt[a[x]]]++;}
int ans[MAXN+5];
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);blk=(n-1)/BLOCK_SZ+1;cnt_cnt[0]=INF;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];knum=n;
	for(int i=1;i<=blk;i++){
		L[i]=(i-1)*BLOCK_SZ+1;
		R[i]=min(i*BLOCK_SZ,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	for(int i=1;i<=m;i++){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) q[++qu].t=i,q[qu].l=x,q[qu].r=y;
		else c[i].x=x,c[i].pre=a[x],a[x]=y,c[i].cur=a[x],key[++knum]=y;
	} sort(q+1,q+qu+1);sort(key+1,key+knum+1);
	for(int i=1;i<=knum;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(hs+1,hs+num+1,a[i])-hs;
	for(int i=1;i<=m;i++) if(c[i].x){
		c[i].pre=lower_bound(hs+1,hs+num+1,c[i].pre)-hs;
		c[i].cur=lower_bound(hs+1,hs+num+1,c[i].cur)-hs;
	}
	int cl=1,cr=0,ct=m;memset(ans,-1,sizeof(ans));
	for(int i=1;i<=qu;i++){
		while(cl>q[i].l) ins(--cl);
		while(cr<q[i].r) ins(++cr);
		while(cl<q[i].l) del(cl++);
		while(cr>q[i].r) del(cr--);
		while(ct>q[i].t){
			if(c[ct].x){
				if(cl<=c[ct].x&&c[ct].x<=cr) del(c[ct].x);
				a[c[ct].x]=c[ct].pre;
				if(cl<=c[ct].x&&c[ct].x<=cr) ins(c[ct].x);
			} ct--;
		}
		while(ct<q[i].t){
			if(c[ct].x){
				if(cl<=c[ct].x&&c[ct].x<=cr) del(c[ct].x);
				a[c[ct].x]=c[ct].cur;
				if(cl<=c[ct].x&&c[ct].x<=cr) ins(c[ct].x);
			} ct++;
		}
		ans[q[i].t]=0;
		while(cnt_cnt[ans[q[i].t]]) ans[q[i].t]++;
	}
	for(int i=1;i<=m;i++) if(~ans[i]) printf("%d\n",ans[i]);
	return 0;
}