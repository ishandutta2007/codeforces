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

const int N=505;
int n,m,k,q,x[N*N],y[N*N],t[N*N],ord[N*N],s[N][N],a[N][N];

int get(int x1,int y1,int x2,int y2) {
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

bool check(int p) {
	rep(i,1,n+1) rep(j,1,m+1) a[i][j]=0;
	rep(i,1,q+1) if (t[ord[i]]<=p) 
		a[x[ord[i]]][y[ord[i]]]=1;
	rep(i,1,n+1) rep(j,1,m+1) s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	rep(i,1,n-k+2) rep(j,1,m-k+2) 
		if (get(i,j,i+k-1,j+k-1)==k*k) return false;
	return true;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&k,&q);
	rep(i,1,q+1) scanf("%d%d%d",x+i,y+i,t+i),ord[i]=i;
	sort(ord+1,ord+q+1,[&](int i,int j) {
		return t[i]<t[j];
	});
	int l=-1,r=1e9+5,ans=0;
	while (l<=r) {
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (ans>1e9) puts("-1");
	else printf("%d",ans+1);
}