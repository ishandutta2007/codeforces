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
 
const int N=1010;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,f[N*N],sz[N*N],srt[N*N];
ll a[N][N],k,ans[N][N];
int vis[N][N];
 
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
 
void unite(int x,int y) {
	x=find(x); 
	y=find(y);
	if (x==y) return;
	sz[x]+=sz[y]; f[y]=x;
}
 
int main() {
	scanf("%d%d%lld",&n,&m,&k);
	rep(i,0,n) rep(j,0,m) scanf("%lld",&a[i][j]);
	rep(i,0,n) rep(j,0,m) {
		int id=i*m+j;
		f[id]=id; 
		sz[id]=1;
		srt[id]=id;
	}
	sort(srt,srt+n*m,[&](int i,int j){
		int x1=i/m,y1=i%m;
		int x2=j/m,y2=j%m;
		return a[x1][y1]>a[x2][y2];
	});
	rep(y,0,n*m) {
		int x=srt[y];
		int ii=x/m,jj=x%m;
		rep(d,0,4) {
			int ni=ii+dx[d],nj=jj+dy[d];
			if (ni>=0&&ni<n&&nj>=0&&nj<m&&a[ni][nj]>=a[ii][jj]) {
				unite(x,ni*m+nj);
			}
		}
		if (k>=a[ii][jj]&&(ll)a[ii][jj]*sz[find(x)]>=k&&k%a[ii][jj]==0) {
			puts("YES");
			k-=a[ii][jj];
			deque<PII> q;
			q.pb(mp(ii,jj));
			vis[ii][jj]=1; ans[ii][jj]=a[ii][jj];
			while (SZ(q)) {
				int i=q[0].fi,j=q[0].se;
				q.pop_front();
				rep(d,0,4) {
					int ni=i+dx[d],nj=j+dy[d];
					if (ni>=0&&ni<n&&nj>=0&&nj<m&&find(x)==find(ni*m+nj)&&!vis[ni][nj]) {
						if (k>0) ans[ni][nj]=a[ii][jj],k-=a[ii][jj];
						vis[ni][nj]=1; q.pb(mp(ni,nj));
					}	
				}
			}
			rep(i,0,n) rep(j,0,m) {
				printf("%lld ",ans[i][j]);
				if (j==m-1) puts("");
			}
			return 0;
		}
	}
	puts("NO");
}