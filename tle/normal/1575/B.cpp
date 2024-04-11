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

const int N=101000;
const db PI=acos(-1.);
int n,k,x[N],y[N];
db EPS=1e-9;
db dist[N],ang[N];

int check(db r) {
	vector<pair<db,int>> cand;
	int cnt=0;
	rep(i,0,n) {
		if (dist[i]>=2*r-EPS) continue;
		db th=acos(dist[i]/2/r);
		db tl=ang[i]-th,tr=ang[i]+th;
		while (tl<0) tl+=2*PI;
		while (tr<0) tr+=2*PI;
		cand.pb(mp(tl,1));
		cand.pb(mp(tr,-1));
		if (tl>tr) {
			cnt+=1;
		}
	}
	int ans=cnt;
	sort(all(cand));
	for (auto x:cand) cnt+=x.se,ans=max(ans,cnt);
	return ans;
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d%d",x+i,y+i);
		if (x[i]==0&&y[i]==0) --k,--n,--i;
	}
	if (k<=0) {
		puts("0");
		return 0;
	}
	rep(i,0,n) ang[i]=atan2(y[i],x[i]),dist[i]=sqrt(1.*x[i]*x[i]+1.*y[i]*y[i]);
	db l=0,r=2e5;
	rep(i,0,50) {
		db md=(l+r)*0.5;
		if (check(md)>=k) r=md; else l=md;
	}
	printf("%.10f\n",r);

}