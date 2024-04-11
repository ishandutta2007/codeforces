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

const int N=605000;
int n,m,c[N],lst[N],mn[N],mx[N];

void modify(int x,int f) {
	for (;x<N;x+=x&-x) c[x]+=f;
}

int query(int x) {
	int res=0;
	for (;x>0;x-=x&-x) res+=c[x];
	return res;
}

int main() {
	scanf("%d%d",&n,&m);
	per(i,1,n+1) modify(i,1),mn[i]=i,lst[i]=mx[i]=n-i+1;
	rep(i,1,m+1) { 
		int x;
		scanf("%d",&x);
		mn[x]=1;
		mx[x]=min(mx[x],query(lst[x]));
		modify(lst[x],-1);
		lst[x]=n+i;
		modify(lst[x],1);
	}
	rep(i,1,n+1) mx[i]=min(mx[i],query(lst[i]));
	rep(i,1,n+1) printf("%d %d\n",mn[i],n-mx[i]+1);
}