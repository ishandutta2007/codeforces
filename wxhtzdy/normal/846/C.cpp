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

const int N=5050;
int n,a[N],bst[N];
ll pref[N][2];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) {
		pref[i][0]=pref[i-1][0]+a[i];
		pref[i][1]=pref[i-1][1]-a[i];
	}
	rep(i,1,n+1) {
		ll mx=pref[i][1];
		bst[i]=0;
		rep(j,1,i+1) {
			ll curr=pref[i][1]-pref[j][1]+pref[j][0];
			if (curr>mx) mx=curr,bst[i]=j;
		}
	}
	bool pos=0;
	rep(i,1,n+1) if (a[i]>=0) pos=1;
	if (!pos) {
		printf("0 0 0");
		return 0;
	}
	if (n==1) {
		if (a[1]>0) printf("1 1 1");
		else printf("0 0 0");
		return 0;
	}
	ll ans=-1e18;
	int x=0,y=0;
	rep(i,1,n+1) {
		per(j,i,n+1) {
			ll curr=pref[j][0]-pref[i-1][0]+pref[n][1]-pref[j][1];
			curr+=pref[i-1][1]-pref[bst[i-1]][1]+pref[bst[i-1]][0];
			if (ans<curr) ans=curr,x=i,y=j;
		}
	}
	printf("%d %d %d",bst[x-1],x-1,y);
}