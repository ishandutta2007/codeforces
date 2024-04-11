#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int P = 998244353;
const int N = 1.1e5, M = 320;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,q,x,z,S;
int b[N],l1[N],l2[N],dp[N];
int s[M][M],mi[M],sum[M];

inline void add(int &x, int y){ x = x+y>=P ? x+y-P : x+y; }
void upd(int x,int val){
	int y = x / q;
	b[x] = val;
	if(y==z) return;
	sum[y] = mi[y] = 0;
	rrep(i,y*q+q-1,y*q) mi[y]=min(mi[y],sum[y]), sum[y]+=b[i];
	sum[y] = 0;
	rep(i,0,q) s[y][i] = 0;
	rrep(i,y*q+q-1,y*q){
		add(s[y][sum[y]-mi[y]],dp[i]);
		sum[y] += b[i];
	}
	rep(i,1,q) add(s[y][i], s[y][i-1]);
}
inline int get(int y,int up){ return up>=mi[y] ? s[y][min(q, up-mi[y])] : 0; }

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&k);
	q = sqrt(n)+1, dp[0] = 1;
	upd(0,0);
	rep(i,1,n){
		scanf("%d",&x);
		if(l2[x]) upd(l2[x],0);
		if(l1[x]) upd(l1[x],-1);
		
		z = i/q*q, S = 1;
		rrep(j,i-1,z){
			if(S<=k) add(dp[i],dp[j]);
			S += b[j];
		}
		for(z=z/q-1;~z;--z) add(dp[i], get(z, k-S)), S += sum[z];
		
		upd(i,1);
		if(l1[x]) l2[x] = l1[x];
		l1[x] = i;
	}
	printf("%d\n",dp[n]);
	return 0;
}