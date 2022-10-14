#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
const int BLOCK=2050;
int n,q,a[N],cc1[N],cc2[N],w[N],prv[N],op[N],t,v[N],pos[N],ans[N];
unordered_map<int,int> c;

struct query {
	int l,r,cnt,id;
	query() {}
	query(int _l,int _r,int _cnt,int _id) : l(_l),r(_r),cnt(_cnt),id(_id) {}
	bool operator < (const query &oth) const {
		if (r/BLOCK!=oth.r/BLOCK) return r<oth.r;
		if (cnt/BLOCK!=oth.cnt/BLOCK) return cnt<oth.cnt;
		return l<oth.l;
	}
}qq[N];


int ql=0,qr=-1,qd;
void upd(int i) {
	cc2[cc1[i]]--;
	cc1[i]++;
	cc2[cc1[i]]++;
}
void rem(int i) {
	cc2[cc1[i]]--;
	cc1[i]--;
	cc2[cc1[i]]++;
}
void qupd(int i) {
	if (pos[i]>=ql&&pos[i]<=qr) {
		rem(a[pos[i]]);
		upd(v[i]);
	}
	a[pos[i]]=v[i];
}
void qrem(int i) {
	if (pos[i]>=ql&&pos[i]<=qr) {
		rem(a[pos[i]]);
		upd(prv[i]);
	}
	a[pos[i]]=prv[i];
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		if (!c.count(a[i])) c[a[i]]=++t;
		a[i]=c[a[i]];
		w[i]=a[i];
	}
	int qi=0,cnt=0;
	rep(i,1,q+1) {
		scanf("%d",op+i);
		if (op[i]==1) {
			int l,r;
			scanf("%d%d",&l,&r);
			++qi;
			qq[qi]={l,r,cnt,i};
		} else {
			cnt++; scanf("%d%d",pos+cnt,v+cnt);
			if (!c.count(v[cnt])) c[v[cnt]]=++t;
			v[cnt]=c[v[cnt]];
			prv[cnt]=w[pos[cnt]];
			w[pos[cnt]]=v[cnt];
		}
	}
	sort(qq+1,qq+qi+1);
	rep(i,1,q+1) {
		while (ql<qq[i].l) rem(a[ql++]);
		while (ql>qq[i].l) upd(a[--ql]);
		while (qr<qq[i].r) upd(a[++qr]);
		while (qr>qq[i].r) rem(a[qr--]);
		while (qd<qq[i].cnt) qupd(++qd);
		while (qd>qq[i].cnt) qrem(qd--);	
		int id=qq[i].id;
		ans[id]=1;
		while (cc2[ans[id]]) ++ans[id];
	}
	rep(i,1,q+1) if (op[i]==1) printf("%d\n",ans[i]);
}