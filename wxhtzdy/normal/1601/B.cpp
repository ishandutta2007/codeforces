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

const int N=301000;
int n,a[N],b[N],dst[N][2],f[N][2];
VI g[N];
set<PII> st;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),st.insert(mp(i-a[i],i));
	rep(i,1,n+1) {
		scanf("%d",b+i);
		if (i!=n) g[i+b[i]].pb(i);
	}
	dst[0][0]=0; dst[0][1]=1e9;
	rep(i,1,n+1) rep(j,0,2) dst[i][j]=1e9;
	set<tuple<int,int,int>> dq;
	dq.insert({0,0,0});
	while (SZ(dq)) {
		auto tr=dq.begin();
		int x=get<1>(*tr);
		int typ=get<2>(*tr);
		dq.erase(tr);
		if (typ==0){
			while (SZ(st)) {
				auto it=st.begin();
				if ((*it).fi>x) break;
				int y=(*it).se;
				st.erase(it);
				if (dst[y][1]>dst[x][0]+1) {
					if (dst[y][1]!=1e9) dq.erase(dq.find({dst[y][1],y,1}));
					dst[y][1]=dst[x][0]+1;
					f[y][1]=x;
					dq.insert({dst[y][1],y,1});
				}
			}
		} else {
			for (int y:g[x]) {
				if (dst[y][0]>dst[x][1]) {
					if (dst[y][0]!=1e9) dq.erase(dq.find({dst[y][0],y,0}));
					dst[y][0]=dst[x][1];
					f[y][0]=x;
					dq.insert({dst[y][0],y,0});
				}
			}
		}
	}
//	rep(i,0,n+1) printf("%d %d\n",i,f[i]);
	VI ans;
	int x=n,tp=1;
	while (x!=0) {
//		printf("%d\n",x);
		ans.pb(x),x=f[x][tp],tp^=1;
	}
	ans.pb(0);
	if (dst[n][1]==1e9) printf("%d",-1);
	else {
		printf("%d\n",dst[n][1]);
		rep(i,0,SZ(ans)) if (i%2==1) printf("%d ",ans[i]);
	}
}