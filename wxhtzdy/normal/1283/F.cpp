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
int n,a[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	printf("%d\n",a[1]);
	set<int> s;
	rep(i,1,n+1) s.insert(i);
	s.erase(s.find(a[1]));
	rep(i,1,n) {
		int u=a[i],v=*prev(s.end());
		s.erase(v);
		int ptr=i+1;
		while (ptr<n&&s.count(a[ptr])) {
			printf("%d %d\n",u,a[ptr]);
			s.erase(s.find(u=a[ptr++]));
		}
		printf("%d %d\n",u,v);
		i=ptr-1;
	}
}