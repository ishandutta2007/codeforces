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
const int MAXN=1.5e5;
const int INF=0x3f3f3f3f;
int n,m,k,a[MAXN+5],b[MAXN+5],pos[MAXN+5];
struct node{int l,r,mn,lz;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].mn=-l;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
void pushdown(int k){
	if(s[k].lz!=0){
		s[k<<1].mn+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mn+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){s[k].mn+=x;s[k].lz+=x;return;}
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	a[0]=-INF;sort(a+1,a+m+1);build(1,1,m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		pos[i]=lower_bound(a,a+m+1,k-b[i])-a;
//		printf("%d\n",pos[i]);
	}
	for(int i=1;i<m;i++) modify(1,pos[i],m,1);
	int ans=0;
	for(int i=m;i<=n;i++){
		modify(1,pos[i],m,1);
//		printf("%d\n",s[1].mn);
		if(s[1].mn>=0) ans++;
		modify(1,pos[i-m+1],m,-1);
	} printf("%d\n",ans);
	return 0;
}