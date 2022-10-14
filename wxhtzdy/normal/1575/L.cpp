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

const int N=201000;
int n,a[N],p[N];
struct node{
	int mx;
}nd[8*N];
void modify(int p,int l,int r,int tl,int x) {
	if (l==r) nd[p].mx=max(nd[p].mx,x);
	else {
		int md=(l+r)>>1;
		if (tl<=md) modify(p+p,l,md,tl,x);
		else modify(p+p+1,md+1,r,tl,x);
		nd[p].mx=max(nd[p+p].mx,nd[p+p+1].mx);
	}
}
int get(int p,int l,int r,int tl,int tr) {
	if (l>tr||r<tl) return 0;
	if (tl<=l&&r<=tr) return nd[p].mx;
	else {
		int md=(l+r)>>1;
		return max(get(p+p,l,md,tl,tr),get(p+p+1,md+1,r,tl,tr));
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[&](int i,int j){
		if (i-a[i]!=j-a[j]) return i-a[i]<j-a[j];
		return i<j;
	});
	rep(i,1,n+1) if (a[p[i]]>=1&&a[p[i]]<=p[i]) {
		modify(1,1,n,a[p[i]],get(1,1,n,1,a[p[i]]-1)+1);
	}
	printf("%d",nd[1].mx);
}