#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> s1[N], s2[N];
int a[N][N], b[N], nc[N], nr[N], ranki[N][N], rankj[N][N];
int m,n;

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)scanf("%d",a[i]+j);
	rep(i,1,n){
		memcpy(b,a[i],sizeof b);
		sort(b+1,b+m+1);
		int n1 = unique(b+1,b+m+1)-b-1;
		rep(j,1,m) ranki[i][j] = lower_bound(b+1,b+n1+1,a[i][j]) - b;
		nr[i] = n1;
		//printf("row:%d %d\n",i,nr[i]);
	}
	rep(j,1,m){
		rep(i,1,n)b[i]=a[i][j];
		sort(b+1,b+n+1);
		int n1 = unique(b+1,b+n+1)-b-1;
		rep(i,1,n) rankj[i][j] = lower_bound(b+1,b+n1+1,a[i][j]) - b; 
		nc[j] = n1;
		//printf("column:%d %d\n",j,nc[j]);
	}
	//rep(i,1,n){rep(j,1,m)cout<<rankj[i][j]<<" ";cout<<endl;}
	rep(i,1,n)rep(j,1,m){
		int ans = max(ranki[i][j], rankj[i][j]);
		ans += max(nr[i]-ranki[i][j], nc[j]-rankj[i][j]);
		printf("%d%c",ans,j==m?'\n':' ');
	}
	return 0;
}