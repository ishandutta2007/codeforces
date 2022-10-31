#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

lli mod;
lli power(lli a,lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
lli inv(lli a) {
	return power(a,mod-2);
}

class matrix{
public:
	vector<vector<lli>> a;
	int n;

	matrix() {}
	matrix(int n) {
		init(n);
	}
	void init(int n) {
		this->n=n;
		a.resize(n);
		for(int i=0;i<n;i++) a[i].resize(n,0);
	}
	
	lli getDigonal() {
		lli res=1;
		for(int i=0;i<n;i++) res = res*a[i][i]%mod;
		return res;
	}
};

const int dy[4]={-1,-1,1,1},dx[4]={-1,1,-1,1};
const int cy[4]={-1,-1,0,0},cx[4]={-1,0,-1,0};
const int bn[4]={1,0,0,1};

int n,m,vis[201][201],g=0,arr[201][201];
char str[201][201];

bool go(int y,int x,int i,int j) {
	return y>=0 && x>=0 && y<=n && x<=m && i>=0 && j>=0 &&
			i<n && j<m;
}
void bfs(int si,int sj) {
	queue<pii> que;
	que.push(pii(si,sj));
	vis[si][sj]=g;
	while(!que.empty()) {
		int i=que.front().first, j=que.front().second;
		que.pop();
		for(int k=0;k<4;k++) {
			int yy=i+dy[k],xx=j+dx[k];
			int ii=i+cy[k],jj=j+cx[k];
			if(go(yy,xx,ii,jj) && vis[yy][xx]==-1 && arr[ii][jj]==bn[k]) {
				vis[yy][xx]=g;
				que.push(pii(yy,xx));
			}
		}
	}
}
lli LU_Det(matrix a) {
	int n=a.n;
	lli res=1;
	matrix U=a,L(n);

	for(int i=0;i<n;i++) {
		for(int k=i;k<n;k++) if(U.a[k][i]!=0) {
			if(k!=i) {
				swap(U.a[i],U.a[k]);
				res=res*(mod-1)%mod;
			}
			break;
		}

		lli val=inv(U.a[i][i]);
		L.a[i][i]=U.a[i][i];
		res = res * U.a[i][i] % mod;
		for(int j=0;j<n;j++) U.a[i][j] = (U.a[i][j]*val)%mod;
		
		for(int k=i+1;k<n;k++) {
			lli val = -U.a[k][i];
			L.a[k][i] = -val;
			for(int j=0;j<n;j++) {
				U.a[k][j] = (U.a[k][j] + U.a[i][j]*val)%mod;
				if(U.a[k][j] < 0) U.a[k][j]+=mod;
			}
		}
	}

	return res%mod;
}
lli solve(int s) {
	int t=s;
	g=0;
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<=n;i++,t^=1) {
		for(int j=t;j<=m;j+=2) if(vis[i][j]==-1) bfs(i,j),g++;
	}
	
	matrix a(g);
	t=s;
	for(int i=0;i<=n;i++,t^=1) {
		for(int j=t;j<=m;j+=2) {
			for(int k=0;k<4;k++) {
				int yy=i+dy[k],xx=j+dx[k];
				int ii=i+cy[k],jj=j+cx[k];
				if( go(yy,xx,ii,jj) && arr[ii][jj]==-1 && vis[i][j]!=vis[yy][xx]) {
					a.a[vis[i][j]][vis[yy][xx]]--;
				}
			}
		}
	}
	
	for(int i=0;i<g;i++) {
		for(int j=0;j<g;j++) if(i!=j) {
			a.a[i][i] -= a.a[i][j];
		}
		for(int j=0;j<g;j++) a.a[i][j] = (a.a[i][j] + mod)%mod;
	}

	matrix b(g-1);
	for(int i=0;i<g-1;i++) for(int j=0;j<g-1;j++) b.a[i][j]=a.a[i][j];

	lli ans = (LU_Det(b)%mod + mod)%mod;
	return ans;
}
int main() {
	scanf("%d%d%lld",&n,&m,&mod);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		if(str[i][j]=='/') arr[i][j]=0;
		else if(str[i][j]=='*') arr[i][j]=-1;
		else arr[i][j]=1;
	}
	
	printf("%lld\n", (solve(0) + solve(1))%mod);

	return 0;
}