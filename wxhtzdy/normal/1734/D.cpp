#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=200050;
int _,n,k,a[N];

bool solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",&a[i]);
	if(k==1||k==n) return true;
	vector<tuple<ll,ll,int>> L,R;
	per(i,1,k) {
		int ptr=i-1;
		ll s=a[i],mn=a[i];
		while(ptr>=1&&s<0) {
			s+=a[ptr];
			mn=min(mn,s);
			ptr--;
		}
		L.emplace_back(s,mn,ptr);
		i=ptr+1;
	}
	rep(i,k+1,n+1) {
		int ptr=i+1;
		ll s=a[i],mn=a[i];
		while(ptr<=n&&s<0) {
			s+=a[ptr];
			mn=min(mn,s);
			ptr++;
		}
		R.emplace_back(s,mn,ptr);
		i=ptr-1;
	}
	int l=0,r=0;
	ll h=a[k];
	while (l<SZ(L)&&r<SZ(R)) {
		if (h>=-get<1>(L[l])) {
			h+=get<0>(L[l]);
			l++;
			continue;
		}
		if (h>=-get<1>(R[r])) {
			h+=get<0>(R[r]);
			r++;
			continue;
		}
		return false;
	}
	return true;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
}