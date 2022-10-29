#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,q,x,y;
int a[N],b[N],nxt[N],r[20][N],occ[N],ansr[N];
bool v[N];
char ans[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,2,n) nxt[a[i-1]] = a[i];
	nxt[a[n]] = a[1];
	
	rep(i,1,m) scanf("%d",b+i);
	rrep(i,m,1){
		if(occ[nxt[b[i]]]) r[0][i] = occ[nxt[b[i]]];
		occ[b[i]] = i;
	}
	rep(i,1,m+1){
		if(!r[0][i]) r[0][i] = m+1;
		ansr[i] = m+1;
		//cout<<i<<" "<<r[0][i]<<endl;
	}
	
	rep(i,1,19) rep(j,1,m+1) r[i][j] = r[i-1][r[i-1][j]];
	rep(i,1,m){
		ansr[i] = i;
		int x = n-1;
		for(;x;x-=x&-x) ansr[i] = r[__builtin_ctz(x)][ansr[i]];
		//cout<<i<<" "<<r[0][i]<<" "<<ansr[i]<<endl;
	}
	
	rrep(i,m,1) ansr[i] = min(ansr[i], ansr[i+1]);
	
	rep(i,1,q){
		scanf("%d%d",&x,&y);
		ans[i] = ansr[x]<=y ? '1' : '0';
	}
	printf("%s\n",ans+1);
	return 0;
}