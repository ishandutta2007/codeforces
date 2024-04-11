#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
int n,m;
ll x[1000005],t[1000005],p[1000005],b[1000005];
ll key[1000005],cnt=0,hs[1000005],num=0;
ll ans[1000005],id[1000005];
struct node{
	int l,r;
	ll mn,lz;
} s[1000005<<2];
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mn=s[k].lz=0x3f3f3f3f;
	if(l==r) return;int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
inline void pushdown(int k){
	if(s[k].lz!=0x3f3f3f3f){
		s[k<<1].mn=min(s[k<<1].mn,s[k].lz);s[k<<1].lz=min(s[k<<1].lz,s[k].lz);
		s[k<<1|1].mn=min(s[k<<1|1].mn,s[k].lz);s[k<<1|1].lz=min(s[k<<1|1].lz,s[k].lz);
		s[k].lz=0x3f3f3f3f;
	}
}
inline void modify(int k,int l,int r,ll x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){
		s[k].mn=min(s[k].mn,x);s[k].lz=min(s[k].lz,x);return;
	}
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
}
inline ll query(int k,int v){
	if(s[k].l==s[k].r) return s[k].mn;
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(v<=mid) return query(k<<1,v);
	else return query(k<<1|1,v);
}
set<pair<int,int> > st;
inline void operate(int i,int j){
//	cerr<<i<<" "<<j<<endl;
	ans[j]++;
	int L=upper_bound(hs+1,hs+num+1,x[j]+t[j])-hs;
	int R=upper_bound(hs+1,hs+num+1,x[j]+t[j]+b[i])-hs-1;
	modify(1,L,R,lower_bound(hs+1,hs+num+1,x[j])-hs);t[j]+=b[i];
	vector<pair<int,int> > dels;
	set<pair<int,int> > :: iterator it=st.lower_bound(make_pair(L,0));
	while(it!=st.end()&&it->fi<=R){
		dels.pb(*it);it++;
	}
	foreach(itt,dels) st.erase(st.find(*itt));
	foreach(itt,dels) operate(itt->se,j);
}
signed main(){
//	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&t[i]);
	for(int i=1;i<=m;i++) scanf("%lld%lld",&p[i],&b[i]);
	for(int i=1;i<=n;i++) key[++cnt]=x[i];
	for(int i=1;i<=m;i++) key[++cnt]=p[i];
	sort(key+1,key+cnt+1);key[0]=-0x3f3f3f3f;
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	build(1,1,num);
	for(int i=1;i<=n;i++){
		int l=lower_bound(hs+1,hs+num+1,x[i])-hs;
		int r=upper_bound(hs+1,hs+num+1,x[i]+t[i])-hs-1;
		id[l]=i;modify(1,l,r,l);
	}
	for(int i=1;i<=m;i++){
		int l=lower_bound(hs+1,hs+num+1,p[i])-hs;
		int val=query(1,l);
		if(val==0x3f3f3f3f){
			st.insert(make_pair(l,i));continue;
		}
		int j=id[val];
		operate(i,j);
	}
	for(int i=1;i<=n;i++) printf("%lld %lld\n",ans[i],t[i]);
	return 0;
}
/*
4 6
10 2
15 0
6 1
0 1
110 10
1 1
6 0
15 10
14 100
12 2
*/