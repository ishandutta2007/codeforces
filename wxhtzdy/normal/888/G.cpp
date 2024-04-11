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
int n,a[N],ch[N*20][2],mx[N*20],tsz;

void modify(int x,int id) {
	int p=0;
	per(i,0,30) {
		int b=((x&(1<<i))?1:0);
		if (!ch[p][b]) ch[p][b]=++tsz;
		p=ch[p][b];
		mx[p]=max(mx[p],id);
	}
}

int query(int x,int id) {
	int p=0,ans=0;
	per(i,0,30) {
		int b=((x&(1<<i))?1:0);
		if (ch[p][b]&&mx[ch[p][b]]>=id) p=ch[p][b];
		else ans+=(1<<i),p=ch[p][b^1];
	}
	return ans;
}

ll gao(int l,int r,int dep) {
	if (l>=r-1||dep<0) return 0;
	int ptr=l;
	while (ptr<r&&!(a[ptr]&(1<<dep))) ptr++;
	ll tot=0;
	tot+=gao(l,ptr,dep-1);
	tot+=gao(ptr,r,dep-1);
	if (l==ptr||r==ptr) return tot;
	int ans=(1<<30);
	rep(i,l,ptr) ans=min(ans,query(a[i],ptr));
	return tot+ans;
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	rep(i,0,n) modify(a[i],i);
	printf("%lld\n",gao(0,n,29));
}