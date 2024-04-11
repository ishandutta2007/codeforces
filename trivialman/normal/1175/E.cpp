#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 5e5+10;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r[N][20];
int n,m,x,y;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		r[x][0] = max(r[x][0], y);
	}
	rep(i,1,5e5) r[i][0] = max(r[i][0], r[i-1][0]);
	rep(i,1,19){
		rep(j,0,5e5) r[j][i] = r[r[j][i-1]][i-1];
	}
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		int ans = 0, j = 0;
		for(j=19;j>=0;--j)if(r[x][j]<y){
			x = r[x][j];
			ans += (1<<j);
		}
		printf("%d\n",ans > n ? -1 : ans+1);
	}
	return 0;
}