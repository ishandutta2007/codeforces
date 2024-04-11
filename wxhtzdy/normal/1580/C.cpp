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
const int BLOCK=300;
int n,m,x[N],y[N],s[N],ans[N],st[N],cnt[BLOCK][BLOCK];
VI pos[N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d%d",x+i,y+i),x[i]=min(x[i],N),y[i]=min(y[i],N);
	rep(i,1,m+1) {
		int op,k;
		scanf("%d%d",&op,&k);
		if (x[k]+y[k]>=BLOCK) {
			pos[k].pb(i);
		} else {
			if (op==1) st[k]=i;
			int a=x[k]+y[k];
			rep(j,0,a) if (j>=x[k]) cnt[a][(st[k]+j)%a]+=(op==1?1:-1);
		}
		rep(j,1,BLOCK) ans[i]+=cnt[j][i%j];
	}
	rep(i,1,n+1) if (SZ(pos[i])&1) pos[i].pb(m+1);
	rep(i,1,n+1) {
		if (x[i]+y[i]>=BLOCK) {
			assert(SZ(pos[i])%2==0);
			for (int j=0;j<SZ(pos[i]);j+=2) {
				int l=pos[i][j],r=pos[i][j+1];
				while (l<r) {
					l+=x[i]; if (l>=r) break;
					s[l]++; l=min(r,l+y[i]); s[l]--;
				}
			}
		}
	}
	rep(i,1,m+1) s[i]+=s[i-1];
	rep(i,1,m+1) printf("%d\n",ans[i]+s[i]);
}