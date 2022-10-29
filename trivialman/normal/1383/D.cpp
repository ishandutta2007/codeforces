#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 260;
const double PI = acos(-1);
mt19937 rng(time(0));

int n, m, k=0, a[N][N], b[N][N];
int r[N], c[N], same[N];

int global_idx = 1;
bool used[N*N];

int next_num(){
	while(used[global_idx]) global_idx++;
	used[global_idx] = true;
	return global_idx;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m){
		scanf("%d",&a[i][j]);
		r[i] = max(r[i], a[i][j]);
		c[j] = max(c[j], a[i][j]);
	}
	
	sort(r+1, r+n+1);
	sort(c+1, c+m+1);
	r[0] = c[0] = 0;
	
	//rep(i,1,n) cout<<r[i]<<" ";cout<<endl;
	//rep(i,1,m) cout<<c[i]<<" ";cout<<endl<<endl;
	
	rep(i,1,n) rep(j,1,m) if(r[i]==c[j]){
		b[i][j] = r[i];
		same[++k] = r[i];
	}
	
	int ri = n, ci = m;
	rrep(i,k,1){
		int x = ri, y = ci;
		while(r[ri]>same[i-1]) b[ri][y] = r[ri], ri--;
		while(c[ci]>same[i-1]) b[x][ci] = c[ci], ci--;
	}
	
	/*rep(i,1,n){
		rep(j,1,m)
			printf("%d ",b[i][j]);
		printf("\n");
	}cout<<endl;*/
	
	memset(used, false, sizeof used);
	rep(i,1,n) used[r[i]] = true;
	rep(j,1,m) used[c[j]] = true;
	ri = ci = 1;
	
	while(ri<=n && ci<=m){
		if(r[ri]<=c[ci]){
			for(int j = 1; b[ri][j] != r[ri]; j++)
				if (!b[ri][j]) b[ri][j] = next_num();
			for(int j = m; b[ri][j] != r[ri]; j--)
				if (!b[ri][j]) b[ri][j] = next_num();
			ri++;
		}else{
			for(int i = 1; b[i][ci] != c[ci]; i++)
				if (!b[i][ci]) b[i][ci] = next_num();
			for(int i = n; b[i][ci] != c[ci]; i--)
				if (!b[i][ci]) b[i][ci] = next_num();
			ci++;
		}
	}
	
	rep(i,1,n){
		rep(j,1,m)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	
	return 0;
}