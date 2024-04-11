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

const int N=101000;
int n,q;
char s[N];

int check(int i) {
	if (i<0||i+3>n) return 0;
	if (s[i]!='a') return 0;
	if (s[i+1]!='b') return 0;
	if (s[i+2]!='c') return 0;
	return 1;
}

int main() {
	scanf("%d%d",&n,&q);
	scanf("%s",s);
	int ans=0;
	rep(i,0,n) ans+=check(i);
	while (q--) {
		int i;
		char c;
		scanf("%d %c",&i,&c);
		i--;
		ans-=check(i);
		ans-=check(i-1);
		ans-=check(i-2);
		s[i]=c;
		ans+=check(i);
		ans+=check(i-1);
		ans+=check(i-2);
		printf("%d\n",ans);
	}
}