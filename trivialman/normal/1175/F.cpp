#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 3e5+5;
const LL INF = 1e16;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,ans,a[N],ma[19][N],lg[N],nxt[N],r[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,2,n) lg[i] = lg[i>>1] + 1;
	rep(i,1,n){
		scanf("%d",a+i);
		ma[0][i] = a[i];
		nxt[i] = n+1;
	}
	rep(j,0,17)rep(i,1,n+1-(1<<j+1)){
		ma[j+1][i] = max(ma[j][i], ma[j][i+(1<<j)]);
	}
	r[n+1] = n+1;
	rrep(i,n,1){
		r[i] = min(r[i+1], nxt[a[i]]);
		nxt[a[i]] = i;
	}
	rep(i,1,n){
		int j = i, x, y;
		for(; j<r[i]; j=max(j+1,i+y-1)){
			x = lg[j-i+1];
			y = max(ma[x][i], ma[x][j-(1<<x)+1]);
			if(i+y-1==j) ++ans;
		}
	}
	printf("%d",ans);
	return 0;
}