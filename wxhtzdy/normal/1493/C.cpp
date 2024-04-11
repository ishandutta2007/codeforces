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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=100050;
int n,k,_,cnt[26];
char s[N];
void solve() {
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if (n%k) {
		printf("-1\n");
		return;
	}
	rep(i,0,26) cnt[i]=0;
	rep(i,1,n+1) cnt[s[i]-'a']++;
	bool ok=true;
	rep(i,0,26) ok&=(cnt[i]%k==0);
	if (ok) {
		printf("%s\n",s+1);
		return;
	}
	per(i,1,n+1) {
		int ch=s[i]-'a';
		cnt[ch]--;
		rep(c,ch+1,26) {
			cnt[c]++;
			int need=0;
			rep(j,0,26) need+=((k-(cnt[j]%k))%k);
			if(need<=n-i) {
				s[i]=(char)(c+'a');
				int ptr=n;
				per(j,0,26) {
					while (cnt[j]%k) {
						s[ptr]=(char)(j+'a');
						cnt[j]++, ptr--;
					}
				}
				while (ptr>i) s[ptr]='a', ptr--;
				printf("%s\n",s+1);
				return;
			}
			cnt[c]--;
		}
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}