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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=200050;
int _,n,a[N],p0[N],p2[N],ps[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		p0[i]=p0[i-1];
		if (a[i]==0) p0[i]++;
		p2[i]=p2[i-1];
		if (abs(a[i])==2) p2[i]++;
		ps[i]=ps[i-1];
		if (a[i]<0) ps[i]++;
	}
	int bst=0,l=n,r=0;
	function<void(int,int)> Update=[&](int L,int R) {
		if (L>R) return;
		int c0=p0[R]-p0[L-1];
		int pp;
		if (c0>0) pp=0;
		else {
			pp=p2[R]-p2[L-1];
			int sgn=ps[R]-ps[L-1];
			if (sgn%2==1) pp=-pp;
		}
		if (pp>bst) bst=pp,l=L-1,r=n-R;
	};
	Update(1,n);
	rep(l,1,3) rep(r,n-1,n+1) Update(l,r);
	VI zer;
	rep(i,1,n+1) if (a[i]==0) zer.pb(i);
	rep(i,0,SZ(zer)-1) Update(zer[i]+1,zer[i+1]-1);
	if (SZ(zer)>0) Update(1,zer[0]-1);
	if (SZ(zer)>0) Update(zer.back()+1,n);
	VI neg;
	rep(i,1,n+1) if (a[i]<0) neg.pb(i);
	rep(i,0,SZ(neg)) Update(neg[i]+1,n);
	rep(i,0,SZ(neg)) Update(1,neg[i]-1);
	rep(i,0,SZ(neg)-1) Update(neg[i]+1,neg[i+1]-1);
	neg.clear();
	int lst=1;
	rep(i,1,n+1) {
		if (a[i]==0) neg.clear(),lst=i;
		if (a[i]<0) neg.pb(i);
		if (SZ(neg)>=1) Update(neg[0]+1,i);
		if (SZ(neg)>=2) Update(neg[1]+1,i);
		Update(lst+1,i);
	}
	neg.clear();
	lst=n;
	per(i,1,n+1) {
		if (a[i]==0) neg.clear(),lst=i;
		if (a[i]<0) neg.pb(i);
		if (SZ(neg)>=1) Update(i,neg[SZ(neg)-1]-1);
		if (SZ(neg)>=2) Update(i,neg[SZ(neg)-2]-1);
		Update(i,lst-1);
	}
	printf("%d %d\n",l,r);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}