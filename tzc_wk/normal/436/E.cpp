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
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
bool chkmin(ll &x,ll y){return ((x>y)?(x=y,1):0);}
bool chkmax(ll &x,ll y){return ((x<y)?(x=y,1):0);}
const int MAXN=3e5+5;
int n,w,a[MAXN],b[MAXN],key[MAXN<<1],hs[MAXN<<1],cnt=0,num=0,ord[MAXN];
int get(int x){return lower_bound(hs+1,hs+num+1,x)-hs;}
struct node{
	int l,r,c;ll v;
} s[MAXN<<3];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int x,int addv,int addc){
	if(s[k].l==s[k].r){s[k].c+=addc;s[k].v+=addv;return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid) modify(k<<1,x,addv,addc);
	else modify(k<<1|1,x,addv,addc);
	s[k].c=s[k<<1].c+s[k<<1|1].c;
	s[k].v=s[k<<1].v+s[k<<1|1].v;
}
ll query(int k,int c){
	if(s[k].l==s[k].r) return 1ll*c*hs[s[k].l];
	if(c>=s[k<<1].c) return s[k<<1].v+query(k<<1|1,c-s[k<<1].c);
	else return query(k<<1,c);
}
bool cmp(int x,int y){return b[x]<b[y];}
int star[MAXN];pii p[MAXN];
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) ord[i]=i;sort(ord+1,ord+n+1,cmp);
//	for(int i=1;i<=n;i++) printf("%d\n",ord[i]);
	for(int i=1;i<=n;i++) key[++cnt]=a[i],key[++cnt]=b[i]-a[i];
	sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	build(1,1,num);
	for(int i=1;i<=n;i++) modify(1,get(a[i]),a[i],1);
	ll ans=1e18,sum=0;if(w<=n) ans=min(ans,query(1,w));
	int pos=0;
	for(int i=1;i<=n;i++){
		modify(1,get(a[ord[i]]),-a[ord[i]],-1);
		modify(1,get(b[ord[i]]-a[ord[i]]),b[ord[i]]-a[ord[i]],1);
		sum+=a[ord[i]];//printf("%lld\n",sum);
//		printf("%lld\n",query(1,w-i));
		if(w-i<=n&&w-i>=0) if(chkmin(ans,query(1,w-i)+sum)) pos=i;
	} printf("%lld\n",ans);
	for(int i=1;i<=pos;i++) star[ord[i]]++;
	for(int i=1;i<=pos;i++) p[i]=mp(b[ord[i]]-a[ord[i]],ord[i]);
	for(int i=pos+1;i<=n;i++) p[i]=mp(a[ord[i]],ord[i]);
	sort(p+1,p+n+1);for(int i=1;i<=w-pos;i++) star[p[i].se]++;
	for(int i=1;i<=n;i++) printf("%d",star[i]);
	return 0;
}