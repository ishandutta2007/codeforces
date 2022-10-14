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
int n,a,b,k;
char s[N];

int main() {
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",s);
	VI v;
	rep(i,0,n) if (s[i]=='0') {
		int ptr=i;
		while (ptr+1<n&&s[ptr+1]=='0') ptr++;
		for (int j=i+b-1;j<=ptr;j+=b) v.pb(j);
		i=ptr;
	}
	printf("%d\n",SZ(v)-a+1);
	rep(i,0,SZ(v)-a+1) printf("%d ",v[i]+1);
}